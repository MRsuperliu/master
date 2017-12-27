/********************************************************************************
** Form generated from reading UI file 'renameimagefolder.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEIMAGEFOLDER_H
#define UI_RENAMEIMAGEFOLDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RenameImageFolderClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *lineEdit_sourceFolder;
    QLineEdit *lineEdit_nameFilter;
    QPushButton *pushButton_browseSourceFolder;
    QPushButton *pushButton_execute;
    QLabel *label_3;
    QComboBox *comboBox_fileType;
    QCheckBox *checkBox_addNum;
    QCheckBox *checkBox_addTime;
    QPushButton *pushButton_undo;
    QLabel *label_4;
    QLineEdit *lineEdit_destFilter;
    QCheckBox *checkBox_folderOnly;

    void setupUi(QDialog *RenameImageFolderClass)
    {
        if (RenameImageFolderClass->objectName().isEmpty())
            RenameImageFolderClass->setObjectName(QString::fromUtf8("RenameImageFolderClass"));
        RenameImageFolderClass->resize(480, 300);
        horizontalLayout = new QHBoxLayout(RenameImageFolderClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(RenameImageFolderClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 90, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 90, 20));
        lineEdit_sourceFolder = new QLineEdit(groupBox);
        lineEdit_sourceFolder->setObjectName(QString::fromUtf8("lineEdit_sourceFolder"));
        lineEdit_sourceFolder->setGeometry(QRect(110, 20, 240, 20));
        lineEdit_nameFilter = new QLineEdit(groupBox);
        lineEdit_nameFilter->setObjectName(QString::fromUtf8("lineEdit_nameFilter"));
        lineEdit_nameFilter->setGeometry(QRect(110, 50, 240, 20));
        pushButton_browseSourceFolder = new QPushButton(groupBox);
        pushButton_browseSourceFolder->setObjectName(QString::fromUtf8("pushButton_browseSourceFolder"));
        pushButton_browseSourceFolder->setGeometry(QRect(360, 20, 70, 20));
        pushButton_execute = new QPushButton(groupBox);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));
        pushButton_execute->setGeometry(QRect(270, 180, 75, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 90, 20));
        comboBox_fileType = new QComboBox(groupBox);
        comboBox_fileType->setObjectName(QString::fromUtf8("comboBox_fileType"));
        comboBox_fileType->setGeometry(QRect(110, 110, 240, 20));
        checkBox_addNum = new QCheckBox(groupBox);
        checkBox_addNum->setObjectName(QString::fromUtf8("checkBox_addNum"));
        checkBox_addNum->setGeometry(QRect(360, 50, 70, 20));
        checkBox_addTime = new QCheckBox(groupBox);
        checkBox_addTime->setObjectName(QString::fromUtf8("checkBox_addTime"));
        checkBox_addTime->setGeometry(QRect(360, 80, 70, 20));
        pushButton_undo = new QPushButton(groupBox);
        pushButton_undo->setObjectName(QString::fromUtf8("pushButton_undo"));
        pushButton_undo->setGeometry(QRect(370, 180, 75, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 80, 90, 20));
        lineEdit_destFilter = new QLineEdit(groupBox);
        lineEdit_destFilter->setObjectName(QString::fromUtf8("lineEdit_destFilter"));
        lineEdit_destFilter->setGeometry(QRect(110, 80, 240, 20));
        checkBox_folderOnly = new QCheckBox(groupBox);
        checkBox_folderOnly->setObjectName(QString::fromUtf8("checkBox_folderOnly"));
        checkBox_folderOnly->setGeometry(QRect(360, 110, 90, 20));

        horizontalLayout->addWidget(groupBox);


        retranslateUi(RenameImageFolderClass);

        QMetaObject::connectSlotsByName(RenameImageFolderClass);
    } // setupUi

    void retranslateUi(QDialog *RenameImageFolderClass)
    {
        RenameImageFolderClass->setWindowTitle(QApplication::translate("RenameImageFolderClass", "RenameImageFolder", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RenameImageFolderClass", "renameImageFolder", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RenameImageFolderClass", "Name Filter:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RenameImageFolderClass", "Source Folder:", 0, QApplication::UnicodeUTF8));
        pushButton_browseSourceFolder->setText(QApplication::translate("RenameImageFolderClass", "Browse...", 0, QApplication::UnicodeUTF8));
        pushButton_execute->setText(QApplication::translate("RenameImageFolderClass", "Execute", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RenameImageFolderClass", "FileType:", 0, QApplication::UnicodeUTF8));
        checkBox_addNum->setText(QApplication::translate("RenameImageFolderClass", "Add Num", 0, QApplication::UnicodeUTF8));
        checkBox_addTime->setText(QApplication::translate("RenameImageFolderClass", "Add Time", 0, QApplication::UnicodeUTF8));
        pushButton_undo->setText(QApplication::translate("RenameImageFolderClass", "Undo", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RenameImageFolderClass", "Dest Filter:", 0, QApplication::UnicodeUTF8));
        checkBox_folderOnly->setText(QApplication::translate("RenameImageFolderClass", "Folder Only", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RenameImageFolderClass: public Ui_RenameImageFolderClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEIMAGEFOLDER_H
