/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../reproxy2/reproxy/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      39,   35,   11,   11, 0x0a,
      65,   11,   11,   11, 0x0a,
      82,   11,   11,   11, 0x0a,
      99,   11,   11,   11, 0x0a,
     116,   11,   11,   11, 0x0a,
     142,  135,   11,   11, 0x0a,
     175,  167,   11,   11, 0x0a,
     201,  167,   11,   11, 0x0a,
     233,  225,   11,   11, 0x0a,
     256,   11,   11,   11, 0x08,
     278,   11,   11,   11, 0x08,
     297,   11,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     336,   11,   11,   11, 0x08,
     349,   11,   11,   11, 0x08,
     362,   11,   11,   11, 0x08,
     375,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0sz\0sigReadyToSend(int)\0"
    "msg\0setStatusMessage(QString)\0"
    "statConnecting()\0statRConnected()\0"
    "statLConnected()\0statDisconnected()\0"
    "errmsg\0statCantConnect(QString)\0buff,sz\0"
    "onEndpointData(char*,int)\0"
    "onClientData(char*,int)\0row,col\0"
    "on_hexChanged(int,int)\0on_bConnect_clicked()\0"
    "on_bSend_clicked()\0on_actionQuit_triggered()\0"
    "on_saveHex()\0on_saveBin()\0on_loadHex()\0"
    "on_loadBin()\0on_about()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->sigReadyToSend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setStatusMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->statConnecting(); break;
        case 3: _t->statRConnected(); break;
        case 4: _t->statLConnected(); break;
        case 5: _t->statDisconnected(); break;
        case 6: _t->statCantConnect((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->onEndpointData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->onClientData((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->on_hexChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->on_bConnect_clicked(); break;
        case 11: _t->on_bSend_clicked(); break;
        case 12: _t->on_actionQuit_triggered(); break;
        case 13: _t->on_saveHex(); break;
        case 14: _t->on_saveBin(); break;
        case 15: _t->on_loadHex(); break;
        case 16: _t->on_loadBin(); break;
        case 17: _t->on_about(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigReadyToSend(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
