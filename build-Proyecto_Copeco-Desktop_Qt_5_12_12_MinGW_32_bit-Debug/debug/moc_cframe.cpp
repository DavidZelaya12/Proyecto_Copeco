/****************************************************************************
** Meta object code from reading C++ file 'cframe.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Proyecto_Copeco/cframe.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cframe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cframe_t {
    QByteArrayData data[12];
    char stringdata0[255];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cframe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cframe_t qt_meta_stringdata_cframe = {
    {
QT_MOC_LITERAL(0, 0, 6), // "cframe"
QT_MOC_LITERAL(1, 7, 24), // "on_botonlogearse_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 26), // "on_AgregarProducto_clicked"
QT_MOC_LITERAL(4, 60, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 82, 21), // "on_Btn_restar_clicked"
QT_MOC_LITERAL(6, 104, 23), // "on_CerrarSesion_clicked"
QT_MOC_LITERAL(7, 128, 25), // "on_CerrarSesion_3_clicked"
QT_MOC_LITERAL(8, 154, 25), // "on_CerrarSesion_2_clicked"
QT_MOC_LITERAL(9, 180, 19), // "on_TokenBtn_clicked"
QT_MOC_LITERAL(10, 200, 30), // "on_RegistrarUsuarioBTN_clicked"
QT_MOC_LITERAL(11, 231, 23) // "on_CerrarSesBTN_clicked"

    },
    "cframe\0on_botonlogearse_clicked\0\0"
    "on_AgregarProducto_clicked\0"
    "on_pushButton_clicked\0on_Btn_restar_clicked\0"
    "on_CerrarSesion_clicked\0"
    "on_CerrarSesion_3_clicked\0"
    "on_CerrarSesion_2_clicked\0on_TokenBtn_clicked\0"
    "on_RegistrarUsuarioBTN_clicked\0"
    "on_CerrarSesBTN_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cframe[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

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

void cframe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<cframe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_botonlogearse_clicked(); break;
        case 1: _t->on_AgregarProducto_clicked(); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_Btn_restar_clicked(); break;
        case 4: _t->on_CerrarSesion_clicked(); break;
        case 5: _t->on_CerrarSesion_3_clicked(); break;
        case 6: _t->on_CerrarSesion_2_clicked(); break;
        case 7: _t->on_TokenBtn_clicked(); break;
        case 8: _t->on_RegistrarUsuarioBTN_clicked(); break;
        case 9: _t->on_CerrarSesBTN_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject cframe::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_cframe.data,
    qt_meta_data_cframe,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *cframe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cframe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cframe.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int cframe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
