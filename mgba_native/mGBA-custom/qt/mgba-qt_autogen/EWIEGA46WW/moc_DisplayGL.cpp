/****************************************************************************
** Meta object code from reading C++ file 'DisplayGL.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/DisplayGL.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DisplayGL.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__mGLWidget_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__mGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__mGLWidget_t qt_meta_stringdata_QGBA__mGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "QGBA::mGLWidget"

    },
    "QGBA::mGLWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__mGLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QGBA::mGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QGBA::mGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__mGLWidget.data,
    qt_meta_data_QGBA__mGLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::mGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::mGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__mGLWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int QGBA::mGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QGBA__DisplayGL_t {
    QByteArrayData data[25];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__DisplayGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__DisplayGL_t qt_meta_stringdata_QGBA__DisplayGL = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::DisplayGL"
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
QT_MOC_LITERAL(11, 133, 15), // "showOSDMessages"
QT_MOC_LITERAL(12, 149, 16), // "showFrameCounter"
QT_MOC_LITERAL(13, 166, 6), // "filter"
QT_MOC_LITERAL(14, 173, 12), // "swapInterval"
QT_MOC_LITERAL(15, 186, 8), // "interval"
QT_MOC_LITERAL(16, 195, 11), // "framePosted"
QT_MOC_LITERAL(17, 207, 10), // "setShaders"
QT_MOC_LITERAL(18, 218, 5), // "VDir*"
QT_MOC_LITERAL(19, 224, 12), // "clearShaders"
QT_MOC_LITERAL(20, 237, 13), // "resizeContext"
QT_MOC_LITERAL(21, 251, 13), // "setVideoScale"
QT_MOC_LITERAL(22, 265, 5), // "scale"
QT_MOC_LITERAL(23, 271, 18), // "setBackgroundImage"
QT_MOC_LITERAL(24, 290, 17) // "updateContentSize"

    },
    "QGBA::DisplayGL\0stopDrawing\0\0pauseDrawing\0"
    "unpauseDrawing\0forceDraw\0lockAspectRatio\0"
    "lock\0lockIntegerScaling\0interframeBlending\0"
    "enable\0showOSDMessages\0showFrameCounter\0"
    "filter\0swapInterval\0interval\0framePosted\0"
    "setShaders\0VDir*\0clearShaders\0"
    "resizeContext\0setVideoScale\0scale\0"
    "setBackgroundImage\0updateContentSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__DisplayGL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    1,  108,    2, 0x0a /* Public */,
       8,    1,  111,    2, 0x0a /* Public */,
       9,    1,  114,    2, 0x0a /* Public */,
      11,    1,  117,    2, 0x0a /* Public */,
      12,    1,  120,    2, 0x0a /* Public */,
      13,    1,  123,    2, 0x0a /* Public */,
      14,    1,  126,    2, 0x0a /* Public */,
      16,    0,  129,    2, 0x0a /* Public */,
      17,    1,  130,    2, 0x0a /* Public */,
      19,    0,  133,    2, 0x0a /* Public */,
      20,    0,  134,    2, 0x0a /* Public */,
      21,    1,  135,    2, 0x0a /* Public */,
      23,    1,  138,    2, 0x0a /* Public */,
      24,    0,  141,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 18,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Void,

       0        // eod
};

