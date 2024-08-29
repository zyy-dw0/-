/****************************************************************************
** Meta object code from reading C++ file 'monitorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../monitorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonitorWindow_t {
    QByteArrayData data[21];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonitorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonitorWindow_t qt_meta_stringdata_MonitorWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MonitorWindow"
QT_MOC_LITERAL(1, 14, 18), // "sigDevInfoToServer"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 3), // "zid"
QT_MOC_LITERAL(4, 38, 3), // "aid"
QT_MOC_LITERAL(5, 42, 14), // "sigShowMainWnd"
QT_MOC_LITERAL(6, 57, 16), // "sigControlDevice"
QT_MOC_LITERAL(7, 74, 7), // "DevType"
QT_MOC_LITERAL(8, 82, 8), // "dev_type"
QT_MOC_LITERAL(9, 91, 8), // "DataType"
QT_MOC_LITERAL(10, 100, 9), // "data_type"
QT_MOC_LITERAL(11, 110, 6), // "status"
QT_MOC_LITERAL(12, 117, 17), // "onTimingClearData"
QT_MOC_LITERAL(13, 135, 9), // "onSetNode"
QT_MOC_LITERAL(14, 145, 13), // "onSetAreaZids"
QT_MOC_LITERAL(15, 159, 4), // "zids"
QT_MOC_LITERAL(16, 164, 21), // "on_btn_return_clicked"
QT_MOC_LITERAL(17, 186, 19), // "on_btn_down_clicked"
QT_MOC_LITERAL(18, 206, 17), // "on_btn_up_clicked"
QT_MOC_LITERAL(19, 224, 19), // "on_btn_grid_clicked"
QT_MOC_LITERAL(20, 244, 19) // "on_btn_list_clicked"

    },
    "MonitorWindow\0sigDevInfoToServer\0\0zid\0"
    "aid\0sigShowMainWnd\0sigControlDevice\0"
    "DevType\0dev_type\0DataType\0data_type\0"
    "status\0onTimingClearData\0onSetNode\0"
    "onSetAreaZids\0zids\0on_btn_return_clicked\0"
    "on_btn_down_clicked\0on_btn_up_clicked\0"
    "on_btn_grid_clicked\0on_btn_list_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonitorWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    0,   74,    2, 0x06 /* Public */,
       6,    4,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   84,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x08 /* Private */,
      14,    2,   90,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,
      17,    0,   96,    2, 0x08 /* Private */,
      18,    0,   97,    2, 0x08 /* Private */,
      19,    0,   98,    2, 0x08 /* Private */,
      20,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7, 0x80000000 | 9, QMetaType::Int,    4,    8,   10,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    4,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MonitorWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonitorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigDevInfoToServer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->sigShowMainWnd(); break;
        case 2: _t->sigControlDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< DevType(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->onTimingClearData(); break;
        case 4: _t->onSetNode((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->onSetAreaZids((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 6: _t->on_btn_return_clicked(); break;
        case 7: _t->on_btn_down_clicked(); break;
        case 8: _t->on_btn_up_clicked(); break;
        case 9: _t->on_btn_grid_clicked(); break;
        case 10: _t->on_btn_list_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonitorWindow::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorWindow::sigDevInfoToServer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MonitorWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorWindow::sigShowMainWnd)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MonitorWindow::*)(int , DevType , DataType , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonitorWindow::sigControlDevice)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MonitorWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MonitorWindow.data,
    qt_meta_data_MonitorWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MonitorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitorWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MonitorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MonitorWindow::sigDevInfoToServer(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MonitorWindow::sigShowMainWnd()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MonitorWindow::sigControlDevice(int _t1, DevType _t2, DataType _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
