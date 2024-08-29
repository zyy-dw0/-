/****************************************************************************
** Meta object code from reading C++ file 'monitorarea.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../monitorarea.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monitorarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonitorArea_t {
    QByteArrayData data[18];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MonitorArea_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MonitorArea_t qt_meta_stringdata_MonitorArea = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MonitorArea"
QT_MOC_LITERAL(1, 12, 16), // "sigControlDevice"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "zid"
QT_MOC_LITERAL(4, 34, 7), // "DevType"
QT_MOC_LITERAL(5, 42, 8), // "dev_type"
QT_MOC_LITERAL(6, 51, 8), // "DataType"
QT_MOC_LITERAL(7, 60, 9), // "data_type"
QT_MOC_LITERAL(8, 70, 6), // "status"
QT_MOC_LITERAL(9, 77, 18), // "on_btn_aid_clicked"
QT_MOC_LITERAL(10, 96, 20), // "on_btn_aid_2_clicked"
QT_MOC_LITERAL(11, 117, 22), // "on_switch_lamp_clicked"
QT_MOC_LITERAL(12, 140, 22), // "on_switch_humi_clicked"
QT_MOC_LITERAL(13, 163, 21), // "on_switch_fan_clicked"
QT_MOC_LITERAL(14, 185, 25), // "on_btn_to_control_clicked"
QT_MOC_LITERAL(15, 211, 25), // "on_btn_to_monitor_clicked"
QT_MOC_LITERAL(16, 237, 34), // "on_switch_curtain_positive_cl..."
QT_MOC_LITERAL(17, 272, 33) // "on_switch_curtain_reverse_cli..."

    },
    "MonitorArea\0sigControlDevice\0\0zid\0"
    "DevType\0dev_type\0DataType\0data_type\0"
    "status\0on_btn_aid_clicked\0"
    "on_btn_aid_2_clicked\0on_switch_lamp_clicked\0"
    "on_switch_humi_clicked\0on_switch_fan_clicked\0"
    "on_btn_to_control_clicked\0"
    "on_btn_to_monitor_clicked\0"
    "on_switch_curtain_positive_clicked\0"
    "on_switch_curtain_reverse_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonitorArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   73,    2, 0x08 /* Private */,
      10,    0,   74,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,
      12,    0,   76,    2, 0x08 /* Private */,
      13,    0,   77,    2, 0x08 /* Private */,
      14,    0,   78,    2, 0x08 /* Private */,
      15,    0,   79,    2, 0x08 /* Private */,
      16,    0,   80,    2, 0x08 /* Private */,
      17,    0,   81,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4, 0x80000000 | 6, QMetaType::Int,    3,    5,    7,    8,

 // slots: parameters
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

void MonitorArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MonitorArea *_t = static_cast<MonitorArea *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigControlDevice((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< DevType(*)>(_a[2])),(*reinterpret_cast< DataType(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->on_btn_aid_clicked(); break;
        case 2: _t->on_btn_aid_2_clicked(); break;
        case 3: _t->on_switch_lamp_clicked(); break;
        case 4: _t->on_switch_humi_clicked(); break;
        case 5: _t->on_switch_fan_clicked(); break;
        case 6: _t->on_btn_to_control_clicked(); break;
        case 7: _t->on_btn_to_monitor_clicked(); break;
        case 8: _t->on_switch_curtain_positive_clicked(); break;
        case 9: _t->on_switch_curtain_reverse_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MonitorArea::*_t)(int , DevType , DataType , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MonitorArea::sigControlDevice)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MonitorArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MonitorArea.data,
      qt_meta_data_MonitorArea,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MonitorArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonitorArea::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonitorArea.stringdata0))
        return static_cast<void*>(const_cast< MonitorArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int MonitorArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MonitorArea::sigControlDevice(int _t1, DevType _t2, DataType _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
