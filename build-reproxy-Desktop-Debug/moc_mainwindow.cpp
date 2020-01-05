/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../reproxy/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[33];
    char stringdata0[414];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 14), // "sigReadyToSend"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 2), // "sz"
QT_MOC_LITERAL(4, 30, 16), // "setStatusMessage"
QT_MOC_LITERAL(5, 47, 3), // "msg"
QT_MOC_LITERAL(6, 51, 14), // "statConnecting"
QT_MOC_LITERAL(7, 66, 14), // "statRConnected"
QT_MOC_LITERAL(8, 81, 14), // "statLConnected"
QT_MOC_LITERAL(9, 96, 16), // "statDisconnected"
QT_MOC_LITERAL(10, 113, 15), // "statCantConnect"
QT_MOC_LITERAL(11, 129, 6), // "errmsg"
QT_MOC_LITERAL(12, 136, 14), // "onEndpointData"
QT_MOC_LITERAL(13, 151, 5), // "char*"
QT_MOC_LITERAL(14, 157, 4), // "buff"
QT_MOC_LITERAL(15, 162, 12), // "onClientData"
QT_MOC_LITERAL(16, 175, 13), // "on_hexChanged"
QT_MOC_LITERAL(17, 189, 3), // "row"
QT_MOC_LITERAL(18, 193, 3), // "col"
QT_MOC_LITERAL(19, 197, 19), // "on_bConnect_clicked"
QT_MOC_LITERAL(20, 217, 16), // "on_bSend_clicked"
QT_MOC_LITERAL(21, 234, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(22, 258, 10), // "on_saveHex"
QT_MOC_LITERAL(23, 269, 10), // "on_saveBin"
QT_MOC_LITERAL(24, 280, 10), // "on_loadHex"
QT_MOC_LITERAL(25, 291, 10), // "on_loadBin"
QT_MOC_LITERAL(26, 302, 10), // "on_saveAll"
QT_MOC_LITERAL(27, 313, 8), // "on_about"
QT_MOC_LITERAL(28, 322, 9), // "on_radare"
QT_MOC_LITERAL(29, 332, 9), // "on_script"
QT_MOC_LITERAL(30, 342, 24), // "on_eSize_editingFinished"
QT_MOC_LITERAL(31, 367, 28), // "on_eMutation_editingFinished"
QT_MOC_LITERAL(32, 396, 17) // "on_help_scripting"

    },
    "MainWindow\0sigReadyToSend\0\0sz\0"
    "setStatusMessage\0msg\0statConnecting\0"
    "statRConnected\0statLConnected\0"
    "statDisconnected\0statCantConnect\0"
    "errmsg\0onEndpointData\0char*\0buff\0"
    "onClientData\0on_hexChanged\0row\0col\0"
    "on_bConnect_clicked\0on_bSend_clicked\0"
    "on_actionQuit_triggered\0on_saveHex\0"
    "on_saveBin\0on_loadHex\0on_loadBin\0"
    "on_saveAll\0on_about\0on_radare\0on_script\0"
    "on_eSize_editingFinished\0"
    "on_eMutation_editingFinished\0"
    "on_help_scripting"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,  137,    2, 0x0a /* Public */,
       6,    0,  140,    2, 0x0a /* Public */,
       7,    0,  141,    2, 0x0a /* Public */,
       8,    0,  142,    2, 0x0a /* Public */,
       9,    0,  143,    2, 0x0a /* Public */,
      10,    1,  144,    2, 0x0a /* Public */,
      12,    2,  147,    2, 0x0a /* Public */,
      15,    2,  152,    2, 0x0a /* Public */,
      16,    2,  157,    2, 0x0a /* Public */,
      19,    0,  162,    2, 0x08 /* Private */,
      20,    0,  163,    2, 0x08 /* Private */,
      21,    0,  164,    2, 0x08 /* Private */,
      22,    0,  165,    2, 0x08 /* Private */,
      23,    0,  166,    2, 0x08 /* Private */,
      24,    0,  167,    2, 0x08 /* Private */,
      25,    0,  168,    2, 0x08 /* Private */,
      26,    0,  169,    2, 0x08 /* Private */,
      27,    0,  170,    2, 0x08 /* Private */,
      28,    0,  171,    2, 0x08 /* Private */,
      29,    0,  172,    2, 0x08 /* Private */,
      30,    0,  173,    2, 0x08 /* Private */,
      31,    0,  174,    2, 0x08 /* Private */,
      32,    0,  175,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,    3,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
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
        case 17: _t->on_saveAll(); break;
        case 18: _t->on_about(); break;
        case 19: _t->on_radare(); break;
        case 20: _t->on_script(); break;
        case 21: _t->on_eSize_editingFinished(); break;
        case 22: _t->on_eMutation_editingFinished(); break;
        case 23: _t->on_help_scripting(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigReadyToSend)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigReadyToSend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
