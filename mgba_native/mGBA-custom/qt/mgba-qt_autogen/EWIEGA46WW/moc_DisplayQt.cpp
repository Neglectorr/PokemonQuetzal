/****************************************************************************
** Meta object code from reading C++ file 'DisplayQt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/DisplayQt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DisplayQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__DisplayQt_t {
    QByteArrayData data[19];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__DisplayQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__DisplayQt_t qt_meta_stringdata_QGBA__DisplayQt = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::DisplayQt"
QT_MOC_LITERAL(1, 16, 11), // "stopDrawing"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "pauseDrawing"
QT_MOC_LITERAL(4, 42, 14), // "unpauseDrawing"
QT_MOC_LITERAL(5, 57, 9), // "forceDraw"
QT_MOC_LITERAL(6, 67, 15), // "lockAspectRatio"
QT_MOC_LITERAL(7, 83, 4), // "lock"
QT_MOC_LITERAL(8, 88, 18), // "lockIntegerScaling"
QT_MOC_LITERAL(9, 107, 18), // "interframeBlending"
QT_MOC_LITERAL(10, 126, 6), // "enable"
QT_MOC_LITERAL(11, 133, 12), // "swapInterval"
QT_MOC_LITERAL(12, 146, 6), // "filter"
QT_MOC_LITERAL(13, 153, 11), // "framePosted"
QT_MOC_LITERAL(14, 165, 10), // "setShaders"
QT_MOC_LITERAL(15, 176, 5), // "VDir*"
QT_MOC_LITERAL(16, 182, 12), // "clearShaders"
QT_MOC_LITERAL(17, 195, 13), // "resizeContext"
QT_MOC_LITERAL(18, 209, 18) // "setBackgroundImage"

    },
    "QGBA::DisplayQt\0stopDrawing\0\0pauseDrawing\0"
    "unpauseDrawing\0forceDraw\0lockAspectRatio\0"
    "lock\0lockIntegerScaling\0interframeBlending\0"
    "enable\0swapInterval\0filter\0framePosted\0"
    "setShaders\0VDir*\0clearShaders\0"
    "resizeContext\0setBackgroundImage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__DisplayQt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       8,    1,   91,    2, 0x0a /* Public */,
       9,    1,   94,    2, 0x0a /* Public */,
      11,    1,   97,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    1,  104,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x0a /* Public */,
      17,    0,  108,    2, 0x0a /* Public */,
      18,    1,  109,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    2,

       0        // eod
};

void QGBA::DisplayQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DisplayQt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stopDrawing(); break;
        case 1: _t->pauseDrawing(); break;
        case 2: _t->unpauseDrawing(); break;
        case 3: _t->forceDraw(); break;
        case 4: _t->lockAspectRatio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->lockIntegerScaling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->interframeBlending((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->swapInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->filter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->framePosted(); break;
        case 10: { bool _r = _t->setShaders((*reinterpret_cast< VDir*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->clearShaders(); break;
        case 12: _t->resizeContext(); break;
        case 13: _t->setBackgroundImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::DisplayQt::staticMetaObject = { {
    QMetaObject::SuperData::link<Display::staticMetaObject>(),
    qt_meta_stringdata_QGBA__DisplayQt.data,
    qt_meta_data_QGBA__DisplayQt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::DisplayQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::DisplayQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__DisplayQt.stringdata0))
        return static_cast<void*>(this);
    return Display::qt_metacast(_clname);
}

int QGBA::DisplayQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
