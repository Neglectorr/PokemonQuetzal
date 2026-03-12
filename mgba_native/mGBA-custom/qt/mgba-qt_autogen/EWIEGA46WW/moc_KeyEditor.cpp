/****************************************************************************
** Meta object code from reading C++ file 'KeyEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/KeyEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__KeyEditor_t {
    QByteArrayData data[21];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__KeyEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__KeyEditor_t qt_meta_stringdata_QGBA__KeyEditor = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QGBA::KeyEditor"
QT_MOC_LITERAL(1, 16, 12), // "valueChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "key"
QT_MOC_LITERAL(4, 34, 11), // "axisChanged"
QT_MOC_LITERAL(5, 46, 4), // "axis"
QT_MOC_LITERAL(6, 51, 9), // "direction"
QT_MOC_LITERAL(7, 61, 10), // "hatChanged"
QT_MOC_LITERAL(8, 72, 3), // "hat"
QT_MOC_LITERAL(9, 76, 8), // "setValue"
QT_MOC_LITERAL(10, 85, 11), // "setValueKey"
QT_MOC_LITERAL(11, 97, 14), // "setValueButton"
QT_MOC_LITERAL(12, 112, 6), // "button"
QT_MOC_LITERAL(13, 119, 12), // "setValueAxis"
QT_MOC_LITERAL(14, 132, 27), // "GamepadAxisEvent::Direction"
QT_MOC_LITERAL(15, 160, 5), // "value"
QT_MOC_LITERAL(16, 166, 11), // "setValueHat"
QT_MOC_LITERAL(17, 178, 26), // "GamepadHatEvent::Direction"
QT_MOC_LITERAL(18, 205, 11), // "clearButton"
QT_MOC_LITERAL(19, 217, 9), // "clearAxis"
QT_MOC_LITERAL(20, 227, 8) // "clearHat"

    },
    "QGBA::KeyEditor\0valueChanged\0\0key\0"
    "axisChanged\0axis\0direction\0hatChanged\0"
    "hat\0setValue\0setValueKey\0setValueButton\0"
    "button\0setValueAxis\0GamepadAxisEvent::Direction\0"
    "value\0setValueHat\0GamepadHatEvent::Direction\0"
    "clearButton\0clearAxis\0clearHat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__KeyEditor[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       7,    2,   77,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   82,    2, 0x0a /* Public */,
      10,    1,   85,    2, 0x0a /* Public */,
      11,    1,   88,    2, 0x0a /* Public */,
      13,    2,   91,    2, 0x0a /* Public */,
      16,    2,   96,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x0a /* Public */,
      19,    0,  102,    2, 0x0a /* Public */,
      20,    0,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,    5,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 17,    8,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QGBA::KeyEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KeyEditor *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->axisChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->hatChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->setValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->setValueKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setValueButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->setValueAxis((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GamepadAxisEvent::Direction(*)>(_a[2]))); break;
        case 7: _t->setValueHat((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< GamepadHatEvent::Direction(*)>(_a[2]))); break;
        case 8: _t->clearButton(); break;
        case 9: _t->clearAxis(); break;
        case 10: _t->clearHat(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KeyEditor::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyEditor::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KeyEditor::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyEditor::axisChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KeyEditor::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KeyEditor::hatChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::KeyEditor::staticMetaObject = { {
    QMetaObject::SuperData::link<QLineEdit::staticMetaObject>(),
    qt_meta_stringdata_QGBA__KeyEditor.data,
    qt_meta_data_QGBA__KeyEditor,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::KeyEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::KeyEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__KeyEditor.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int QGBA::KeyEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QGBA::KeyEditor::valueChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::KeyEditor::axisChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::KeyEditor::hatChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
