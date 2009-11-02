/****************************************************************************
** Meta object code from reading C++ file 'qwt_plot_panner.h'
**
** Created: Sun Aug 23 17:13:52 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qwt_plot_panner.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_plot_panner.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwtPlotPanner[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   15,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_QwtPlotPanner[] = {
    "QwtPlotPanner\0\0dx,dy\0moveCanvas(int,int)\0"
};

const QMetaObject QwtPlotPanner::staticMetaObject = {
    { &QwtPanner::staticMetaObject, qt_meta_stringdata_QwtPlotPanner,
      qt_meta_data_QwtPlotPanner, 0 }
};

const QMetaObject *QwtPlotPanner::metaObject() const
{
    return &staticMetaObject;
}

void *QwtPlotPanner::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtPlotPanner))
        return static_cast<void*>(const_cast< QwtPlotPanner*>(this));
    return QwtPanner::qt_metacast(_clname);
}

int QwtPlotPanner::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPanner::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: moveCanvas((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
