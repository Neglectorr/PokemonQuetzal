/****************************************************************************
** Meta object code from reading C++ file 'ConfigController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/ConfigController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConfigController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ConfigOption_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ConfigOption_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ConfigOption_t qt_meta_stringdata_QGBA__ConfigOption = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QGBA::ConfigOption"
QT_MOC_LITERAL(1, 19, 12), // "valueChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "value"
QT_MOC_LITERAL(4, 39, 8), // "setValue"
QT_MOC_LITERAL(5, 48, 11) // "const char*"

    },
    "QGBA::ConfigOption\0valueChanged\0\0value\0"
    "setValue\0const char*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ConfigOption[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   47,    2, 0x0a /* Public */,
       4,    1,   50,    2, 0x0a /* Public */,
       4,    1,   53,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x0a /* Public */,
       4,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::UInt,    3,
    QMetaType::Void, 0x80000000 | 5,    3,
    QMetaType::Void, QMetaType::QVariant,    3,

       0        // eod
};

void QGBA::ConfigOption::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigOption *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 1: _t->setValue((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setValue((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< const char*(*)>(_a[1]))); break;
        case 5: _t->setValue((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ConfigOption::*)(const QVariant & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ConfigOption::valueChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ConfigOption::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ConfigOption.data,
    qt_meta_data_QGBA__ConfigOption,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ConfigOption::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ConfigOption::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ConfigOption.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::ConfigOption::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QGBA::ConfigOption::valueChanged(const QVariant & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QGBA__ConfigController_t {
    QByteArrayData data[15];
    char stringdata0[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ConfigController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ConfigController_t qt_meta_stringdata_QGBA__ConfigController = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QGBA::ConfigController"
QT_MOC_LITERAL(1, 23, 9), // "setOption"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 11), // "const char*"
QT_MOC_LITERAL(4, 46, 3), // "key"
QT_MOC_LITERAL(5, 50, 5), // "value"
QT_MOC_LITERAL(6, 56, 11), // "setQtOption"
QT_MOC_LITERAL(7, 68, 5), // "group"
QT_MOC_LITERAL(8, 74, 6), // "setMRU"
QT_MOC_LITERAL(9, 81, 3), // "mru"
QT_MOC_LITERAL(10, 85, 3), // "MRU"
QT_MOC_LITERAL(11, 89, 7), // "setList"
QT_MOC_LITERAL(12, 97, 4), // "list"
QT_MOC_LITERAL(13, 102, 12), // "makePortable"
QT_MOC_LITERAL(14, 115, 5) // "write"

    },
    "QGBA::ConfigController\0setOption\0\0"
    "const char*\0key\0value\0setQtOption\0"
    "group\0setMRU\0mru\0MRU\0setList\0list\0"
    "makePortable\0write"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ConfigController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x0a /* Public */,
       1,    2,   79,    2, 0x0a /* Public */,
       1,    2,   84,    2, 0x0a /* Public */,
       1,    2,   89,    2, 0x0a /* Public */,
       1,    2,   94,    2, 0x0a /* Public */,
       6,    3,   99,    2, 0x0a /* Public */,
       6,    2,  106,    2, 0x2a /* Public | MethodCloned */,
       8,    2,  111,    2, 0x0a /* Public */,
       8,    1,  116,    2, 0x2a /* Public | MethodCloned */,
      11,    2,  119,    2, 0x0a /* Public */,
      13,    0,  124,    2, 0x0a /* Public */,
      14,    0,  125,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt,    4,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QVariant,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant, QMetaType::QString,    4,    5,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariant,    4,    5,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 10,    9,    2,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantList,    7,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::ConfigController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ConfigController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setOption((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->setOption((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setOption((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->setOption((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const char*(*)>(_a[2]))); break;
        case 4: _t->setOption((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 5: _t->setQtOption((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 6: _t->setQtOption((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVariant(*)>(_a[2]))); break;
        case 7: _t->setMRU((*reinterpret_cast< const QStringList(*)>(_a[1])),(*reinterpret_cast< MRU(*)>(_a[2]))); break;
        case 8: _t->setMRU((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 9: _t->setList((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<QVariant>(*)>(_a[2]))); break;
        case 10: _t->makePortable(); break;
        case 11: _t->write(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ConfigController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ConfigController.data,
    qt_meta_data_QGBA__ConfigController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ConfigController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ConfigController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ConfigController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::ConfigController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
