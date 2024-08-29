/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "onConnected"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 7), // "onError"
QT_MOC_LITERAL(4, 32, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(5, 61, 3), // "err"
QT_MOC_LITERAL(6, 65, 12), // "onReadSocket"
QT_MOC_LITERAL(7, 78, 12), // "onReadSerial"
QT_MOC_LITERAL(8, 91, 15), // "onControlDevice"
QT_MOC_LITERAL(9, 107, 3), // "zid"
QT_MOC_LITERAL(10, 111, 7), // "DevType"
QT_MOC_LITERAL(11, 119, 8), // "dev_type"
QT_MOC_LITERAL(12, 128, 8), // "DataType"
QT_MOC_LITERAL(13, 137, 9), // "data_type"
QT_MOC_LITERAL(14, 147, 6), // "status"
QT_MOC_LITERAL(15, 154, 7), // "onLogin"
QT_MOC_LITERAL(16, 162, 7), // "CmdType"
QT_MOC_LITERAL(17, 170, 8), // "user_cmd"
QT_MOC_LITERAL(18, 179, 8), // "username"
QT_MOC_LITERAL(19, 188, 3), // "pwd"
QT_MOC_LITERAL(20, 192, 6), // "online"
QT_MOC_LITERAL(21, 199, 10), // "onRegister"
QT_MOC_LITERAL(22, 210, 14), // "onSaveSettings"
QT_MOC_LITERAL(23, 225, 22), // "on_btn_monitor_clicked"
QT_MOC_LITERAL(24, 248, 22), // "on_btn_control_clicked"
QT_MOC_LITERAL(25, 271, 22) // "on_btn_setting_clicked"

    },
    "MainWindow\0onConnected\0\0onError\0"
    "QAbstractSocket::SocketError\0err\0"
    "onReadSocket\0onReadSerial\0onControlDevice\0"
    "zid\0DevType\0dev_type\0DataType\0data_type\0"
    "status\0onLogin\0CmdType\0user_cmd\0"
    "username\0pwd\0online\0onRegister\0"
    "onSaveSettings\0on_btn_monitor_clicked\0"
    "on_btn_control_clicked\0on_btn_setting_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    1,   70,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    4,   75,    2, 0x08 /* Private */,
      15,    4,   84,    2, 0x08 /* Private */,
      21,    3,   93,    2, 0x08 /* Private */,
      22,    0,  100,    2, 0x08 /* Private */,
      23,    0,  101,    2, 0x08 /* Private */,
      24,    0,  102,    2, 0x08 /* Private */,
      25,    0,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 10, 0x80000000 | 12, QMetaType::Int,    9,   11,   13,   14,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::QString, QMetaType::Bool,   17,   18,   19,   20,
    QMetaType::Void, 0x80000000 | 16, QMetaType::QString, QMetaType::QString,   17,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onConnected(); break;
        case 1: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->onReadSocket(); break;
        case 3: _t->onReadSerial(); break;
        case 4: _t->onControlDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< DevType(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 5: _t->onLogin((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 6: _t->onRegister((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->onSaveSettings(); break;
        case 8: _t->on_btn_monitor_clicked(); break;
        case 9: _t->on_btn_control_clicked(); break;
        case 10: _t->on_btn_setting_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
