/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[28];
    char stringdata0[303];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "sigSetAckDialog"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "AckStatus"
QT_MOC_LITERAL(4, 38, 2), // "st"
QT_MOC_LITERAL(5, 41, 10), // "onCloseApp"
QT_MOC_LITERAL(6, 52, 11), // "onConnected"
QT_MOC_LITERAL(7, 64, 7), // "onError"
QT_MOC_LITERAL(8, 72, 12), // "onReadSocket"
QT_MOC_LITERAL(9, 85, 17), // "onDevInfoToServer"
QT_MOC_LITERAL(10, 103, 3), // "zid"
QT_MOC_LITERAL(11, 107, 3), // "aid"
QT_MOC_LITERAL(12, 111, 7), // "onLogin"
QT_MOC_LITERAL(13, 119, 7), // "CmdType"
QT_MOC_LITERAL(14, 127, 8), // "user_cmd"
QT_MOC_LITERAL(15, 136, 8), // "username"
QT_MOC_LITERAL(16, 145, 3), // "pwd"
QT_MOC_LITERAL(17, 149, 10), // "onRegister"
QT_MOC_LITERAL(18, 160, 15), // "onControlDevice"
QT_MOC_LITERAL(19, 176, 7), // "DevType"
QT_MOC_LITERAL(20, 184, 8), // "dev_type"
QT_MOC_LITERAL(21, 193, 8), // "DataType"
QT_MOC_LITERAL(22, 202, 9), // "data_type"
QT_MOC_LITERAL(23, 212, 6), // "status"
QT_MOC_LITERAL(24, 219, 14), // "onSaveSettings"
QT_MOC_LITERAL(25, 234, 22), // "on_btn_monitor_clicked"
QT_MOC_LITERAL(26, 257, 22), // "on_btn_control_clicked"
QT_MOC_LITERAL(27, 280, 22) // "on_btn_setting_clicked"

    },
    "MainWindow\0sigSetAckDialog\0\0AckStatus\0"
    "st\0onCloseApp\0onConnected\0onError\0"
    "onReadSocket\0onDevInfoToServer\0zid\0"
    "aid\0onLogin\0CmdType\0user_cmd\0username\0"
    "pwd\0onRegister\0onControlDevice\0DevType\0"
    "dev_type\0DataType\0data_type\0status\0"
    "onSaveSettings\0on_btn_monitor_clicked\0"
    "on_btn_control_clicked\0on_btn_setting_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    2,   86,    2, 0x08 /* Private */,
      12,    3,   91,    2, 0x08 /* Private */,
      17,    3,   98,    2, 0x08 /* Private */,
      18,    4,  105,    2, 0x08 /* Private */,
      24,    0,  114,    2, 0x08 /* Private */,
      25,    0,  115,    2, 0x08 /* Private */,
      26,    0,  116,    2, 0x08 /* Private */,
      27,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, 0x80000000 | 13, QMetaType::QString, QMetaType::QString,   14,   15,   16,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19, 0x80000000 | 21, QMetaType::Int,   11,   20,   22,   23,
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
        case 0: _t->sigSetAckDialog((*reinterpret_cast< AckStatus(*)>(_a[1]))); break;
        case 1: _t->onCloseApp(); break;
        case 2: _t->onConnected(); break;
        case 3: _t->onError(); break;
        case 4: _t->onReadSocket(); break;
        case 5: _t->onDevInfoToServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->onLogin((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: _t->onRegister((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 8: _t->onControlDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< DevType(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 9: _t->onSaveSettings(); break;
        case 10: _t->on_btn_monitor_clicked(); break;
        case 11: _t->on_btn_control_clicked(); break;
        case 12: _t->on_btn_setting_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(AckStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigSetAckDialog)) {
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigSetAckDialog(AckStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
