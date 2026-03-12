/****************************************************************************
** Meta object code from reading C++ file 'AbstractUpdater.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/AbstractUpdater.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AbstractUpdater.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__AbstractUpdater_t {
    QByteArrayData data[10];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__AbstractUpdater_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__AbstractUpdater_t qt_meta_stringdata_QGBA__AbstractUpdater = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QGBA::AbstractUpdater"
QT_MOC_LITERAL(1, 22, 15), // "updateAvailable"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 10), // "updateDone"
QT_MOC_LITERAL(4, 50, 14), // "updateProgress"
QT_MOC_LITERAL(5, 65, 4), // "done"
QT_MOC_LITERAL(6, 70, 11), // "checkUpdate"
QT_MOC_LITERAL(7, 82, 14), // "downloadUpdate"
QT_MOC_LITERAL(8, 97, 8), // "progress"
QT_MOC_LITERAL(9, 106, 3) // "max"

    },
    "QGBA::AbstractUpdater\0updateAvailable\0"
    "\0updateDone\0updateProgress\0done\0"
    "checkUpdate\0downloadUpdate\0progress\0"
    "max"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__AbstractUpdater[] = {

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
       3,    1,   47,    2, 0x06 /* Public */,
       4,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    2,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Float,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    8,    9,

       0        // eod
};

void QGBA::AbstractUpdater::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AbstractUpdater *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->updateDone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->updateProgress((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->checkUpdate(); break;
        case 4: _t->downloadUpdate(); break;
        case 5: _t->progress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AbstractUpdater::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractUpdater::updateAvailable)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AbstractUpdater::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractUpdater::updateDone)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AbstractUpdater::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractUpdater::updateProgress)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::AbstractUpdater::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__AbstractUpdater.data,
    qt_meta_data_QGBA__AbstractUpdater,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::AbstractUpdater::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::AbstractUpdater::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__AbstractUpdater.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::AbstractUpdater::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QGBA::AbstractUpdater::updateAvailable(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::AbstractUpdater::updateDone(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::AbstractUpdater::updateProgress(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
