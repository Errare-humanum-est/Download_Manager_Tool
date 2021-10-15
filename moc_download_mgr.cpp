/****************************************************************************
** Meta object code from reading C++ file 'download_mgr.h'
**
** Created: Thu Jul 3 12:24:54 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "download_mgr.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'download_mgr.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_download_mgr[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      43,   13,   13,   13, 0x08,
      59,   13,   13,   13, 0x08,
      81,   76,   13,   13, 0x08,
     118,   13,   13,   13, 0x08,
     150,   76,   13,   13, 0x08,
     182,   13,   13,   13, 0x08,
     206,   13,   13,   13, 0x08,
     240,   13,   13,   13, 0x08,
     287,  277,  269,   13, 0x08,
     319,   13,  312,   13, 0x08,
     347,  335,  312,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_download_mgr[] = {
    "download_mgr\0\0on_Check_Server_IP_clicked()\0"
    "TCP_Read_Data()\0update_Console()\0arg1\0"
    "on_Console_refresh_valueChanged(int)\0"
    "on_int_limits_editingFinished()\0"
    "on_int_limits_valueChanged(int)\0"
    "on_pushButton_clicked()\0"
    "on_command_line_editingFinished()\0"
    "on_Rate_adaptation_clicked()\0quint64\0"
    "data_rate\0bw_quality_match(double)\0"
    "double\0avg_data_rate()\0avg_bitrate\0"
    "logarithmic_processor(double)\0"
};

void download_mgr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        download_mgr *_t = static_cast<download_mgr *>(_o);
        switch (_id) {
        case 0: _t->on_Check_Server_IP_clicked(); break;
        case 1: _t->TCP_Read_Data(); break;
        case 2: _t->update_Console(); break;
        case 3: _t->on_Console_refresh_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_int_limits_editingFinished(); break;
        case 5: _t->on_int_limits_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_command_line_editingFinished(); break;
        case 8: _t->on_Rate_adaptation_clicked(); break;
        case 9: { quint64 _r = _t->bw_quality_match((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint64*>(_a[0]) = _r; }  break;
        case 10: { double _r = _t->avg_data_rate();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 11: { double _r = _t->logarithmic_processor((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData download_mgr::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject download_mgr::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_download_mgr,
      qt_meta_data_download_mgr, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &download_mgr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *download_mgr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *download_mgr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_download_mgr))
        return static_cast<void*>(const_cast< download_mgr*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int download_mgr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
