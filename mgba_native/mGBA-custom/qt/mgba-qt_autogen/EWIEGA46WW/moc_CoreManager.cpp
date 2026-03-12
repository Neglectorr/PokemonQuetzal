/****************************************************************************
** Meta object code from reading C++ file 'CoreManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/CoreManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoreManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__CoreManager_t {
    QByteArrayData data[11];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__CoreManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__CoreManager_t qt_meta_stringdata_QGBA__CoreManager = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QGBA::CoreManager"
QT_MOC_LITERAL(1, 18, 10), // "coreLoaded"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "CoreController*"
QT_MOC_LITERAL(4, 46, 8), // "loadGame"
QT_MOC_LITERAL(5, 55, 4), // "path"
QT_MOC_LITERAL(6, 60, 6), // "VFile*"
QT_MOC_LITERAL(7, 67, 2), // "vf"
QT_MOC_LITERAL(8, 70, 4), // "base"
QT_MOC_LITERAL(9, 75, 8), // "loadBIOS"
QT_MOC_LITERAL(10, 84, 8) // "platform"

    },
    "QGBA::CoreManager\0coreLoaded\0\0"
    "CoreController*\0loadGame\0path\0VFile*\0"
    "vf\0base\0loadBIOS\0platform"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__CoreManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   37,    2, 0x0a /* Public */,
       4,    3,   40,    2, 0x0a /* Public */,
       9,    2,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    0x80000000 | 3, QMetaType::QString,    5,
    0x80000000 | 3, 0x80000000 | 6, QMetaType::QString, QMetaType::QString,    7,    5,    8,
    0x80000000 | 3, QMetaType::Int, QMetaType::QString,   10,    5,

       0        // eod
};

void QGBA::CoreManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoreManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->coreLoaded((*reinterpret_cast< CoreController*(*)>(_a[1]))); break;
        case 1: { CoreController* _r = _t->loadGame((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< CoreController**>(_a[0]) = std::move(_r); }  break;
        case 2: { CoreController* _r = _t->loadGame((*reinterpret_cast< VFile*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< CoreController**>(_a[0]) = std::move(_r); }  break;
        case 3: { CoreController* _r = _t->loadBIOS((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< CoreController**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CoreManager::*)(CoreController * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreManager::coreLoaded)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::CoreManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__CoreManager.data,
    qt_meta_data_QGBA__CoreManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::CoreManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::CoreManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__CoreManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::CoreManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QGBA::CoreManager::coreLoaded(CoreController * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
