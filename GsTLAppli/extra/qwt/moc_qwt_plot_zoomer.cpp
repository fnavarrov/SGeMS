/****************************************************************************
** Meta object code from reading C++ file 'qwt_plot_zoomer.h'
**
** Created: Sun Nov 1 16:37:15 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qwt_plot_zoomer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qwt_plot_zoomer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QwtPlotZoomer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      46,   42,   14,   14, 0x0a,
      68,   42,   14,   14, 0x0a,
      88,   14,   14,   14, 0x0a,
     111,  108,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QwtPlotZoomer[] = {
    "QwtPlotZoomer\0\0rect\0zoomed(QwtDoubleRect)\0"
    "x,y\0moveBy(double,double)\0move(double,double)\0"
    "zoom(QwtDoubleRect)\0up\0zoom(int)\0"
};

const QMetaObject QwtPlotZoomer::staticMetaObject = {
    { &QwtPlotPicker::staticMetaObject, qt_meta_stringdata_QwtPlotZoomer,
      qt_meta_data_QwtPlotZoomer, 0 }
};

const QMetaObject *QwtPlotZoomer::metaObject() const
{
    return &staticMetaObject;
}

void *QwtPlotZoomer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QwtPlotZoomer))
        return static_cast<void*>(const_cast< QwtPlotZoomer*>(this));
    return QwtPlotPicker::qt_metacast(_clname);
}

int QwtPlotZoomer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QwtPlotPicker::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: zoomed((*reinterpret_cast< const QwtDoubleRect(*)>(_a[1]))); break;
        case 1: moveBy((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: move((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: zoom((*reinterpret_cast< const QwtDoubleRect(*)>(_a[1]))); break;
        case 4: zoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QwtPlotZoomer::zoomed(const QwtDoubleRect & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
