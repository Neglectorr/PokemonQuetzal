/****************************************************************************
** Meta object code from reading C++ file 'ShortcutController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/ShortcutController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShortcutController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__Shortcut_t {
    QByteArrayData data[13];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__Shortcut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__Shortcut_t qt_meta_stringdata_QGBA__Shortcut = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QGBA::Shortcut"
QT_MOC_LITERAL(1, 15, 15), // "shortcutChanged"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "sequence"
QT_MOC_LITERAL(4, 41, 13), // "buttonChanged"
QT_MOC_LITERAL(5, 55, 6), // "button"
QT_MOC_LITERAL(6, 62, 11), // "axisChanged"
QT_MOC_LITERAL(7, 74, 4), // "axis"
QT_MOC_LITERAL(8, 79, 27), // "GamepadAxisEvent::Direction"
QT_MOC_LITERAL(9, 107, 9), // "direction"
QT_MOC_LITERAL(10, 117, 11), // "setShortcut"
QT_MOC_LITERAL(11, 129, 9), // "setButton"
QT_MOC_LITERAL(12, 139, 7) // "setAxis"

    },
    "QGBA::Shortcut\0shortcutChanged\0\0"
    "sequence\0buttonChanged\0button\0axisChanged\0"
    "axis\0GamepadAxisEvent::Direction\0"
    "direction\0setShortcut\0setButton\0setAxis"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__Shortcut[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       6,    2,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   55,    2, 0x0a /* Public */,
      11,    1,   58,    2, 0x0a /* Public */,
      12,    2,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 8,    7,    9,

       0        // eod
};

void QGBA::Shortcut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Shortcut *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shortcutChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->buttonChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->axisChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GamepadAxisEvent::Direction(*)>(_a[2]))); break;
        case 3: _t->setShortcut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setAxis((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GamepadAxisEvent::Direction(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Shortcut::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Shortcut::shortcutChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Shortcut::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Shortcut::buttonChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Shortcut::*)(int , GamepadAxisEvent::Direction );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Shortcut::axisChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::Shortcut::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__Shortcut.data,
    qt_meta_data_QGBA__Shortcut,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::Shortcut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::Shortcut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__Shortcut.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::Shortcut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QGBA::Shortcut::shortcutChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::Shortcut::buttonChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::Shortcut::axisChanged(int _t1, GamepadAxisEvent::Direction _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
struct qt_meta_stringdata_QGBA__ShortcutController_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ShortcutController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ShortcutController_t qt_meta_stringdata_QGBA__ShortcutController = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QGBA::ShortcutController"
QT_MOC_LITERAL(1, 25, 13), // "shortcutAdded"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 4), // "name"
QT_MOC_LITERAL(4, 45, 11), // "menuCleared"
QT_MOC_LITERAL(5, 57, 11), // "loadProfile"
QT_MOC_LITERAL(6, 69, 7), // "profile"
QT_MOC_LITERAL(7, 77, 12) // "rebuildItems"

    },
    "QGBA::ShortcutController\0shortcutAdded\0"
    "\0name\0menuCleared\0loadProfile\0profile\0"
    "rebuildItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ShortcutController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   40,    2, 0x0a /* Public */,
       7,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void QGBA::ShortcutController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShortcutController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shortcutAdded((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->menuCleared((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loadProfile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->rebuildItems(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShortcutController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortcutController::shortcutAdded)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ShortcutController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShortcutController::menuCleared)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ShortcutController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ShortcutController.data,
    qt_meta_data_QGBA__ShortcutController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ShortcutController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ShortcutController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ShortcutController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::ShortcutController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QGBA::ShortcutController::shortcutAdded(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::ShortcutController::menuCleared(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
