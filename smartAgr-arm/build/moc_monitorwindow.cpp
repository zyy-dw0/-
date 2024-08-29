/****************************************************************************
** Meta object code from reading C++ file 'monitorwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../monitorwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonitorWindow_t {
    QByteArrayData data[15];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonitorWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonitorWindow_t qt_meta_stringdata_MonitorWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MonitorWindow"
QT_MOC_LITERAL(1, 14, 16), // "sigControlDevice"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "aid"
QT_MOC_LITERAL(4, 36, 7), // "DevType"
QT_MOC_LITERAL(5, 44, 8), // "dev_type"
QT_MOC_LITERAL(6, 53, 8), // "DataType"
QT_MOC_LITERAL(7, 62, 9), // "data_type"
QT_MOC_LITERAL(8, 72, 6), // "status"
QT_MOC_LITERAL(9, 79, 17), // "onTimingClearData"
QT_MOC_LITERAL(10, 97, 21), // "on_btn_return_clicked"
QT_MOC_LITERAL(11, 119, 19), // "on_btn_down_clicked"
QT_MOC_LITERAL(12, 139, 17), // "on_btn_up_clicked"
QT_MOC_LITERAL(13, 157, 19), // "on_btn_grid_clicked"
QT_MOC_LITERAL(14, 177, 19) // "on_btn_list_clicked"

    },
    "MonitorWindow\0sigControlDevice\0\0aid\0"
    "DevType\0dev_type\0DataType\0data_type\0"
    "status\0onTimingClearData\0on_btn_return_clicked\0"
    "on_btn_down_clicked\0on_btn_up_clicked\0"
    "on_btn_grid_clicked\0on_btn_list_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonitorWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   58,    2, 0x08 /* Private */,
      10,    0,   59,    2, 0x08 /* Private */,
      11,    0,   60,    2, 0x08 /* Private */,
      12,    0,   61,    2, 0x08 /* Private */,
      13,    0,   62,    2, 0x08 /* Private */,
      14,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 6, QMetaType::Int,    3,    5,    7,    8,

 // slots: parameters
    QMetaType::Void,
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
        MonitorWindow *_t = static_cast<MonitorWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigControlDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< DevType(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->onTimingClearData(); break;
        case 2: _t->on_btn_return_clicked(); break;
        case 3: _t->on_btn_down_clicked(); break;
        case 4: _t->on_btn_up_clicked(); break;
        case 5: _t->on_btn_grid_clicked(); break;
        case 6: _t->on_btn_list_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MonitorWindow::*_t)(int , DevType , DataType , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MonitorWindow::sigControlDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MonitorWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MonitorWindow.data,
      qt_meta_data_MonitorWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MonitorWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitorWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitorWindow.stringdata0))
        return static_cast<void*>(const_cast< MonitorWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MonitorWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void MonitorWindow::sigControlDevice(int _t1, DevType _t2, DataType _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
