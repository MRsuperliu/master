/****************************************************************************
** Meta object code from reading C++ file 'renameimagefile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../renameimagefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renameimagefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RenameImageFile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   17,   16,   16, 0x0a,
      72,   61,   16,   16, 0x0a,
     116,  101,   16,   16, 0x0a,
     162,  149,   16,   16, 0x0a,
     199,  193,   16,   16, 0x0a,
     222,   16,   16,   16, 0x0a,
     243,   16,   16,   16, 0x0a,
     264,   16,   16,   16, 0x0a,
     279,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RenameImageFile[] = {
    "RenameImageFile\0\0sourceFolder\0"
    "onSourceFolderChanged(QString)\0"
    "DestFolser\0onDestFolderChanged(QString)\0"
    "sourceFileName\0onSourceFileNameChanged(QString)\0"
    "destFileName\0onDestFileNameChanged(QString)\0"
    "index\0onFileTypeChanged(int)\0"
    "onBrowseSourFolder()\0onBrowseDestFolder()\0"
    "onSelfFolder()\0onExecute()\0"
};

void RenameImageFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RenameImageFile *_t = static_cast<RenameImageFile *>(_o);
        switch (_id) {
        case 0: _t->onSourceFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onDestFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onSourceFileNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->onDestFileNameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onFileTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onBrowseSourFolder(); break;
        case 6: _t->onBrowseDestFolder(); break;
        case 7: _t->onSelfFolder(); break;
        case 8: _t->onExecute(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RenameImageFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RenameImageFile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RenameImageFile,
      qt_meta_data_RenameImageFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RenameImageFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RenameImageFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RenameImageFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RenameImageFile))
        return static_cast<void*>(const_cast< RenameImageFile*>(this));
    return QDialog::qt_metacast(_clname);
}

int RenameImageFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
