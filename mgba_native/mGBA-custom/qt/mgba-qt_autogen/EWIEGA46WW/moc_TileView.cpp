/****************************************************************************
** Meta object code from reading C++ file 'TileView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/TileView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TileView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__TileView_t {
    QByteArrayData data[7];
    char stringdata0[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__TileView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__TileView_t qt_meta_stringdata_QGBA__TileView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QGBA::TileView"
QT_MOC_LITERAL(1, 15, 13), // "updatePalette"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "exportTiles"
QT_MOC_LITERAL(4, 42, 10), // "exportTile"
QT_MOC_LITERAL(5, 53, 9), // "copyTiles"
QT_MOC_LITERAL(6, 63, 8) // "copyTile"

    },
    "QGBA::TileView\0updatePalette\0\0exportTiles\0"
    "exportTile\0copyTiles\0copyTile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__TileView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::TileView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TileView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatePalette((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->exportTiles(); break;
        case 2: _t->exportTile(); break;
        case 3: _t->copyTiles(); break;
        case 4: _t->copyTile(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::TileView::staticMetaObject = { {
    QMetaObject::SuperData::link<AssetView::staticMetaObject>(),
    qt_meta_stringdata_QGBA__TileView.data,
    qt_meta_data_QGBA__TileView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::TileView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::TileView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__TileView.stringdata0))
        return static_cast<void*>(this);
    return AssetView::qt_metacast(_clname);
}

int QGBA::TileView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssetView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
