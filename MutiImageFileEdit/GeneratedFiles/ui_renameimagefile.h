/********************************************************************************
** Form generated from reading UI file 'renameimagefile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEIMAGEFILE_H
#define UI_RENAMEIMAGEFILE_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RenameImageFileClass
{
public:
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_sourceFolder;
    QLineEdit *lineEdit_destFolder;
    QPushButton *pushButton_sourceFolder;
    QPushButton *pushButton_destFolder;
    QCheckBox *checkBox_selfFolder;
    QPushButton *pushButton_execute;
    QLineEdit *lineEdit_destFileName;
    QLabel *label_3;
    QLineEdit *lineEdit_sourceFileName;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBox_fileType;
    QProgressBar *progressBar;

    void setupUi(QDialog *RenameImageFileClass)
    {
        if (RenameImageFileClass->objectName().isEmpty())
            RenameImageFileClass->setObjectName(QString::fromUtf8("RenameImageFileClass"));
        RenameImageFileClass->resize(480, 270);
        RenameImageFileClass->setMinimumSize(QSize(480, 270));
        RenameImageFileClass->setMaximumSize(QSize(480, 270));
        horizontalLayout = new QHBoxLayout(RenameImageFileClass);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(RenameImageFileClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 90, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 70, 90, 20));
        lineEdit_sourceFolder = new QLineEdit(groupBox);
        lineEdit_sourceFolder->setObjectName(QString::fromUtf8("lineEdit_sourceFolder"));
        lineEdit_sourceFolder->setGeometry(QRect(110, 30, 250, 20));
        lineEdit_destFolder = new QLineEdit(groupBox);
        lineEdit_destFolder->setObjectName(QString::fromUtf8("lineEdit_destFolder"));
        lineEdit_destFolder->setGeometry(QRect(110, 70, 250, 20));
        pushButton_sourceFolder = new QPushButton(groupBox);
        pushButton_sourceFolder->setObjectName(QString::fromUtf8("pushButton_sourceFolder"));
        pushButton_sourceFolder->setGeometry(QRect(370, 30, 75, 20));
        pushButton_destFolder = new QPushButton(groupBox);
        pushButton_destFolder->setObjectName(QString::fromUtf8("pushButton_destFolder"));
        pushButton_destFolder->setGeometry(QRect(370, 70, 75, 20));
        checkBox_selfFolder = new QCheckBox(groupBox);
        checkBox_selfFolder->setObjectName(QString::fromUtf8("checkBox_selfFolder"));
        checkBox_selfFolder->setGeometry(QRect(370, 150, 90, 20));
        pushButton_execute = new QPushButton(groupBox);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));
        pushButton_execute->setGeometry(QRect(340, 220, 75, 20));
        lineEdit_destFileName = new QLineEdit(groupBox);
        lineEdit_destFileName->setObjectName(QString::fromUtf8("lineEdit_destFileName"));
        lineEdit_destFileName->setGeometry(QRect(120, 150, 240, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 110, 100, 29));
        lineEdit_sourceFileName = new QLineEdit(groupBox);
        lineEdit_sourceFileName->setObjectName(QString::fromUtf8("lineEdit_sourceFileName"));
        lineEdit_sourceFileName->setGeometry(QRect(120, 120, 240, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 150, 100, 29));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 190, 100, 20));
        comboBox_fileType = new QComboBox(groupBox);
        comboBox_fileType->setObjectName(QString::fromUtf8("comboBox_fileType"));
        comboBox_fileType->setGeometry(QRect(120, 190, 240, 20));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(20, 220, 300, 20));
        progressBar->setValue(24);

        horizontalLayout->addWidget(groupBox);


        retranslateUi(RenameImageFileClass);

        QMetaObject::connectSlotsByName(RenameImageFileClass);
    } // setupUi

    void retranslateUi(QDialog *RenameImageFileClass)
    {
        RenameImageFileClass->setWindowTitle(QApplication::translate("RenameImageFileClass", "RenameImageFile", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RenameImageFileClass", "RenameImageFile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RenameImageFileClass", "Source Folder:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RenameImageFileClass", "Dest Folder:", 0, QApplication::UnicodeUTF8));
        pushButton_sourceFolder->setText(QApplication::translate("RenameImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        pushButton_destFolder->setText(QApplication::translate("RenameImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        checkBox_selfFolder->setText(QApplication::translate("RenameImageFileClass", "Self Folder", 0, QApplication::UnicodeUTF8));
        pushButton_execute->setText(QApplication::translate("RenameImageFileClass", "Execute", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("RenameImageFileClass", "Source File Name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("RenameImageFileClass", "Dest File Name:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("RenameImageFileClass", "FileType:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RenameImageFileClass: public Ui_RenameImageFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEIMAGEFILE_H
