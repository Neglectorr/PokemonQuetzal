/****************************************************************************
** Meta object code from reading C++ file 'ObjView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/ObjView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ObjView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ObjView_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ObjView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ObjView_t qt_meta_stringdata_QGBA__ObjView = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QGBA::ObjView"
QT_MOC_LITERAL(1, 14, 9), // "exportObj"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "copyObj"
QT_MOC_LITERAL(4, 33, 9), // "selectObj"
QT_MOC_LITERAL(5, 43, 14) // "translateIndex"

    },
    "QGBA::ObjView\0exportObj\0\0copyObj\0"
    "selectObj\0translateIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ObjView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x08 /* Private */,
       5,    1,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void QGBA::ObjView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ObjView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->exportObj(); break;
        case 1: _t->copyObj(); break;
        case 2: _t->selectObj((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->translateIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ObjView::staticMetaObject = { {
    QMetaObject::SuperData::link<AssetView::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ObjView.data,
    qt_meta_data_QGBA__ObjView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ObjView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ObjView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ObjView.stringdata0))
        return static_cast<void*>(this);
    return AssetView::qt_metacast(_clname);
}

int QGBA::ObjView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AssetView::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
