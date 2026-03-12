/****************************************************************************
** Meta object code from reading C++ file 'TilePainter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/TilePainter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TilePainter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__TilePainter_t {
    QByteArrayData data[12];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__TilePainter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__TilePainter_t qt_meta_stringdata_QGBA__TilePainter = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QGBA::TilePainter"
QT_MOC_LITERAL(1, 18, 12), // "indexPressed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "index"
QT_MOC_LITERAL(4, 38, 11), // "needsRedraw"
QT_MOC_LITERAL(5, 50, 9), // "clearTile"
QT_MOC_LITERAL(6, 60, 7), // "setTile"
QT_MOC_LITERAL(7, 68, 13), // "const mColor*"
QT_MOC_LITERAL(8, 82, 12), // "setTileCount"
QT_MOC_LITERAL(9, 95, 5), // "tiles"
QT_MOC_LITERAL(10, 101, 20), // "setTileMagnification"
QT_MOC_LITERAL(11, 122, 3) // "mag"

    },
    "QGBA::TilePainter\0indexPressed\0\0index\0"
    "needsRedraw\0clearTile\0setTile\0"
    "const mColor*\0setTileCount\0tiles\0"
    "setTileMagnification\0mag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__TilePainter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   48,    2, 0x0a /* Public */,
       6,    2,   51,    2, 0x0a /* Public */,
       8,    1,   56,    2, 0x0a /* Public */,
      10,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    3,    2,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void QGBA::TilePainter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TilePainter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->indexPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->needsRedraw(); break;
        case 2: _t->clearTile((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setTile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const mColor*(*)>(_a[2]))); break;
        case 4: _t->setTileCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setTileMagnification((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TilePainter::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TilePainter::indexPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TilePainter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TilePainter::needsRedraw)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::TilePainter::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__TilePainter.data,
    qt_meta_data_QGBA__TilePainter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::TilePainter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::TilePainter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__TilePainter.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::TilePainter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QGBA::TilePainter::indexPressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::TilePainter::needsRedraw()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
