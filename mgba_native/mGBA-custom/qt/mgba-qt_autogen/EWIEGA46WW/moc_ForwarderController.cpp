/****************************************************************************
** Meta object code from reading C++ file 'ForwarderController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/ForwarderController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ForwarderController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ForwarderController_t {
    QByteArrayData data[19];
    char stringdata0[247];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ForwarderController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ForwarderController_t qt_meta_stringdata_QGBA__ForwarderController = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QGBA::ForwarderController"
QT_MOC_LITERAL(1, 26, 12), // "buildStarted"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 17), // "needsForwarderKit"
QT_MOC_LITERAL(4, 58, 15), // "downloadStarted"
QT_MOC_LITERAL(5, 74, 8), // "Download"
QT_MOC_LITERAL(6, 83, 5), // "which"
QT_MOC_LITERAL(7, 89, 16), // "downloadComplete"
QT_MOC_LITERAL(8, 106, 16), // "downloadProgress"
QT_MOC_LITERAL(9, 123, 11), // "bytesGotten"
QT_MOC_LITERAL(10, 135, 10), // "bytesTotal"
QT_MOC_LITERAL(11, 146, 13), // "buildComplete"
QT_MOC_LITERAL(12, 160, 11), // "buildFailed"
QT_MOC_LITERAL(13, 172, 10), // "startBuild"
QT_MOC_LITERAL(14, 183, 11), // "outFilename"
QT_MOC_LITERAL(15, 195, 11), // "gotManifest"
QT_MOC_LITERAL(16, 207, 14), // "QNetworkReply*"
QT_MOC_LITERAL(17, 222, 8), // "gotBuild"
QT_MOC_LITERAL(18, 231, 15) // "gotForwarderKit"

    },
    "QGBA::ForwarderController\0buildStarted\0"
    "\0needsForwarderKit\0downloadStarted\0"
    "Download\0which\0downloadComplete\0"
    "downloadProgress\0bytesGotten\0bytesTotal\0"
    "buildComplete\0buildFailed\0startBuild\0"
    "outFilename\0gotManifest\0QNetworkReply*\0"
    "gotBuild\0gotForwarderKit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ForwarderController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       8,    3,   73,    2, 0x06 /* Public */,
      11,    0,   80,    2, 0x06 /* Public */,
      12,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   82,    2, 0x0a /* Public */,
      15,    1,   85,    2, 0x08 /* Private */,
      17,    1,   88,    2, 0x08 /* Private */,
      18,    1,   91,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5, QMetaType::LongLong, QMetaType::LongLong,    6,    9,   10,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void, 0x80000000 | 16,    2,

       0        // eod
};

void QGBA::ForwarderController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ForwarderController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->buildStarted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->downloadStarted((*reinterpret_cast< Download(*)>(_a[1]))); break;
        case 2: _t->downloadComplete((*reinterpret_cast< Download(*)>(_a[1]))); break;
        case 3: _t->downloadProgress((*reinterpret_cast< Download(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 4: _t->buildComplete(); break;
        case 5: _t->buildFailed(); break;
        case 6: _t->startBuild((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->gotManifest((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 8: _t->gotBuild((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 9: _t->gotForwarderKit((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ForwarderController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::buildStarted)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ForwarderController::*)(Download );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::downloadStarted)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ForwarderController::*)(Download );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::downloadComplete)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ForwarderController::*)(Download , qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::downloadProgress)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ForwarderController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::buildComplete)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ForwarderController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ForwarderController::buildFailed)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ForwarderController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ForwarderController.data,
    qt_meta_data_QGBA__ForwarderController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ForwarderController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ForwarderController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ForwarderController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::ForwarderController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QGBA::ForwarderController::buildStarted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::ForwarderController::downloadStarted(Download _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::ForwarderController::downloadComplete(Download _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGBA::ForwarderController::downloadProgress(Download _t1, qint64 _t2, qint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QGBA::ForwarderController::buildComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void QGBA::ForwarderController::buildFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
