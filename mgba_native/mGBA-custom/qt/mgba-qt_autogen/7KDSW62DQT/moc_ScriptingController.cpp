/****************************************************************************
** Meta object code from reading C++ file 'ScriptingController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/scripting/ScriptingController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ScriptingController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__ScriptingController_t {
    QByteArrayData data[21];
    char stringdata0[238];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__ScriptingController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__ScriptingController_t qt_meta_stringdata_QGBA__ScriptingController = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QGBA::ScriptingController"
QT_MOC_LITERAL(1, 26, 3), // "log"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "warn"
QT_MOC_LITERAL(4, 36, 5), // "error"
QT_MOC_LITERAL(5, 42, 17), // "textBufferCreated"
QT_MOC_LITERAL(6, 60, 20), // "ScriptingTextBuffer*"
QT_MOC_LITERAL(7, 81, 20), // "autorunScriptsOpened"
QT_MOC_LITERAL(8, 102, 8), // "QWidget*"
QT_MOC_LITERAL(9, 111, 4), // "view"
QT_MOC_LITERAL(10, 116, 15), // "clearController"
QT_MOC_LITERAL(11, 132, 16), // "updateVideoScale"
QT_MOC_LITERAL(12, 149, 5), // "reset"
QT_MOC_LITERAL(13, 155, 7), // "runCode"
QT_MOC_LITERAL(14, 163, 4), // "code"
QT_MOC_LITERAL(15, 168, 15), // "openAutorunEdit"
QT_MOC_LITERAL(16, 184, 12), // "flushStorage"
QT_MOC_LITERAL(17, 197, 13), // "updateGamepad"
QT_MOC_LITERAL(18, 211, 6), // "attach"
QT_MOC_LITERAL(19, 218, 11), // "saveAutorun"
QT_MOC_LITERAL(20, 230, 7) // "autorun"

    },
    "QGBA::ScriptingController\0log\0\0warn\0"
    "error\0textBufferCreated\0ScriptingTextBuffer*\0"
    "autorunScriptsOpened\0QWidget*\0view\0"
    "clearController\0updateVideoScale\0reset\0"
    "runCode\0code\0openAutorunEdit\0flushStorage\0"
    "updateGamepad\0attach\0saveAutorun\0"
    "autorun"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__ScriptingController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,
       7,    1,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   99,    2, 0x0a /* Public */,
      11,    0,  100,    2, 0x0a /* Public */,
      12,    0,  101,    2, 0x0a /* Public */,
      13,    1,  102,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,
      16,    0,  106,    2, 0x0a /* Public */,
      17,    0,  107,    2, 0x08 /* Private */,
      18,    0,  108,    2, 0x08 /* Private */,
      19,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,   20,

       0        // eod
};

void QGBA::ScriptingController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ScriptingController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->log((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->warn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->textBufferCreated((*reinterpret_cast< ScriptingTextBuffer*(*)>(_a[1]))); break;
        case 4: _t->autorunScriptsOpened((*reinterpret_cast< QWidget*(*)>(_a[1]))); break;
        case 5: _t->clearController(); break;
        case 6: _t->updateVideoScale(); break;
        case 7: _t->reset(); break;
        case 8: _t->runCode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->openAutorunEdit(); break;
        case 10: _t->flushStorage(); break;
        case 11: _t->updateGamepad(); break;
        case 12: _t->attach(); break;
        case 13: _t->saveAutorun((*reinterpret_cast< const QList<QVariant>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ScriptingController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingController::log)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ScriptingController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingController::warn)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ScriptingController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingController::error)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ScriptingController::*)(ScriptingTextBuffer * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingController::textBufferCreated)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ScriptingController::*)(QWidget * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ScriptingController::autorunScriptsOpened)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::ScriptingController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__ScriptingController.data,
    qt_meta_data_QGBA__ScriptingController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::ScriptingController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::ScriptingController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__ScriptingController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::ScriptingController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void QGBA::ScriptingController::log(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QGBA::ScriptingController::warn(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGBA::ScriptingController::error(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGBA::ScriptingController::textBufferCreated(ScriptingTextBuffer * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QGBA::ScriptingController::autorunScriptsOpened(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
