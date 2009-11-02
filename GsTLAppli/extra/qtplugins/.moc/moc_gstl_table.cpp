/****************************************************************************
** Meta object code from reading C++ file 'gstl_table.h'
**
** Created: Sun Nov 1 20:45:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../gstl_table.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gstl_table.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GsTLTable[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       3,   22, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,   11,   10,   10, 0x0a,
      29,   11,   10,   10, 0x0a,

 // properties: name, type, flags
      49,   45, 0x02095003,
      77,   69, 0x0a095003,
      89,   69, 0x0a095003,

       0        // eod
};

static const char qt_meta_stringdata_GsTLTable[] = {
    "GsTLTable\0\0n\0setNumRows(int)\0"
    "setNumCols(int)\0int\0default_column_size\0"
    "QString\0row_headers\0col_headers\0"
};

const QMetaObject GsTLTable::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_GsTLTable,
      qt_meta_data_GsTLTable, 0 }
};

const QMetaObject *GsTLTable::metaObject() const
{
    return &staticMetaObject;
}

void *GsTLTable::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GsTLTable))
        return static_cast<void*>(const_cast< GsTLTable*>(this));
    return QTableWidget::qt_metacast(_clname);
}

int GsTLTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setNumRows((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: setNumCols((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = defaultColsize(); break;
        case 1: *reinterpret_cast< QString*>(_v) = rowHeaders(); break;
        case 2: *reinterpret_cast< QString*>(_v) = colHeaders(); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setDefaultColsize(*reinterpret_cast< int*>(_v)); break;
        case 1: setRowHeaders(*reinterpret_cast< QString*>(_v)); break;
        case 2: setColHeaders(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 3;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
