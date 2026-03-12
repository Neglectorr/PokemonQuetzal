/****************************************************************************
** Meta object code from reading C++ file 'MemoryAccessLogController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/MemoryAccessLogController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemoryAccessLogController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__MemoryAccessLogController_t {
    QByteArrayData data[19];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__MemoryAccessLogController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__MemoryAccessLogController_t qt_meta_stringdata_QGBA__MemoryAccessLogController = {
    {
QT_MOC_LITERAL(0, 0, 31), // "QGBA::MemoryAccessLogController"
QT_MOC_LITERAL(1, 32, 6), // "loaded"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 14), // "loggingChanged"
QT_MOC_LITERAL(4, 55, 6), // "active"
QT_MOC_LITERAL(5, 62, 20), // "regionMappingChanged"
QT_MOC_LITERAL(6, 83, 12), // "internalName"
QT_MOC_LITERAL(7, 96, 12), // "updateRegion"
QT_MOC_LITERAL(8, 109, 6), // "enable"
QT_MOC_LITERAL(9, 116, 7), // "setFile"
QT_MOC_LITERAL(10, 124, 4), // "path"
QT_MOC_LITERAL(11, 129, 5), // "start"
QT_MOC_LITERAL(12, 135, 12), // "loadExisting"
QT_MOC_LITERAL(13, 148, 8), // "logExtra"
QT_MOC_LITERAL(14, 157, 4), // "stop"
QT_MOC_LITERAL(15, 162, 4), // "load"
QT_MOC_LITERAL(16, 167, 6), // "unload"
QT_MOC_LITERAL(17, 174, 10), // "exportFile"
QT_MOC_LITERAL(18, 185, 8) // "filename"

    },
    "QGBA::MemoryAccessLogController\0loaded\0"
    "\0loggingChanged\0active\0regionMappingChanged\0"
    "internalName\0updateRegion\0enable\0"
    "setFile\0path\0start\0loadExisting\0"
    "logExtra\0stop\0load\0unload\0exportFile\0"
    "filename"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__MemoryAccessLogController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    1,   67,    2, 0x06 /* Public */,
       5,    2,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    2,   75,    2, 0x0a /* Public */,
       9,    1,   80,    2, 0x0a /* Public */,
      11,    2,   83,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,
      15,    1,   89,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    1,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    6,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    6,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,

       0        // eod
};

void QGBA::MemoryAccessLogController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoryAccessLogController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loaded((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->loggingChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->regionMappingChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->updateRegion((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->start((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 6: _t->stop(); break;
        case 7: _t->load((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->unload(); break;
        case 9: _t->exportFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MemoryAccessLogController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MemoryAccessLogController::loaded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MemoryAccessLogController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MemoryAccessLogController::loggingChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MemoryAccessLogController::*)(const QString & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MemoryAccessLogController::regionMappingChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::MemoryAccessLogController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__MemoryAccessLogController.data,
    qt_meta_data_QGBA__MemoryAccessLogController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::MemoryAccessLogController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::MemoryAccessLogController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__MemoryAccessLogController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::MemoryAccessLogController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QGBA::MemoryAccessLogController::loaded(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::MemoryAccessLogController::loggingChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::MemoryAccessLogController::regionMappingChanged(const QString & _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
