/****************************************************************************
** Meta object code from reading C++ file 'MemoryAccessLogView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/MemoryAccessLogView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MemoryAccessLogView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__MemoryAccessLogView_t {
    QByteArrayData data[13];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__MemoryAccessLogView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__MemoryAccessLogView_t qt_meta_stringdata_QGBA__MemoryAccessLogView = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QGBA::MemoryAccessLogView"
QT_MOC_LITERAL(1, 26, 12), // "updateRegion"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 12), // "internalName"
QT_MOC_LITERAL(4, 53, 6), // "enable"
QT_MOC_LITERAL(5, 60, 10), // "selectFile"
QT_MOC_LITERAL(6, 71, 5), // "start"
QT_MOC_LITERAL(7, 77, 4), // "stop"
QT_MOC_LITERAL(8, 82, 4), // "load"
QT_MOC_LITERAL(9, 87, 6), // "unload"
QT_MOC_LITERAL(10, 94, 10), // "exportFile"
QT_MOC_LITERAL(11, 105, 15), // "handleStartStop"
QT_MOC_LITERAL(12, 121, 16) // "handleLoadUnload"

    },
    "QGBA::MemoryAccessLogView\0updateRegion\0"
    "\0internalName\0enable\0selectFile\0start\0"
    "stop\0load\0unload\0exportFile\0handleStartStop\0"
    "handleLoadUnload"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__MemoryAccessLogView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x08 /* Private */,
       5,    0,   64,    2, 0x08 /* Private */,
       6,    0,   65,    2, 0x08 /* Private */,
       7,    0,   66,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    1,   70,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Bool,    8,

       0        // eod
};

void QGBA::MemoryAccessLogView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MemoryAccessLogView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateRegion((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->selectFile(); break;
        case 2: _t->start(); break;
        case 3: _t->stop(); break;
        case 4: _t->load(); break;
        case 5: _t->unload(); break;
        case 6: _t->exportFile(); break;
        case 7: _t->handleStartStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->handleLoadUnload((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::MemoryAccessLogView::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QGBA__MemoryAccessLogView.data,
    qt_meta_data_QGBA__MemoryAccessLogView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::MemoryAccessLogView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::MemoryAccessLogView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__MemoryAccessLogView.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QGBA::MemoryAccessLogView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
