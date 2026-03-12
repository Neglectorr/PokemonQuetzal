/****************************************************************************
** Meta object code from reading C++ file 'FrameView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/FrameView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FrameView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__FrameView_t {
    QByteArrayData data[11];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__FrameView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__FrameView_t qt_meta_stringdata_QGBA__FrameView = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::FrameView"
QT_MOC_LITERAL(1, 16, 11), // "selectLayer"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "coord"
QT_MOC_LITERAL(4, 35, 12), // "disableLayer"
QT_MOC_LITERAL(5, 48, 11), // "exportFrame"
QT_MOC_LITERAL(6, 60, 5), // "reset"
QT_MOC_LITERAL(7, 66, 15), // "invalidateQueue"
QT_MOC_LITERAL(8, 82, 14), // "updateRendered"
QT_MOC_LITERAL(9, 97, 9), // "refreshVl"
QT_MOC_LITERAL(10, 107, 5) // "newVl"

    },
    "QGBA::FrameView\0selectLayer\0\0coord\0"
    "disableLayer\0exportFrame\0reset\0"
    "invalidateQueue\0updateRendered\0refreshVl\0"
    "newVl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__FrameView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       5,    0,   65,    2, 0x0a /* Public */,
       6,    0,   66,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x28 /* Private | MethodCloned */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void, QMetaType::QPointF,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::FrameView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FrameView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectLayer((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 1: _t->disableLayer((*reinterpret_cast< const QPointF(*)>(_a[1]))); break;
        case 2: _t->exportFrame(); break;
        case 3: _t->reset(); break;
        case 4: _t->invalidateQueue((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 5: _t->invalidateQueue(); break;
        case 6: _t->updateRendered(); break;
        case 7: _t->refreshVl(); break;
        case 8: _t->newVl(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::FrameView::staticMetaObject = { {
    QMetaObject::SuperData::link<AssetView::staticMetaObject>(),
    qt_meta_stringdata_QGBA__FrameView.data,
    qt_meta_data_QGBA__FrameView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::FrameView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::FrameView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__FrameView.stringdata0))
        return static_cast<void*>(this);
    return AssetView::qt_metacast(_clname);
}

int QGBA::FrameView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssetView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
