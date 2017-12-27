/****************************************************************************
** Meta object code from reading C++ file 'renameimagefolder.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../renameimagefolder.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renameimagefolder.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RenameImageFolder[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   19,   18,   18, 0x0a,
      74,   63,   18,   18, 0x0a,
     103,   63,   18,   18, 0x0a,
     138,  132,   18,   18, 0x0a,
     161,   18,   18,   18, 0x0a,
     172,   18,   18,   18, 0x0a,
     184,   18,   18,   18, 0x0a,
     199,   18,   18,   18, 0x0a,
     220,   18,   18,   18, 0x0a,
     232,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RenameImageFolder[] = {
    "RenameImageFolder\0\0sourceFolder\0"
    "onSourceFolderChanged(QString)\0"
    "nameFilter\0onNameFilterChanged(QString)\0"
    "onDestFilterChanged(QString)\0index\0"
    "onFileTypeChanged(int)\0onAddNum()\0"
    "onAddTime()\0onFolderOnly()\0"
    "onBrowseSourFolder()\0onExecute()\0"
    "onUndo()\0"
};

void RenameImageFolder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RenameImageFolder *_t = static_cast<RenameImageFolder *>(_o);
        switch (_id) {
        case 0: _t->onSourceFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onNameFilterChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onDestFilterChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onFileTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onAddNum(); break;
        case 5: _t->onAddTime(); break;
        case 6: _t->onFolderOnly(); break;
        case 7: _t->onBrowseSourFolder(); break;
        case 8: _t->onExecute(); break;
        case 9: _t->onUndo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RenameImageFolder::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RenameImageFolder::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RenameImageFolder,
      qt_meta_data_RenameImageFolder, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RenameImageFolder::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RenameImageFolder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RenameImageFolder::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RenameImageFolder))
        return static_cast<void*>(const_cast< RenameImageFolder*>(this));
    return QDialog::qt_metacast(_clname);
}

int RenameImageFolder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
