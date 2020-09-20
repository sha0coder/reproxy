/****************************************************************************
** Meta object code from reading C++ file 'proxy.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../reproxy/proxy.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Proxy[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    7,    6,    6, 0x05,
      30,    6,    6,    6, 0x05,
      48,    6,    6,    6, 0x05,
      64,    6,    6,    6, 0x05,
      87,   80,    6,    6, 0x05,
     111,    6,    6,    6, 0x05,
     135,  127,    6,    6, 0x05,
     162,  127,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
     187,    6,    6,    6, 0x0a,
     208,    6,    6,    6, 0x0a,
     233,    6,    6,    6, 0x0a,
     250,    6,    6,    6, 0x0a,
     276,    6,    6,    6, 0x0a,
     294,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Proxy[] = {
    "Proxy\0\0msg\0setStatus(QString)\0"
    "sigDisconnected()\0sigRConnected()\0"
    "sigLConnected()\0errmsg\0sigCantConnect(QString)\0"
    "sigConnecting()\0buff,sz\0"
    "sigEndpiontData(char*,int)\0"
    "sigClientData(char*,int)\0onNewTcpConnection()\0"
    "onTcpLocalDisconnected()\0onReadTcpLocal()\0"
    "onTcpRemoteDisconnected()\0onReadTcpRemote()\0"
    "onReadyToSend(int)\0"
};

void Proxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Proxy *_t = static_cast<Proxy *>(_o);
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
    }
}

const QMetaObjectExtraData Proxy::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Proxy::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Proxy,
      qt_meta_data_Proxy, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Proxy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Proxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Proxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Proxy))
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
    }
    return _id;
}

// SIGNAL 0
void Proxy::setStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Proxy::sigDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Proxy::sigRConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Proxy::sigLConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Proxy::sigCantConnect(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Proxy::sigConnecting()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Proxy::sigEndpiontData(char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Proxy::sigClientData(char * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
