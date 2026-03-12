/****************************************************************************
** Meta object code from reading C++ file 'InputController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/InputController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InputController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__InputController_t {
    QByteArrayData data[27];
    char stringdata0[315];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__InputController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__InputController_t qt_meta_stringdata_QGBA__InputController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QGBA::InputController"
QT_MOC_LITERAL(1, 22, 7), // "updated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "profileLoaded"
QT_MOC_LITERAL(4, 45, 7), // "profile"
QT_MOC_LITERAL(5, 53, 21), // "luminanceValueChanged"
QT_MOC_LITERAL(6, 75, 5), // "value"
QT_MOC_LITERAL(7, 81, 11), // "testGamepad"
QT_MOC_LITERAL(8, 93, 8), // "uint32_t"
QT_MOC_LITERAL(9, 102, 4), // "type"
QT_MOC_LITERAL(10, 107, 6), // "update"
QT_MOC_LITERAL(11, 114, 22), // "increaseLuminanceLevel"
QT_MOC_LITERAL(12, 137, 22), // "decreaseLuminanceLevel"
QT_MOC_LITERAL(13, 160, 17), // "setLuminanceLevel"
QT_MOC_LITERAL(14, 178, 5), // "level"
QT_MOC_LITERAL(15, 184, 17), // "setLuminanceValue"
QT_MOC_LITERAL(16, 202, 7), // "uint8_t"
QT_MOC_LITERAL(17, 210, 12), // "loadCamImage"
QT_MOC_LITERAL(18, 223, 4), // "path"
QT_MOC_LITERAL(19, 228, 11), // "setCamImage"
QT_MOC_LITERAL(20, 240, 5), // "image"
QT_MOC_LITERAL(21, 246, 9), // "setCamera"
QT_MOC_LITERAL(22, 256, 2), // "id"
QT_MOC_LITERAL(23, 259, 18), // "prepareCamSettings"
QT_MOC_LITERAL(24, 278, 15), // "QCamera::Status"
QT_MOC_LITERAL(25, 294, 8), // "setupCam"
QT_MOC_LITERAL(26, 303, 11) // "teardownCam"

    },
    "QGBA::InputController\0updated\0\0"
    "profileLoaded\0profile\0luminanceValueChanged\0"
    "value\0testGamepad\0uint32_t\0type\0update\0"
    "increaseLuminanceLevel\0decreaseLuminanceLevel\0"
    "setLuminanceLevel\0level\0setLuminanceValue\0"
    "uint8_t\0loadCamImage\0path\0setCamImage\0"
    "image\0setCamera\0id\0prepareCamSettings\0"
    "QCamera::Status\0setupCam\0teardownCam"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__InputController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   96,    2, 0x0a /* Public */,
      10,    0,   99,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    1,  102,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,
      17,    1,  108,    2, 0x0a /* Public */,
      19,    1,  111,    2, 0x0a /* Public */,
      21,    1,  114,    2, 0x0a /* Public */,
      23,    1,  117,    2, 0x08 /* Private */,
      25,    0,  120,    2, 0x08 /* Private */,
      26,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, 0x80000000 | 16,    6,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QImage,   20,
    QMetaType::Void, QMetaType::QByteArray,   22,
    QMetaType::Void, 0x80000000 | 24,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::InputController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InputController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updated(); break;
        case 1: _t->profileLoaded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->luminanceValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->testGamepad((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 4: _t->update(); break;
        case 5: _t->increaseLuminanceLevel(); break;
        case 6: _t->decreaseLuminanceLevel(); break;
        case 7: _t->setLuminanceLevel((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setLuminanceValue((*reinterpret_cast< uint8_t(*)>(_a[1]))); break;
        case 9: _t->loadCamImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setCamImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 11: _t->setCamera((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 12: _t->prepareCamSettings((*reinterpret_cast< QCamera::Status(*)>(_a[1]))); break;
        case 13: _t->setupCam(); break;
        case 14: _t->teardownCam(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCamera::Status >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (InputController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputController::updated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (InputController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputController::profileLoaded)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (InputController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&InputController::luminanceValueChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::InputController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__InputController.data,
    qt_meta_data_QGBA__InputController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::InputController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::InputController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__InputController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::InputController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void QGBA::InputController::updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::InputController::profileLoaded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::InputController::luminanceValueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
