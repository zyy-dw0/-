/****************************************************************************
** Meta object code from reading C++ file 'logindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginDialog_t {
    QByteArrayData data[19];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginDialog_t qt_meta_stringdata_LoginDialog = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginDialog"
QT_MOC_LITERAL(1, 12, 8), // "sigLogin"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 7), // "CmdType"
QT_MOC_LITERAL(4, 30, 8), // "cmd_type"
QT_MOC_LITERAL(5, 39, 8), // "username"
QT_MOC_LITERAL(6, 48, 3), // "pwd"
QT_MOC_LITERAL(7, 52, 6), // "online"
QT_MOC_LITERAL(8, 59, 11), // "sigRegister"
QT_MOC_LITERAL(9, 71, 21), // "on_btn_cancle_clicked"
QT_MOC_LITERAL(10, 93, 20), // "on_btn_login_clicked"
QT_MOC_LITERAL(11, 114, 22), // "on_btn_tologin_clicked"
QT_MOC_LITERAL(12, 137, 25), // "on_btn_toregister_clicked"
QT_MOC_LITERAL(13, 163, 23), // "on_btn_register_clicked"
QT_MOC_LITERAL(14, 187, 22), // "on_btn_rcancle_clicked"
QT_MOC_LITERAL(15, 210, 22), // "on_btn_scancle_clicked"
QT_MOC_LITERAL(16, 233, 22), // "on_btn_sreturn_clicked"
QT_MOC_LITERAL(17, 256, 26), // "on_btn_save_server_clicked"
QT_MOC_LITERAL(18, 283, 27) // "on_btn_to_setserver_clicked"

    },
    "LoginDialog\0sigLogin\0\0CmdType\0cmd_type\0"
    "username\0pwd\0online\0sigRegister\0"
    "on_btn_cancle_clicked\0on_btn_login_clicked\0"
    "on_btn_tologin_clicked\0on_btn_toregister_clicked\0"
    "on_btn_register_clicked\0on_btn_rcancle_clicked\0"
    "on_btn_scancle_clicked\0on_btn_sreturn_clicked\0"
    "on_btn_save_server_clicked\0"
    "on_btn_to_setserver_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   74,    2, 0x06 /* Public */,
       8,    3,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   90,    2, 0x08 /* Private */,
      10,    0,   91,    2, 0x08 /* Private */,
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,

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
    QMetaType::Void,

       0        // eod
};

void LoginDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoginDialog *_t = static_cast<LoginDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLogin((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->sigRegister((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->on_btn_cancle_clicked(); break;
        case 3: _t->on_btn_login_clicked(); break;
        case 4: _t->on_btn_tologin_clicked(); break;
        case 5: _t->on_btn_toregister_clicked(); break;
        case 6: _t->on_btn_register_clicked(); break;
        case 7: _t->on_btn_rcancle_clicked(); break;
        case 8: _t->on_btn_scancle_clicked(); break;
        case 9: _t->on_btn_sreturn_clicked(); break;
        case 10: _t->on_btn_save_server_clicked(); break;
        case 11: _t->on_btn_to_setserver_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoginDialog::*_t)(CmdType , QString , QString , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginDialog::sigLogin)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (LoginDialog::*_t)(CmdType , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoginDialog::sigRegister)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LoginDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_LoginDialog.data,
      qt_meta_data_LoginDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginDialog.stringdata0))
        return static_cast<void*>(const_cast< LoginDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int LoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LoginDialog::sigLogin(CmdType _t1, QString _t2, QString _t3, bool _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginDialog::sigRegister(CmdType _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
