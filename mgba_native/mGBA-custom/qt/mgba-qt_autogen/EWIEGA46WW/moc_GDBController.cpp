/****************************************************************************
** Meta object code from reading C++ file 'GDBController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/GDBController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GDBController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__GDBController_t {
    QByteArrayData data[11];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__GDBController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__GDBController_t qt_meta_stringdata_QGBA__GDBController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QGBA::GDBController"
QT_MOC_LITERAL(1, 20, 9), // "listening"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "listenFailed"
QT_MOC_LITERAL(4, 44, 7), // "setPort"
QT_MOC_LITERAL(5, 52, 4), // "port"
QT_MOC_LITERAL(6, 57, 14), // "setBindAddress"
QT_MOC_LITERAL(7, 72, 7), // "Address"
QT_MOC_LITERAL(8, 80, 22), // "setWatchpointsBehavior"
QT_MOC_LITERAL(9, 103, 21), // "watchpointsBehaviorId"
QT_MOC_LITERAL(10, 125, 6) // "listen"

    },
    "QGBA::GDBController\0listening\0\0"
    "listenFailed\0setPort\0port\0setBindAddress\0"
    "Address\0setWatchpointsBehavior\0"
    "watchpointsBehaviorId\0listen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__GDBController[] = {

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
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   46,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
      10,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    5,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,

       0        // eod
};

void QGBA::GDBController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GDBController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->listening(); break;
        case 1: _t->listenFailed(); break;
        case 2: _t->setPort((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 3: _t->setBindAddress((*reinterpret_cast< const Address(*)>(_a[1]))); break;
        case 4: _t->setWatchpointsBehavior((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->listen(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GDBController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GDBController::listening)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GDBController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GDBController::listenFailed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::GDBController::staticMetaObject = { {
    QMetaObject::SuperData::link<DebuggerController::staticMetaObject>(),
    qt_meta_stringdata_QGBA__GDBController.data,
    qt_meta_data_QGBA__GDBController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::GDBController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::GDBController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__GDBController.stringdata0))
        return static_cast<void*>(this);
    return DebuggerController::qt_metacast(_clname);
}

int QGBA::GDBController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DebuggerController::qt_metacall(_c, _id, _a);
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
void QGBA::GDBController::listening()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::GDBController::listenFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
