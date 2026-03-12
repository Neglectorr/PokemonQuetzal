/****************************************************************************
** Meta object code from reading C++ file 'ShaderSelector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/ShaderSelector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ShaderSelector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ShaderSelector_t {
    QByteArrayData data[16];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ShaderSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ShaderSelector_t qt_meta_stringdata_QGBA__ShaderSelector = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QGBA::ShaderSelector"
QT_MOC_LITERAL(1, 21, 21), // "saveSettingsRequested"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 5), // "reset"
QT_MOC_LITERAL(4, 50, 14), // "resetToDefault"
QT_MOC_LITERAL(5, 65, 12), // "saveSettings"
QT_MOC_LITERAL(6, 78, 14), // "refreshShaders"
QT_MOC_LITERAL(7, 93, 5), // "clear"
QT_MOC_LITERAL(8, 99, 6), // "revert"
QT_MOC_LITERAL(9, 106, 12), // "selectShader"
QT_MOC_LITERAL(10, 119, 10), // "loadShader"
QT_MOC_LITERAL(11, 130, 4), // "path"
QT_MOC_LITERAL(12, 135, 14), // "saveToSettings"
QT_MOC_LITERAL(13, 150, 11), // "clearShader"
QT_MOC_LITERAL(14, 162, 13), // "buttonPressed"
QT_MOC_LITERAL(15, 176, 16) // "QAbstractButton*"

    },
    "QGBA::ShaderSelector\0saveSettingsRequested\0"
    "\0reset\0resetToDefault\0saveSettings\0"
    "refreshShaders\0clear\0revert\0selectShader\0"
    "loadShader\0path\0saveToSettings\0"
    "clearShader\0buttonPressed\0QAbstractButton*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ShaderSelector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   82,    2, 0x0a /* Public */,
       6,    0,   83,    2, 0x0a /* Public */,
       7,    0,   84,    2, 0x0a /* Public */,
       8,    0,   85,    2, 0x0a /* Public */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    2,   87,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x28 /* Private | MethodCloned */,
      13,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x28 /* Private | MethodCloned */,
      14,    1,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,   12,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::Bool,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,

       0        // eod
};

void QGBA::ShaderSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ShaderSelector *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveSettingsRequested(); break;
        case 1: _t->reset(); break;
        case 2: _t->resetToDefault(); break;
        case 3: _t->saveSettings(); break;
        case 4: _t->refreshShaders(); break;
        case 5: _t->clear(); break;
        case 6: _t->revert(); break;
        case 7: _t->selectShader(); break;
        case 8: _t->loadShader((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->loadShader((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->clearShader((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->clearShader(); break;
        case 12: _t->buttonPressed((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ShaderSelector::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShaderSelector::saveSettingsRequested)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ShaderSelector::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShaderSelector::reset)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ShaderSelector::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ShaderSelector::resetToDefault)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ShaderSelector::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ShaderSelector.data,
    qt_meta_data_QGBA__ShaderSelector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ShaderSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ShaderSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ShaderSelector.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int QGBA::ShaderSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QGBA::ShaderSelector::saveSettingsRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::ShaderSelector::reset()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGBA::ShaderSelector::resetToDefault()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
