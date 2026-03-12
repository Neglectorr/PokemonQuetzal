/****************************************************************************
** Meta object code from reading C++ file 'GBAApp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/GBAApp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GBAApp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__GameDBParser_t {
    QByteArrayData data[3];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__GameDBParser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__GameDBParser_t qt_meta_stringdata_QGBA__GameDBParser = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QGBA::GameDBParser"
QT_MOC_LITERAL(1, 19, 14), // "parseNoIntroDB"
QT_MOC_LITERAL(2, 34, 0) // ""

    },
    "QGBA::GameDBParser\0parseNoIntroDB\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__GameDBParser[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void QGBA::GameDBParser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameDBParser *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->parseNoIntroDB(); break;
        default: ;
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QGBA::GameDBParser::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__GameDBParser.data,
    qt_meta_data_QGBA__GameDBParser,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::GameDBParser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::GameDBParser::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__GameDBParser.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::GameDBParser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_QGBA__GBAApp_t {
    QByteArrayData data[12];
    char stringdata0[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__GBAApp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__GBAApp_t qt_meta_stringdata_QGBA__GBAApp = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QGBA::GBAApp"
QT_MOC_LITERAL(1, 13, 11), // "jobFinished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "jobId"
QT_MOC_LITERAL(4, 32, 16), // "restartForUpdate"
QT_MOC_LITERAL(5, 49, 9), // "newWindow"
QT_MOC_LITERAL(6, 59, 7), // "Window*"
QT_MOC_LITERAL(7, 67, 18), // "suspendScreensaver"
QT_MOC_LITERAL(8, 86, 17), // "resumeScreensaver"
QT_MOC_LITERAL(9, 104, 25), // "setScreensaverSuspendable"
QT_MOC_LITERAL(10, 130, 9), // "finishJob"
QT_MOC_LITERAL(11, 140, 7) // "cleanup"

    },
    "QGBA::GBAApp\0jobFinished\0\0jobId\0"
    "restartForUpdate\0newWindow\0Window*\0"
    "suspendScreensaver\0resumeScreensaver\0"
    "setScreensaverSuspendable\0finishJob\0"
    "cleanup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__GBAApp[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void,

       0        // eod
};

void QGBA::GBAApp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GBAApp *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->jobFinished((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->restartForUpdate(); break;
        case 2: { Window* _r = _t->newWindow();
            if (_a[0]) *reinterpret_cast< Window**>(_a[0]) = std::move(_r); }  break;
        case 3: _t->suspendScreensaver(); break;
        case 4: _t->resumeScreensaver(); break;
        case 5: _t->setScreensaverSuspendable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->finishJob((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->cleanup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GBAApp::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GBAApp::jobFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::GBAApp::staticMetaObject = { {
    QMetaObject::SuperData::link<QApplication::staticMetaObject>(),
    qt_meta_stringdata_QGBA__GBAApp.data,
    qt_meta_data_QGBA__GBAApp,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::GBAApp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::GBAApp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__GBAApp.stringdata0))
        return static_cast<void*>(this);
    return QApplication::qt_metacast(_clname);
}

int QGBA::GBAApp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QGBA::GBAApp::jobFinished(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
