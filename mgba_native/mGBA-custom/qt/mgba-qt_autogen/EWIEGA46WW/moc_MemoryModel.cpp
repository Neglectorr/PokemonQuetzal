/****************************************************************************
** Meta object code from reading C++ file 'MemoryModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/MemoryModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemoryModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__MemoryModel_t {
    QByteArrayData data[15];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__MemoryModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__MemoryModel_t qt_meta_stringdata_QGBA__MemoryModel = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QGBA::MemoryModel"
QT_MOC_LITERAL(1, 18, 16), // "selectionChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 8), // "uint32_t"
QT_MOC_LITERAL(4, 45, 5), // "start"
QT_MOC_LITERAL(5, 51, 3), // "end"
QT_MOC_LITERAL(6, 55, 13), // "jumpToAddress"
QT_MOC_LITERAL(7, 69, 3), // "hex"
QT_MOC_LITERAL(8, 73, 15), // "loadTBLFromPath"
QT_MOC_LITERAL(9, 89, 4), // "path"
QT_MOC_LITERAL(10, 94, 7), // "loadTBL"
QT_MOC_LITERAL(11, 102, 4), // "copy"
QT_MOC_LITERAL(12, 107, 5), // "paste"
QT_MOC_LITERAL(13, 113, 4), // "save"
QT_MOC_LITERAL(14, 118, 4) // "load"

    },
    "QGBA::MemoryModel\0selectionChanged\0\0"
    "uint32_t\0start\0end\0jumpToAddress\0hex\0"
    "loadTBLFromPath\0path\0loadTBL\0copy\0"
    "paste\0save\0load"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__MemoryModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   64,    2, 0x0a /* Public */,
       6,    1,   67,    2, 0x0a /* Public */,
       8,    1,   70,    2, 0x0a /* Public */,
      10,    0,   73,    2, 0x0a /* Public */,
      11,    0,   74,    2, 0x0a /* Public */,
      12,    0,   75,    2, 0x0a /* Public */,
      13,    0,   76,    2, 0x0a /* Public */,
      14,    0,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::MemoryModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoryModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectionChanged((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 1: _t->jumpToAddress((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->jumpToAddress((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 3: _t->loadTBLFromPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->loadTBL(); break;
        case 5: _t->copy(); break;
        case 6: _t->paste(); break;
        case 7: _t->save(); break;
        case 8: _t->load(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MemoryModel::*)(uint32_t , uint32_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MemoryModel::selectionChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::MemoryModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractScrollArea::staticMetaObject>(),
    qt_meta_stringdata_QGBA__MemoryModel.data,
    qt_meta_data_QGBA__MemoryModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::MemoryModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::MemoryModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__MemoryModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractScrollArea::qt_metacast(_clname);
}

int QGBA::MemoryModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void QGBA::MemoryModel::selectionChanged(uint32_t _t1, uint32_t _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
