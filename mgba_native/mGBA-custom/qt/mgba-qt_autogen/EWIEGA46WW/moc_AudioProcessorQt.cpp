/****************************************************************************
** Meta object code from reading C++ file 'AudioProcessorQt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/AudioProcessorQt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AudioProcessorQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__AudioProcessorQt_t {
    QByteArrayData data[12];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__AudioProcessorQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__AudioProcessorQt_t qt_meta_stringdata_QGBA__AudioProcessorQt = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QGBA::AudioProcessorQt"
QT_MOC_LITERAL(1, 23, 8), // "setInput"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 31), // "std::shared_ptr<CoreController>"
QT_MOC_LITERAL(4, 65, 5), // "input"
QT_MOC_LITERAL(5, 71, 4), // "stop"
QT_MOC_LITERAL(6, 76, 5), // "start"
QT_MOC_LITERAL(7, 82, 5), // "pause"
QT_MOC_LITERAL(8, 88, 16), // "setBufferSamples"
QT_MOC_LITERAL(9, 105, 7), // "samples"
QT_MOC_LITERAL(10, 113, 22), // "inputParametersChanged"
QT_MOC_LITERAL(11, 136, 17) // "requestSampleRate"

    },
    "QGBA::AudioProcessorQt\0setInput\0\0"
    "std::shared_ptr<CoreController>\0input\0"
    "stop\0start\0pause\0setBufferSamples\0"
    "samples\0inputParametersChanged\0"
    "requestSampleRate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__AudioProcessorQt[] = {

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
       1,    1,   49,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    1,   55,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    2,

       0        // eod
};

void QGBA::AudioProcessorQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AudioProcessorQt *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setInput((*reinterpret_cast< std::shared_ptr<CoreController>(*)>(_a[1]))); break;
        case 1: _t->stop(); break;
        case 2: { bool _r = _t->start();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->pause(); break;
        case 4: _t->setBufferSamples((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->inputParametersChanged(); break;
        case 6: _t->requestSampleRate((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::AudioProcessorQt::staticMetaObject = { {
    QMetaObject::SuperData::link<AudioProcessor::staticMetaObject>(),
    qt_meta_stringdata_QGBA__AudioProcessorQt.data,
    qt_meta_data_QGBA__AudioProcessorQt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::AudioProcessorQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::AudioProcessorQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__AudioProcessorQt.stringdata0))
        return static_cast<void*>(this);
    return AudioProcessor::qt_metacast(_clname);
}

int QGBA::AudioProcessorQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AudioProcessor::qt_metacall(_c, _id, _a);
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
