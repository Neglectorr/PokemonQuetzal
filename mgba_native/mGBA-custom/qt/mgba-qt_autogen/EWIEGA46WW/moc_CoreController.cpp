/****************************************************************************
** Meta object code from reading C++ file 'CoreController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.18)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/platform/qt/CoreController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoreController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.18. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGBA__CoreController_t {
    QByteArrayData data[94];
    char stringdata0[1009];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGBA__CoreController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGBA__CoreController_t qt_meta_stringdata_QGBA__CoreController = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QGBA::CoreController"
QT_MOC_LITERAL(1, 21, 7), // "started"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "paused"
QT_MOC_LITERAL(4, 37, 8), // "unpaused"
QT_MOC_LITERAL(5, 46, 8), // "stopping"
QT_MOC_LITERAL(6, 55, 7), // "crashed"
QT_MOC_LITERAL(7, 63, 12), // "errorMessage"
QT_MOC_LITERAL(8, 76, 6), // "failed"
QT_MOC_LITERAL(9, 83, 14), // "frameAvailable"
QT_MOC_LITERAL(10, 98, 8), // "didReset"
QT_MOC_LITERAL(11, 107, 11), // "stateLoaded"
QT_MOC_LITERAL(12, 119, 7), // "rewound"
QT_MOC_LITERAL(13, 127, 13), // "rewindChanged"
QT_MOC_LITERAL(14, 141, 18), // "fastForwardChanged"
QT_MOC_LITERAL(15, 160, 21), // "unimplementedBiosCall"
QT_MOC_LITERAL(16, 182, 12), // "statusPosted"
QT_MOC_LITERAL(17, 195, 7), // "message"
QT_MOC_LITERAL(18, 203, 9), // "logPosted"
QT_MOC_LITERAL(19, 213, 5), // "level"
QT_MOC_LITERAL(20, 219, 8), // "category"
QT_MOC_LITERAL(21, 228, 3), // "log"
QT_MOC_LITERAL(22, 232, 12), // "imagePrinted"
QT_MOC_LITERAL(23, 245, 5), // "start"
QT_MOC_LITERAL(24, 251, 4), // "stop"
QT_MOC_LITERAL(25, 256, 5), // "reset"
QT_MOC_LITERAL(26, 262, 9), // "setPaused"
QT_MOC_LITERAL(27, 272, 12), // "frameAdvance"
QT_MOC_LITERAL(28, 285, 7), // "setSync"
QT_MOC_LITERAL(29, 293, 6), // "enable"
QT_MOC_LITERAL(30, 300, 13), // "showResetInfo"
QT_MOC_LITERAL(31, 314, 12), // "setRewinding"
QT_MOC_LITERAL(32, 327, 6), // "rewind"
QT_MOC_LITERAL(33, 334, 5), // "count"
QT_MOC_LITERAL(34, 340, 14), // "setFastForward"
QT_MOC_LITERAL(35, 355, 16), // "forceFastForward"
QT_MOC_LITERAL(36, 372, 12), // "changePlayer"
QT_MOC_LITERAL(37, 385, 2), // "id"
QT_MOC_LITERAL(38, 388, 12), // "overrideMute"
QT_MOC_LITERAL(39, 401, 9), // "loadState"
QT_MOC_LITERAL(40, 411, 4), // "slot"
QT_MOC_LITERAL(41, 416, 4), // "path"
QT_MOC_LITERAL(42, 421, 5), // "flags"
QT_MOC_LITERAL(43, 427, 10), // "QIODevice*"
QT_MOC_LITERAL(44, 438, 5), // "iodev"
QT_MOC_LITERAL(45, 444, 9), // "saveState"
QT_MOC_LITERAL(46, 454, 15), // "loadBackupState"
QT_MOC_LITERAL(47, 470, 15), // "saveBackupState"
QT_MOC_LITERAL(48, 486, 8), // "loadSave"
QT_MOC_LITERAL(49, 495, 9), // "temporary"
QT_MOC_LITERAL(50, 505, 6), // "VFile*"
QT_MOC_LITERAL(51, 512, 9), // "loadPatch"
QT_MOC_LITERAL(52, 522, 8), // "scanCard"
QT_MOC_LITERAL(53, 531, 9), // "scanCards"
QT_MOC_LITERAL(54, 541, 11), // "replaceGame"
QT_MOC_LITERAL(55, 553, 7), // "yankPak"
QT_MOC_LITERAL(56, 561, 9), // "blockSave"
QT_MOC_LITERAL(57, 571, 6), // "addKey"
QT_MOC_LITERAL(58, 578, 3), // "key"
QT_MOC_LITERAL(59, 582, 8), // "clearKey"
QT_MOC_LITERAL(60, 591, 11), // "setAutofire"
QT_MOC_LITERAL(61, 603, 10), // "screenshot"
QT_MOC_LITERAL(62, 614, 11), // "setRealTime"
QT_MOC_LITERAL(63, 626, 12), // "setFixedTime"
QT_MOC_LITERAL(64, 639, 4), // "time"
QT_MOC_LITERAL(65, 644, 12), // "setFakeEpoch"
QT_MOC_LITERAL(66, 657, 13), // "setTimeOffset"
QT_MOC_LITERAL(67, 671, 6), // "offset"
QT_MOC_LITERAL(68, 678, 15), // "importSharkport"
QT_MOC_LITERAL(69, 694, 15), // "exportSharkport"
QT_MOC_LITERAL(70, 710, 13), // "attachPrinter"
QT_MOC_LITERAL(71, 724, 13), // "detachPrinter"
QT_MOC_LITERAL(72, 738, 8), // "endPrint"
QT_MOC_LITERAL(73, 747, 20), // "attachBattleChipGate"
QT_MOC_LITERAL(74, 768, 20), // "detachBattleChipGate"
QT_MOC_LITERAL(75, 789, 15), // "setBattleChipId"
QT_MOC_LITERAL(76, 805, 8), // "uint16_t"
QT_MOC_LITERAL(77, 814, 19), // "setBattleChipFlavor"
QT_MOC_LITERAL(78, 834, 6), // "flavor"
QT_MOC_LITERAL(79, 841, 13), // "attachDolphin"
QT_MOC_LITERAL(80, 855, 7), // "Address"
QT_MOC_LITERAL(81, 863, 7), // "address"
QT_MOC_LITERAL(82, 871, 13), // "detachDolphin"
QT_MOC_LITERAL(83, 885, 11), // "setAVStream"
QT_MOC_LITERAL(84, 897, 10), // "mAVStream*"
QT_MOC_LITERAL(85, 908, 13), // "clearAVStream"
QT_MOC_LITERAL(86, 922, 13), // "clearOverride"
QT_MOC_LITERAL(87, 936, 13), // "startVideoLog"
QT_MOC_LITERAL(88, 950, 11), // "compression"
QT_MOC_LITERAL(89, 962, 2), // "vf"
QT_MOC_LITERAL(90, 965, 11), // "endVideoLog"
QT_MOC_LITERAL(91, 977, 7), // "closeVf"
QT_MOC_LITERAL(92, 985, 20), // "setFramebufferHandle"
QT_MOC_LITERAL(93, 1006, 2) // "fb"

    },
    "QGBA::CoreController\0started\0\0paused\0"
    "unpaused\0stopping\0crashed\0errorMessage\0"
    "failed\0frameAvailable\0didReset\0"
    "stateLoaded\0rewound\0rewindChanged\0"
    "fastForwardChanged\0unimplementedBiosCall\0"
    "statusPosted\0message\0logPosted\0level\0"
    "category\0log\0imagePrinted\0start\0stop\0"
    "reset\0setPaused\0frameAdvance\0setSync\0"
    "enable\0showResetInfo\0setRewinding\0"
    "rewind\0count\0setFastForward\0"
    "forceFastForward\0changePlayer\0id\0"
    "overrideMute\0loadState\0slot\0path\0flags\0"
    "QIODevice*\0iodev\0saveState\0loadBackupState\0"
    "saveBackupState\0loadSave\0temporary\0"
    "VFile*\0loadPatch\0scanCard\0scanCards\0"
    "replaceGame\0yankPak\0blockSave\0addKey\0"
    "key\0clearKey\0setAutofire\0screenshot\0"
    "setRealTime\0setFixedTime\0time\0"
    "setFakeEpoch\0setTimeOffset\0offset\0"
    "importSharkport\0exportSharkport\0"
    "attachPrinter\0detachPrinter\0endPrint\0"
    "attachBattleChipGate\0detachBattleChipGate\0"
    "setBattleChipId\0uint16_t\0setBattleChipFlavor\0"
    "flavor\0attachDolphin\0Address\0address\0"
    "detachDolphin\0setAVStream\0mAVStream*\0"
    "clearAVStream\0clearOverride\0startVideoLog\0"
    "compression\0vf\0endVideoLog\0closeVf\0"
    "setFramebufferHandle\0fb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGBA__CoreController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      82,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      16,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  424,    2, 0x06 /* Public */,
       3,    0,  425,    2, 0x06 /* Public */,
       4,    0,  426,    2, 0x06 /* Public */,
       5,    0,  427,    2, 0x06 /* Public */,
       6,    1,  428,    2, 0x06 /* Public */,
       8,    0,  431,    2, 0x06 /* Public */,
       9,    0,  432,    2, 0x06 /* Public */,
      10,    0,  433,    2, 0x06 /* Public */,
      11,    0,  434,    2, 0x06 /* Public */,
      12,    0,  435,    2, 0x06 /* Public */,
      13,    1,  436,    2, 0x06 /* Public */,
      14,    1,  439,    2, 0x06 /* Public */,
      15,    1,  442,    2, 0x06 /* Public */,
      16,    1,  445,    2, 0x06 /* Public */,
      18,    3,  448,    2, 0x06 /* Public */,
      22,    1,  455,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      23,    0,  458,    2, 0x0a /* Public */,
      24,    0,  459,    2, 0x0a /* Public */,
      25,    0,  460,    2, 0x0a /* Public */,
      26,    1,  461,    2, 0x0a /* Public */,
      27,    0,  464,    2, 0x0a /* Public */,
      28,    1,  465,    2, 0x0a /* Public */,
      30,    1,  468,    2, 0x0a /* Public */,
      31,    1,  471,    2, 0x0a /* Public */,
      32,    1,  474,    2, 0x0a /* Public */,
      32,    0,  477,    2, 0x2a /* Public | MethodCloned */,
      34,    1,  478,    2, 0x0a /* Public */,
      35,    1,  481,    2, 0x0a /* Public */,
      36,    1,  484,    2, 0x0a /* Public */,
      38,    1,  487,    2, 0x0a /* Public */,
      39,    1,  490,    2, 0x0a /* Public */,
      39,    0,  493,    2, 0x2a /* Public | MethodCloned */,
      39,    2,  494,    2, 0x0a /* Public */,
      39,    1,  499,    2, 0x2a /* Public | MethodCloned */,
      39,    2,  502,    2, 0x0a /* Public */,
      39,    1,  507,    2, 0x2a /* Public | MethodCloned */,
      45,    1,  510,    2, 0x0a /* Public */,
      45,    0,  513,    2, 0x2a /* Public | MethodCloned */,
      45,    2,  514,    2, 0x0a /* Public */,
      45,    1,  519,    2, 0x2a /* Public | MethodCloned */,
      45,    2,  522,    2, 0x0a /* Public */,
      45,    1,  527,    2, 0x2a /* Public | MethodCloned */,
      46,    0,  530,    2, 0x0a /* Public */,
      47,    0,  531,    2, 0x0a /* Public */,
      48,    2,  532,    2, 0x0a /* Public */,
      48,    3,  537,    2, 0x0a /* Public */,
      48,    2,  544,    2, 0x2a /* Public | MethodCloned */,
      51,    1,  549,    2, 0x0a /* Public */,
      52,    1,  552,    2, 0x0a /* Public */,
      53,    1,  555,    2, 0x0a /* Public */,
      54,    1,  558,    2, 0x0a /* Public */,
      55,    0,  561,    2, 0x0a /* Public */,
      56,    0,  562,    2, 0x0a /* Public */,
      57,    1,  563,    2, 0x0a /* Public */,
      59,    1,  566,    2, 0x0a /* Public */,
      60,    2,  569,    2, 0x0a /* Public */,
      61,    0,  574,    2, 0x0a /* Public */,
      62,    0,  575,    2, 0x0a /* Public */,
      63,    1,  576,    2, 0x0a /* Public */,
      65,    1,  579,    2, 0x0a /* Public */,
      66,    1,  582,    2, 0x0a /* Public */,
      68,    1,  585,    2, 0x0a /* Public */,
      69,    1,  588,    2, 0x0a /* Public */,
      70,    0,  591,    2, 0x0a /* Public */,
      71,    0,  592,    2, 0x0a /* Public */,
      72,    0,  593,    2, 0x0a /* Public */,
      73,    0,  594,    2, 0x0a /* Public */,
      74,    0,  595,    2, 0x0a /* Public */,
      75,    1,  596,    2, 0x0a /* Public */,
      77,    1,  599,    2, 0x0a /* Public */,
      79,    1,  602,    2, 0x0a /* Public */,
      82,    0,  605,    2, 0x0a /* Public */,
      83,    1,  606,    2, 0x0a /* Public */,
      85,    0,  609,    2, 0x0a /* Public */,
      86,    0,  610,    2, 0x0a /* Public */,
      87,    2,  611,    2, 0x0a /* Public */,
      87,    1,  616,    2, 0x2a /* Public | MethodCloned */,
      87,    2,  619,    2, 0x0a /* Public */,
      87,    1,  624,    2, 0x2a /* Public | MethodCloned */,
      90,    1,  627,    2, 0x0a /* Public */,
      90,    0,  630,    2, 0x2a /* Public | MethodCloned */,
      92,    1,  631,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,   19,   20,   21,
    QMetaType::Void, QMetaType::QImage,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   37,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   41,   42,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int,   44,   42,
    QMetaType::Void, 0x80000000 | 43,   44,
    QMetaType::Void, QMetaType::Int,   40,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   41,   42,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, 0x80000000 | 43, QMetaType::Int,   44,   42,
    QMetaType::Void, 0x80000000 | 43,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,   49,
    QMetaType::Void, 0x80000000 | 50, QMetaType::Bool, QMetaType::QString,    2,   49,   41,
    QMetaType::Void, 0x80000000 | 50, QMetaType::Bool,    2,   49,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void, QMetaType::Int,   58,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   58,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,   64,
    QMetaType::Void, QMetaType::QDateTime,   64,
    QMetaType::Void, QMetaType::LongLong,   67,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 76,   37,
    QMetaType::Void, QMetaType::Int,   78,
    QMetaType::Bool, 0x80000000 | 80,   81,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 84,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   41,   88,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, 0x80000000 | 50, QMetaType::Bool,   89,   88,
    QMetaType::Void, 0x80000000 | 50,   89,
    QMetaType::Void, QMetaType::Bool,   91,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   93,

       0        // eod
};

