/****************************************************************************
** Meta object code from reading C++ file 'GBAKeyEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/GBAKeyEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GBAKeyEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__GBAKeyEditor_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__GBAKeyEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__GBAKeyEditor_t qt_meta_stringdata_QGBA__GBAKeyEditor = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QGBA::GBAKeyEditor"
QT_MOC_LITERAL(1, 19, 6), // "setAll"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 4), // "save"
QT_MOC_LITERAL(4, 32, 7), // "setNext"
QT_MOC_LITERAL(5, 40, 7), // "refresh"
QT_MOC_LITERAL(6, 48, 13), // "selectGamepad"
QT_MOC_LITERAL(7, 62, 5), // "index"
QT_MOC_LITERAL(8, 68, 15) // "updateJoysticks"

    },
    "QGBA::GBAKeyEditor\0setAll\0\0save\0setNext\0"
    "refresh\0selectGamepad\0index\0updateJoysticks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__GBAKeyEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void QGBA::GBAKeyEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GBAKeyEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setAll(); break;
        case 1: _t->save(); break;
        case 2: _t->setNext(); break;
        case 3: _t->refresh(); break;
        case 4: _t->selectGamepad((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->updateJoysticks(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::GBAKeyEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__GBAKeyEditor.data,
    qt_meta_data_QGBA__GBAKeyEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::GBAKeyEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::GBAKeyEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__GBAKeyEditor.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::GBAKeyEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
