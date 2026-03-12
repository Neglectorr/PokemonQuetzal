/****************************************************************************
** Meta object code from reading C++ file 'Action.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/Action.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Action.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__Action_t {
    QByteArrayData data[7];
    char stringdata0[61];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__Action_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__Action_t qt_meta_stringdata_QGBA__Action = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QGBA::Action"
QT_MOC_LITERAL(1, 13, 7), // "enabled"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 9), // "activated"
QT_MOC_LITERAL(4, 32, 7), // "trigger"
QT_MOC_LITERAL(5, 40, 10), // "setEnabled"
QT_MOC_LITERAL(6, 51, 9) // "setActive"

    },
    "QGBA::Action\0enabled\0\0activated\0trigger\0"
    "setEnabled\0setActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__Action[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       3,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   60,    2, 0x0a /* Public */,
       4,    0,   63,    2, 0x2a /* Public | MethodCloned */,
       5,    1,   64,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x2a /* Public | MethodCloned */,
       6,    1,   68,    2, 0x0a /* Public */,
       6,    0,   71,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void QGBA::Action::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Action *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->enabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->activated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->trigger((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->trigger(); break;
        case 4: _t->setEnabled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->setEnabled(); break;
        case 6: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->setActive(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Action::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Action::enabled)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Action::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Action::activated)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::Action::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__Action.data,
    qt_meta_data_QGBA__Action,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::Action::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::Action::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__Action.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::Action::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void QGBA::Action::enabled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::Action::activated(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