void QGBA::DisplayGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DisplayGL *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->stopDrawing(); break;
        case 1: _t->pauseDrawing(); break;
        case 2: _t->unpauseDrawing(); break;
        case 3: _t->forceDraw(); break;
        case 4: _t->lockAspectRatio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->lockIntegerScaling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->interframeBlending((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->showOSDMessages((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->showFrameCounter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->filter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->swapInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->framePosted(); break;
        case 12: { bool _r = _t->setShaders((*reinterpret_cast< VDir*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->clearShaders(); break;
        case 14: _t->resizeContext(); break;
        case 15: _t->setVideoScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setBackgroundImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 17: _t->updateContentSize(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::DisplayGL::staticMetaObject = { {
    QMetaObject::SuperData::link<Display::staticMetaObject>(),
    qt_meta_stringdata_QGBA__DisplayGL.data,
    qt_meta_data_QGBA__DisplayGL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::DisplayGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::DisplayGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__DisplayGL.stringdata0))
        return static_cast<void*>(this);
    return Display::qt_metacast(_clname);
}

int QGBA::DisplayGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Display::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
struct qt_meta_stringdata_QGBA__PainterGL_t {
    QByteArrayData data[34];
    char stringdata0[344];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__PainterGL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__PainterGL_t qt_meta_stringdata_QGBA__PainterGL = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::PainterGL"
QT_MOC_LITERAL(1, 16, 7), // "created"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "started"
QT_MOC_LITERAL(4, 33, 10), // "texSwapped"
QT_MOC_LITERAL(5, 44, 6), // "create"
QT_MOC_LITERAL(6, 51, 7), // "destroy"
QT_MOC_LITERAL(7, 59, 9), // "forceDraw"
QT_MOC_LITERAL(8, 69, 4), // "draw"
QT_MOC_LITERAL(9, 74, 5), // "start"
QT_MOC_LITERAL(10, 80, 5), // "pause"
QT_MOC_LITERAL(11, 86, 7), // "unpause"
QT_MOC_LITERAL(12, 94, 6), // "resize"
QT_MOC_LITERAL(13, 101, 4), // "size"
QT_MOC_LITERAL(14, 106, 14), // "setMaximumSize"
QT_MOC_LITERAL(15, 121, 15), // "lockAspectRatio"
QT_MOC_LITERAL(16, 137, 4), // "lock"
QT_MOC_LITERAL(17, 142, 18), // "lockIntegerScaling"
QT_MOC_LITERAL(18, 161, 18), // "interframeBlending"
QT_MOC_LITERAL(19, 180, 6), // "enable"
QT_MOC_LITERAL(20, 187, 7), // "showOSD"
QT_MOC_LITERAL(21, 195, 16), // "showFrameCounter"
QT_MOC_LITERAL(22, 212, 6), // "filter"
QT_MOC_LITERAL(23, 219, 12), // "swapInterval"
QT_MOC_LITERAL(24, 232, 8), // "interval"
QT_MOC_LITERAL(25, 241, 13), // "resizeContext"
QT_MOC_LITERAL(26, 255, 18), // "setBackgroundImage"
QT_MOC_LITERAL(27, 274, 10), // "setShaders"
QT_MOC_LITERAL(28, 285, 5), // "VDir*"
QT_MOC_LITERAL(29, 291, 12), // "clearShaders"
QT_MOC_LITERAL(30, 304, 7), // "shaders"
QT_MOC_LITERAL(31, 312, 12), // "VideoShader*"
QT_MOC_LITERAL(32, 325, 11), // "contentSize"
QT_MOC_LITERAL(33, 337, 6) // "doStop"

    },
    "QGBA::PainterGL\0created\0\0started\0"
    "texSwapped\0create\0destroy\0forceDraw\0"
    "draw\0start\0pause\0unpause\0resize\0size\0"
    "setMaximumSize\0lockAspectRatio\0lock\0"
    "lockIntegerScaling\0interframeBlending\0"
    "enable\0showOSD\0showFrameCounter\0filter\0"
    "swapInterval\0interval\0resizeContext\0"
    "setBackgroundImage\0setShaders\0VDir*\0"
    "clearShaders\0shaders\0VideoShader*\0"
    "contentSize\0doStop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__PainterGL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  144,    2, 0x06 /* Public */,
       3,    0,  145,    2, 0x06 /* Public */,
       4,    0,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  147,    2, 0x0a /* Public */,
       6,    0,  148,    2, 0x0a /* Public */,
       7,    0,  149,    2, 0x0a /* Public */,
       8,    0,  150,    2, 0x0a /* Public */,
       9,    0,  151,    2, 0x0a /* Public */,
      10,    0,  152,    2, 0x0a /* Public */,
      11,    0,  153,    2, 0x0a /* Public */,
      12,    1,  154,    2, 0x0a /* Public */,
      14,    1,  157,    2, 0x0a /* Public */,
      15,    1,  160,    2, 0x0a /* Public */,
      17,    1,  163,    2, 0x0a /* Public */,
      18,    1,  166,    2, 0x0a /* Public */,
      20,    1,  169,    2, 0x0a /* Public */,
      21,    1,  172,    2, 0x0a /* Public */,
      22,    1,  175,    2, 0x0a /* Public */,
      23,    1,  178,    2, 0x0a /* Public */,
      25,    0,  181,    2, 0x0a /* Public */,
      26,    1,  182,    2, 0x0a /* Public */,
      27,    1,  185,    2, 0x0a /* Public */,
      29,    0,  188,    2, 0x0a /* Public */,
      30,    0,  189,    2, 0x0a /* Public */,
      32,    0,  190,    2, 0x0a /* Public */,
      33,    0,  191,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,   13,
    QMetaType::Void, QMetaType::QSize,   13,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage,    2,
    QMetaType::Bool, 0x80000000 | 28,    2,
    QMetaType::Void,
    0x80000000 | 31,
    QMetaType::QSize,
    QMetaType::Void,

       0        // eod
};

void QGBA::PainterGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PainterGL *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->created(); break;
        case 1: _t->started(); break;
        case 2: _t->texSwapped(); break;
        case 3: _t->create(); break;
        case 4: _t->destroy(); break;
        case 5: _t->forceDraw(); break;
        case 6: _t->draw(); break;
        case 7: _t->start(); break;
        case 8: _t->pause(); break;
        case 9: _t->unpause(); break;
        case 10: _t->resize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 11: _t->setMaximumSize((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 12: _t->lockAspectRatio((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->lockIntegerScaling((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->interframeBlending((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->showOSD((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->showFrameCounter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->filter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->swapInterval((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->resizeContext(); break;
        case 20: _t->setBackgroundImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 21: { bool _r = _t->setShaders((*reinterpret_cast< VDir*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 22: _t->clearShaders(); break;
        case 23: { VideoShader* _r = _t->shaders();
            if (_a[0]) *reinterpret_cast< VideoShader**>(_a[0]) = std::move(_r); }  break;
        case 24: { QSize _r = _t->contentSize();
            if (_a[0]) *reinterpret_cast< QSize*>(_a[0]) = std::move(_r); }  break;
        case 25: _t->doStop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PainterGL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PainterGL::created)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PainterGL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PainterGL::started)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PainterGL::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PainterGL::texSwapped)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::PainterGL::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__PainterGL.data,
    qt_meta_data_QGBA__PainterGL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::PainterGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::PainterGL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__PainterGL.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::PainterGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 26;
    }
    return _id;
}

// SIGNAL 0
void QGBA::PainterGL::created()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::PainterGL::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGBA::PainterGL::texSwapped()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