void QGBA::CoreController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CoreController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->paused(); break;
        case 2: _t->unpaused(); break;
        case 3: _t->stopping(); break;
        case 4: _t->crashed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->failed(); break;
        case 6: _t->frameAvailable(); break;
        case 7: _t->didReset(); break;
        case 8: _t->stateLoaded(); break;
        case 9: _t->rewound(); break;
        case 10: _t->rewindChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->fastForwardChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->unimplementedBiosCall((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->statusPosted((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->logPosted((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 15: _t->imagePrinted((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 16: _t->start(); break;
        case 17: _t->stop(); break;
        case 18: _t->reset(); break;
        case 19: _t->setPaused((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->frameAdvance(); break;
        case 21: _t->setSync((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->showResetInfo((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setRewinding((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->rewind((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->rewind(); break;
        case 26: _t->setFastForward((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->forceFastForward((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->changePlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->overrideMute((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->loadState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->loadState(); break;
        case 32: _t->loadState((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->loadState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->loadState((*reinterpret_cast< QIODevice*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: _t->loadState((*reinterpret_cast< QIODevice*(*)>(_a[1]))); break;
        case 36: _t->saveState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->saveState(); break;
        case 38: _t->saveState((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 39: _t->saveState((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->saveState((*reinterpret_cast< QIODevice*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 41: _t->saveState((*reinterpret_cast< QIODevice*(*)>(_a[1]))); break;
        case 42: _t->loadBackupState(); break;
        case 43: _t->saveBackupState(); break;
        case 44: _t->loadSave((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 45: _t->loadSave((*reinterpret_cast< VFile*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 46: _t->loadSave((*reinterpret_cast< VFile*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 47: _t->loadPatch((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->scanCard((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->scanCards((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 50: _t->replaceGame((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->yankPak(); break;
        case 52: _t->blockSave(); break;
        case 53: _t->addKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 54: _t->clearKey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->setAutofire((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 56: _t->screenshot(); break;
        case 57: _t->setRealTime(); break;
        case 58: _t->setFixedTime((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 59: _t->setFakeEpoch((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 60: _t->setTimeOffset((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 61: _t->importSharkport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 62: _t->exportSharkport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 63: _t->attachPrinter(); break;
        case 64: _t->detachPrinter(); break;
        case 65: _t->endPrint(); break;
        case 66: _t->attachBattleChipGate(); break;
        case 67: _t->detachBattleChipGate(); break;
        case 68: _t->setBattleChipId((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 69: _t->setBattleChipFlavor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 70: { bool _r = _t->attachDolphin((*reinterpret_cast< const Address(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 71: _t->detachDolphin(); break;
        case 72: _t->setAVStream((*reinterpret_cast< mAVStream*(*)>(_a[1]))); break;
        case 73: _t->clearAVStream(); break;
        case 74: _t->clearOverride(); break;
        case 75: _t->startVideoLog((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 76: _t->startVideoLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 77: _t->startVideoLog((*reinterpret_cast< VFile*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 78: _t->startVideoLog((*reinterpret_cast< VFile*(*)>(_a[1]))); break;
        case 79: _t->endVideoLog((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 80: _t->endVideoLog(); break;
        case 81: _t->setFramebufferHandle((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 34:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 35:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 40:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        case 41:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QIODevice* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::started)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::paused)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::unpaused)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::stopping)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::crashed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::failed)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::frameAvailable)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::didReset)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::stateLoaded)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (CoreController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::rewound)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::rewindChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::fastForwardChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::unimplementedBiosCall)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::statusPosted)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(int , int , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::logPosted)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (CoreController::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CoreController::imagePrinted)) {
                *result = 15;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGBA::CoreController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGBA__CoreController.data,
    qt_meta_data_QGBA__CoreController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGBA::CoreController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGBA::CoreController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGBA__CoreController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGBA::CoreController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 82)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 82;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 82)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 82;
    }
    return _id;
}

// SIGNAL 0
void QGBA::CoreController::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGBA::CoreController::paused()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QGBA::CoreController::unpaused()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QGBA::CoreController::stopping()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void QGBA::CoreController::crashed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QGBA::CoreController::failed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QGBA::CoreController::frameAvailable()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QGBA::CoreController::didReset()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QGBA::CoreController::stateLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QGBA::CoreController::rewound()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void QGBA::CoreController::rewindChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void QGBA::CoreController::fastForwardChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void QGBA::CoreController::unimplementedBiosCall(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void QGBA::CoreController::statusPosted(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void QGBA::CoreController::logPosted(int _t1, int _t2, const QString & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void QGBA::CoreController::imagePrinted(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
