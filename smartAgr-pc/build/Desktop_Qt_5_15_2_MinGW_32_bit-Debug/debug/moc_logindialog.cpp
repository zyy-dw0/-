/****************************************************************************
** Meta object code from reading C++ file 'logindialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../logindialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logindialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginDialog_t {
    QByteArrayData data[22];
    char stringdata0[348];
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
QT_MOC_LITERAL(7, 52, 11), // "sigRegister"
QT_MOC_LITERAL(8, 64, 11), // "sigCloseApp"
QT_MOC_LITERAL(9, 76, 14), // "onSetAckDialog"
QT_MOC_LITERAL(10, 91, 9), // "AckStatus"
QT_MOC_LITERAL(11, 101, 6), // "status"
QT_MOC_LITERAL(12, 108, 21), // "on_btn_cancle_clicked"
QT_MOC_LITERAL(13, 130, 20), // "on_btn_login_clicked"
QT_MOC_LITERAL(14, 151, 22), // "on_btn_tologin_clicked"
QT_MOC_LITERAL(15, 174, 25), // "on_btn_toregister_clicked"
QT_MOC_LITERAL(16, 200, 23), // "on_btn_register_clicked"
QT_MOC_LITERAL(17, 224, 22), // "on_btn_rcancle_clicked"
QT_MOC_LITERAL(18, 247, 22), // "on_btn_scancle_clicked"
QT_MOC_LITERAL(19, 270, 22), // "on_btn_sreturn_clicked"
QT_MOC_LITERAL(20, 293, 26), // "on_btn_save_server_clicked"
QT_MOC_LITERAL(21, 320, 27) // "on_btn_to_setserver_clicked"

    },
    "LoginDialog\0sigLogin\0\0CmdType\0cmd_type\0"
    "username\0pwd\0sigRegister\0sigCloseApp\0"
    "onSetAckDialog\0AckStatus\0status\0"
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
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x06 /* Public */,
       7,    3,   91,    2, 0x06 /* Public */,
       8,    0,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   99,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,
      16,    0,  106,    2, 0x08 /* Private */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    0,  109,    2, 0x08 /* Private */,
      20,    0,  110,    2, 0x08 /* Private */,
      21,    0,  111,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
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
        auto *_t = static_cast<LoginDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigLogin((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->sigRegister((*reinterpret_cast< CmdType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->sigCloseApp(); break;
        case 3: _t->onSetAckDialog((*reinterpret_cast< AckStatus(*)>(_a[1]))); break;
        case 4: _t->on_btn_cancle_clicked(); break;
        case 5: _t->on_btn_login_clicked(); break;
        case 6: _t->on_btn_tologin_clicked(); break;
        case 7: _t->on_btn_toregister_clicked(); break;
        case 8: _t->on_btn_register_clicked(); break;
        case 9: _t->on_btn_rcancle_clicked(); break;
        case 10: _t->on_btn_scancle_clicked(); break;
        case 11: _t->on_btn_sreturn_clicked(); break;
        case 12: _t->on_btn_save_server_clicked(); break;
        case 13: _t->on_btn_to_setserver_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginDialog::*)(CmdType , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginDialog::sigLogin)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginDialog::*)(CmdType , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginDialog::sigRegister)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LoginDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginDialog::sigCloseApp)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoginDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_LoginDialog.data,
    qt_meta_data_LoginDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int LoginDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void LoginDialog::sigLogin(CmdType _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoginDialog::sigRegister(CmdType _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoginDialog::sigCloseApp()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
