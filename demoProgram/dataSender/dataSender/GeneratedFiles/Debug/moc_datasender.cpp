/****************************************************************************
** Meta object code from reading C++ file 'datasender.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../datasender.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datasender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_dataSender_t {
    QByteArrayData data[16];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataSender_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataSender_t qt_meta_stringdata_dataSender = {
    {
QT_MOC_LITERAL(0, 0, 10), // "dataSender"
QT_MOC_LITERAL(1, 11, 15), // "on_sub1_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "on_sub2_clicked"
QT_MOC_LITERAL(4, 44, 15), // "on_sub3_clicked"
QT_MOC_LITERAL(5, 60, 15), // "on_sub4_clicked"
QT_MOC_LITERAL(6, 76, 15), // "on_sub5_clicked"
QT_MOC_LITERAL(7, 92, 15), // "on_sub6_clicked"
QT_MOC_LITERAL(8, 108, 15), // "on_sub7_clicked"
QT_MOC_LITERAL(9, 124, 15), // "on_sub8_clicked"
QT_MOC_LITERAL(10, 140, 19), // "on_oneClass_clicked"
QT_MOC_LITERAL(11, 160, 19), // "on_twoClass_clicked"
QT_MOC_LITERAL(12, 180, 16), // "on_train_clicked"
QT_MOC_LITERAL(13, 197, 20), // "on_startSend_clicked"
QT_MOC_LITERAL(14, 218, 19), // "on_stopSend_clicked"
QT_MOC_LITERAL(15, 238, 15) // "on_exit_clicked"

    },
    "dataSender\0on_sub1_clicked\0\0on_sub2_clicked\0"
    "on_sub3_clicked\0on_sub4_clicked\0"
    "on_sub5_clicked\0on_sub6_clicked\0"
    "on_sub7_clicked\0on_sub8_clicked\0"
    "on_oneClass_clicked\0on_twoClass_clicked\0"
    "on_train_clicked\0on_startSend_clicked\0"
    "on_stopSend_clicked\0on_exit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataSender[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dataSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        dataSender *_t = static_cast<dataSender *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sub1_clicked(); break;
        case 1: _t->on_sub2_clicked(); break;
        case 2: _t->on_sub3_clicked(); break;
        case 3: _t->on_sub4_clicked(); break;
        case 4: _t->on_sub5_clicked(); break;
        case 5: _t->on_sub6_clicked(); break;
        case 6: _t->on_sub7_clicked(); break;
        case 7: _t->on_sub8_clicked(); break;
        case 8: _t->on_oneClass_clicked(); break;
        case 9: _t->on_twoClass_clicked(); break;
        case 10: _t->on_train_clicked(); break;
        case 11: _t->on_startSend_clicked(); break;
        case 12: _t->on_stopSend_clicked(); break;
        case 13: _t->on_exit_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject dataSender::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_dataSender.data,
      qt_meta_data_dataSender,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *dataSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataSender::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_dataSender.stringdata0))
        return static_cast<void*>(const_cast< dataSender*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int dataSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
