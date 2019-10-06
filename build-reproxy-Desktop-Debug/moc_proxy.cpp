/****************************************************************************
** Meta object code from reading C++ file 'proxy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../reproxy/proxy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Proxy_t {
    QByteArrayData data[21];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Proxy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Proxy_t qt_meta_stringdata_Proxy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Proxy"
QT_MOC_LITERAL(1, 6, 9), // "setStatus"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 3), // "msg"
QT_MOC_LITERAL(4, 21, 15), // "sigDisconnected"
QT_MOC_LITERAL(5, 37, 13), // "sigRConnected"
QT_MOC_LITERAL(6, 51, 13), // "sigLConnected"
QT_MOC_LITERAL(7, 65, 14), // "sigCantConnect"
QT_MOC_LITERAL(8, 80, 6), // "errmsg"
QT_MOC_LITERAL(9, 87, 13), // "sigConnecting"
QT_MOC_LITERAL(10, 101, 15), // "sigEndpiontData"
QT_MOC_LITERAL(11, 117, 5), // "char*"
QT_MOC_LITERAL(12, 123, 4), // "buff"
QT_MOC_LITERAL(13, 128, 2), // "sz"
QT_MOC_LITERAL(14, 131, 13), // "sigClientData"
QT_MOC_LITERAL(15, 145, 18), // "onNewTcpConnection"
QT_MOC_LITERAL(16, 164, 22), // "onTcpLocalDisconnected"
QT_MOC_LITERAL(17, 187, 14), // "onReadTcpLocal"
QT_MOC_LITERAL(18, 202, 23), // "onTcpRemoteDisconnected"
QT_MOC_LITERAL(19, 226, 15), // "onReadTcpRemote"
QT_MOC_LITERAL(20, 242, 13) // "onReadyToSend"

    },
    "Proxy\0setStatus\0\0msg\0sigDisconnected\0"
    "sigRConnected\0sigLConnected\0sigCantConnect\0"
    "errmsg\0sigConnecting\0sigEndpiontData\0"
    "char*\0buff\0sz\0sigClientData\0"
    "onNewTcpConnection\0onTcpLocalDisconnected\0"
    "onReadTcpLocal\0onTcpRemoteDisconnected\0"
    "onReadTcpRemote\0onReadyToSend"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Proxy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,
       9,    0,   93,    2, 0x06 /* Public */,
      10,    2,   94,    2, 0x06 /* Public */,
      14,    2,   99,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  104,    2, 0x0a /* Public */,
      16,    0,  105,    2, 0x0a /* Public */,
      17,    0,  106,    2, 0x0a /* Public */,
      18,    0,  107,    2, 0x0a /* Public */,
      19,    0,  108,    2, 0x0a /* Public */,
      20,    1,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,
    QMetaType::Void, 0x80000000 | 11, QMetaType::Int,   12,   13,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Proxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Proxy *_t = static_cast<Proxy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigDisconnected(); break;
        case 2: _t->sigRConnected(); break;
        case 3: _t->sigLConnected(); break;
        case 4: _t->sigCantConnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigConnecting(); break;
        case 6: _t->sigEndpiontData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->sigClientData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onNewTcpConnection(); break;
        case 9: _t->onTcpLocalDisconnected(); break;
        case 10: _t->onReadTcpLocal(); break;
        case 11: _t->onTcpRemoteDisconnected(); break;
        case 12: _t->onReadTcpRemote(); break;
        case 13: _t->onReadyToSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Proxy::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::setStatus)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigDisconnected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigRConnected)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigLConnected)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigCantConnect)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigConnecting)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigEndpiontData)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Proxy::*_t)(char * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Proxy::sigClientData)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject Proxy::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Proxy.data,
      qt_meta_data_Proxy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Proxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Proxy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Proxy.stringdata0))
        return static_cast<void*>(const_cast< Proxy*>(this));
    return QThread::qt_metacast(_clname);
}

int Proxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Proxy::setStatus(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Proxy::sigDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Proxy::sigRConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Proxy::sigLConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Proxy::sigCantConnect(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Proxy::sigConnecting()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Proxy::sigEndpiontData(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Proxy::sigClientData(char * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
