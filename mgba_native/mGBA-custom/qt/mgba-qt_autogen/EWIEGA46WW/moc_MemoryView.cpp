/****************************************************************************
** Meta object code from reading C++ file 'MemoryView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/MemoryView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemoryView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__IntValidator_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__IntValidator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__IntValidator_t qt_meta_stringdata_QGBA__IntValidator = {
    {
QT_MOC_LITERAL(0, 0, 18) // "QGBA::IntValidator"

    },
    "QGBA::IntValidator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__IntValidator[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QGBA::IntValidator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QGBA::IntValidator::staticMetaObject = { {
    QMetaObject::SuperData::link<QValidator::staticMetaObject>(),
    qt_meta_stringdata_QGBA__IntValidator.data,
    qt_meta_data_QGBA__IntValidator,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::IntValidator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::IntValidator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__IntValidator.stringdata0))
        return static_cast<void*>(this);
    return QValidator::qt_metacast(_clname);
}

int QGBA::IntValidator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QValidator::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QGBA__MemoryView_t {
    QByteArrayData data[13];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__MemoryView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__MemoryView_t qt_meta_stringdata_QGBA__MemoryView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QGBA::MemoryView"
QT_MOC_LITERAL(1, 17, 6), // "update"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 13), // "jumpToAddress"
QT_MOC_LITERAL(4, 39, 8), // "uint32_t"
QT_MOC_LITERAL(5, 48, 7), // "address"
QT_MOC_LITERAL(6, 56, 8), // "setIndex"
QT_MOC_LITERAL(7, 65, 10), // "setSegment"
QT_MOC_LITERAL(8, 76, 15), // "updateSelection"
QT_MOC_LITERAL(9, 92, 5), // "start"
QT_MOC_LITERAL(10, 98, 3), // "end"
QT_MOC_LITERAL(11, 102, 12), // "updateStatus"
QT_MOC_LITERAL(12, 115, 9) // "saveRange"

    },
    "QGBA::MemoryView\0update\0\0jumpToAddress\0"
    "uint32_t\0address\0setIndex\0setSegment\0"
    "updateSelection\0start\0end\0updateStatus\0"
    "saveRange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__MemoryView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    1,   50,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       8,    2,   59,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x08 /* Private */,
      12,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::MemoryView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoryView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->jumpToAddress((*reinterpret_cast< uint32_t(*)>(_a[1]))); break;
        case 2: _t->setIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setSegment((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->updateSelection((*reinterpret_cast< uint32_t(*)>(_a[1])),(*reinterpret_cast< uint32_t(*)>(_a[2]))); break;
        case 5: _t->updateStatus(); break;
        case 6: _t->saveRange(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::MemoryView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__MemoryView.data,
    qt_meta_data_QGBA__MemoryView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::MemoryView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::MemoryView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__MemoryView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::MemoryView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
