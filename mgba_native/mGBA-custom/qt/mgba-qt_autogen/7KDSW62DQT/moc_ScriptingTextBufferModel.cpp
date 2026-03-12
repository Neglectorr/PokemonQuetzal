/****************************************************************************
** Meta object code from reading C++ file 'ScriptingTextBufferModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/scripting/ScriptingTextBufferModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptingTextBufferModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ScriptingTextBufferModel_t {
    QByteArrayData data[6];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ScriptingTextBufferModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ScriptingTextBufferModel_t qt_meta_stringdata_QGBA__ScriptingTextBufferModel = {
    {
QT_MOC_LITERAL(0, 0, 30), // "QGBA::ScriptingTextBufferModel"
QT_MOC_LITERAL(1, 31, 17), // "textBufferCreated"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 20), // "ScriptingTextBuffer*"
QT_MOC_LITERAL(4, 71, 5), // "reset"
QT_MOC_LITERAL(5, 77, 17) // "bufferNameChanged"

    },
    "QGBA::ScriptingTextBufferModel\0"
    "textBufferCreated\0\0ScriptingTextBuffer*\0"
    "reset\0bufferNameChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ScriptingTextBufferModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x0a /* Public */,
       5,    1,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void QGBA::ScriptingTextBufferModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptingTextBufferModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->textBufferCreated((*reinterpret_cast< ScriptingTextBuffer*(*)>(_a[1]))); break;
        case 1: _t->reset(); break;
        case 2: _t->bufferNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptingTextBufferModel::*)(ScriptingTextBuffer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingTextBufferModel::textBufferCreated)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ScriptingTextBufferModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ScriptingTextBufferModel.data,
    qt_meta_data_QGBA__ScriptingTextBufferModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ScriptingTextBufferModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ScriptingTextBufferModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ScriptingTextBufferModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int QGBA::ScriptingTextBufferModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QGBA::ScriptingTextBufferModel::textBufferCreated(ScriptingTextBuffer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
