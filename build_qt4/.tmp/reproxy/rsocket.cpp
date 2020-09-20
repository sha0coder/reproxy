#include "rsocket.h"

RSocket::RSocket() {
    RSocket(true, 10);
}

RSocket::RSocket(bool isTcp, int secs) {
    err = "";
    this->isTcp = isTcp;
    this->isTimeout = false;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock<1) {
        setError("can not create a socket.");
        return;
    }

    setTimeout(secs);
    setNonBlocking();
}

bool RSocket::ok() {
    return (err.size() == 0);
}

const char *RSocket::getError() {
    return err.c_str();
}

void RSocket::setError(std::string msg) {
    if (ok())
        err = msg;
}

void RSocket::setNonBlocking() {
    int opt;

    if ((opt = fcntl (sock, F_GETFL, NULL)) < 0) {
        setError("F_GETFL error");
        return;
    }

    if (fcntl (sock, F_SETFL, opt | O_NONBLOCK) < 0) {
        setError("F_SETFL error");
        return;
    }
}

void RSocket::setTimeout(int secs) {
    tv.tv_usec = 0;
    tv.tv_sec = secs;
}

int RSocket::getSock() {
    return sock;
}

bool RSocket::timeout() {
    return isTimeout;
}

RSocket::~RSocket() {
    if (sock>=0) {
        close(sock);
        sock = -1;
     }
}

void RSocket::dial(std::string host, int port) {
    int r;

    struct hostent *h = gethostbyname(host.c_str());
    if (!h) {
        setError("Cannot resolve the remote host!");
        return;
    }

    endpoint.sin_family = AF_INET;
    endpoint.sin_port = htons(port);
    endpoint.sin_addr = *(struct in_addr *)(h->h_addr);

    r = connect(sock, (struct sockaddr *)&endpoint, sizeof(endpoint));
    if (r<0) {
        if (errno == EINPROGRESS) {
            fd_set wait_set;
            FD_ZERO (&wait_set);
            FD_SET (sock, &wait_set);

            r = select(sock + 1, &wait_set, &wait_set, NULL, &tv);
            if (r <= 0) {
                setError("can not connect.");
                return;
            }
        } else {
            setError("can not connect");
            return;
        }
    }

    return;
}

void RSocket::serve(int port, int simultaneousConnections=1) {
    int r;

    endpoint.sin_family = AF_INET;
    endpoint.sin_port = htons((unsigned short)port);
    endpoint.sin_addr.s_addr = htonl(INADDR_ANY);

    r = bind(sock, (struct sockaddr *)&endpoint, sizeof(endpoint));
    if (r<0) {
        setError("Cant bind the port!");
        return;
    }

    r = listen(sock, simultaneousConnections);
    if (r<0) {
        setError("cant listen on that port");
        return;
    }

    cSock = accept(sock, (struct sockaddr *)&client, &clientLen);
    if (cSock < 0) {
        setError("cant accept the incomming connection");
        return;
    }

}

void RSocket::shutdown() {
    if (sock >= 0) {
        close(sock);
        sock = -1;
     }
}

long int RSocket::push(char *data, size_t sz) {
    long int n;
    int s;
    setError("");

    fd_set wait_set;
    FD_ZERO (&wait_set);
    FD_SET (sock, &wait_set);
    s = select(sock + 1, NULL, &wait_set, NULL, &tv);
    if (s < 0) {
        setError("RSocket error");
        return 0;
    }
    if (s == 0) {
        isTimeout = true;
        return 0;
    }

    if (isTcp)
        n = send(sock, data, sz, 0);

    if (n < 0) {
        setError("cant sent data");
        return 0;
    }

    return n;
}


long int RSocket::pop(char *data, size_t sz) {
    long int n;
    int s;
    setError("");
    isTimeout = false;

    fd_set wait_set;
    FD_ZERO (&wait_set);
    FD_SET (sock, &wait_set);
    s = select(sock + 1, &wait_set, NULL,  NULL, &tv);
    if (s < 0) {
        setError("RSocket error");
        return 0;
    }
    if (s == 0) {
        isTimeout = true;
        return 0;
    }

    memset(data, 0, sz);

    if (isTcp)
        n = recv(sock, data, sz, 0);
        perror("recv");
    if (n < 0) {
        setError("cant receive data");
        return 0;
    }

    return n;
}

bool RSocket::isReadyForRead(int timeout_secs) {
    int s;
    struct timeval tv;
    tv.tv_usec = 0;
    tv.tv_sec = timeout_secs;

    fd_set wait_set;
    FD_ZERO (&wait_set);
    FD_SET (sock, &wait_set);
    s = select(sock + 1, &wait_set, NULL,  NULL, &tv);
    if (s < 0) {
        return false; // socket error
    }
    if (s == 0) {
        return false; // timeout
    }

    return true;
}

bool RSocket::isReadyForWrite(int timeout_secs) {
    int s;
    struct timeval tv;
    tv.tv_usec = 0;
    tv.tv_sec = timeout_secs;

    fd_set wait_set;
    FD_ZERO (&wait_set);
    FD_SET (sock, &wait_set);
    s = select(sock + 1, NULL, &wait_set,  NULL, &tv);
    if (s < 0) {
        return false; // socket error
    }
    if (s == 0) {
        return false; // timeout
    }

    return true;
}

char RSocket::wait() {
    int s;
    fd_set read_set, write_set, err_set;
    FD_ZERO(&read_set);
    FD_ZERO(&write_set);
    FD_ZERO(&err_set);
    FD_SET(sock, &read_set);
    FD_SET(sock, &write_set);
    FD_SET(sock, &err_set);
    s = select(sock + 1, &read_set, &write_set, &err_set, NULL);
    if (s < 0)
        return 'e';
    if (s == 0)
        return 't';

    if (FD_ISSET(sock, &read_set))
        return 'r';
    if (FD_ISSET(sock, &write_set))
        return 'w';
    if (FD_ISSET(sock, &err_set))
        return 'E';

    return 'x';
}

