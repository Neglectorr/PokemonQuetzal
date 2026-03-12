/****************************************************************************
** Meta object code from reading C++ file 'AssetTile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/AssetTile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AssetTile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__AssetTile_t {
    QByteArrayData data[13];
    char stringdata0[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__AssetTile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__AssetTile_t qt_meta_stringdata_QGBA__AssetTile = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::AssetTile"
QT_MOC_LITERAL(1, 16, 10), // "setPalette"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "setBoundary"
QT_MOC_LITERAL(4, 40, 8), // "boundary"
QT_MOC_LITERAL(5, 49, 4), // "set0"
QT_MOC_LITERAL(6, 54, 4), // "set1"
QT_MOC_LITERAL(7, 59, 11), // "selectIndex"
QT_MOC_LITERAL(8, 71, 7), // "setFlip"
QT_MOC_LITERAL(9, 79, 1), // "h"
QT_MOC_LITERAL(10, 81, 1), // "v"
QT_MOC_LITERAL(11, 83, 11), // "selectColor"
QT_MOC_LITERAL(12, 95, 10) // "setMaxTile"

    },
    "QGBA::AssetTile\0setPalette\0\0setBoundary\0"
    "boundary\0set0\0set1\0selectIndex\0setFlip\0"
    "h\0v\0selectColor\0setMaxTile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__AssetTile[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       3,    3,   47,    2, 0x0a /* Public */,
       7,    1,   54,    2, 0x0a /* Public */,
       8,    2,   57,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      12,    1,   65,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    9,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void QGBA::AssetTile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AssetTile *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setPalette((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setBoundary((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->selectIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setFlip((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->selectColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setMaxTile((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::AssetTile::staticMetaObject = { {
    QMetaObject::SuperData::link<AssetInfo::staticMetaObject>(),
    qt_meta_stringdata_QGBA__AssetTile.data,
    qt_meta_data_QGBA__AssetTile,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::AssetTile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::AssetTile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__AssetTile.stringdata0))
        return static_cast<void*>(this);
    return AssetInfo::qt_metacast(_clname);
}

int QGBA::AssetTile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssetInfo::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
