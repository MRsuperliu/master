/****************************************************************************
** Meta object code from reading C++ file 'moveimagefile.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../moveimagefile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'moveimagefile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MoveImageFile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      28,   15,   14,   14, 0x0a,
      70,   59,   14,   14, 0x0a,
     105,   99,   14,   14, 0x0a,
     128,   14,   14,   14, 0x0a,
     147,   14,   14,   14, 0x0a,
     168,   14,   14,   14, 0x0a,
     189,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MoveImageFile[] = {
    "MoveImageFile\0\0sourceFolder\0"
    "onSourceFolderChanged(QString)\0"
    "DestFolser\0onDestFolderChanged(QString)\0"
    "index\0onFileTypeChanged(int)\0"
    "onOriginalFolder()\0onBrowseSourFolder()\0"
    "onBrowseDestFolder()\0onExecute()\0"
};

void MoveImageFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MoveImageFile *_t = static_cast<MoveImageFile *>(_o);
        switch (_id) {
        case 0: _t->onSourceFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onDestFolderChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->onFileTypeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onOriginalFolder(); break;
        case 4: _t->onBrowseSourFolder(); break;
        case 5: _t->onBrowseDestFolder(); break;
        case 6: _t->onExecute(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MoveImageFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MoveImageFile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MoveImageFile,
      qt_meta_data_MoveImageFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MoveImageFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MoveImageFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MoveImageFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MoveImageFile))
        return static_cast<void*>(const_cast< MoveImageFile*>(this));
    return QDialog::qt_metacast(_clname);
}

int MoveImageFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
