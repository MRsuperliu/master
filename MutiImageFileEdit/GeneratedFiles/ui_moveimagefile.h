/********************************************************************************
** Form generated from reading UI file 'moveimagefile.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEIMAGEFILE_H
#define UI_MOVEIMAGEFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MoveImageFileClass
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QCheckBox *checkBox_originalFolder;
    QLineEdit *lineEdit_sourceFolder;
    QPushButton *pushButton_sourceFolder;
    QLabel *label;
    QPushButton *pushButton_execute;
    QPushButton *pushButton_destFolder;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_destFolder;
    QComboBox *comboBox_fileType;
    QProgressBar *progressBar;

    void setupUi(QDialog *MoveImageFileClass)
    {
        if (MoveImageFileClass->objectName().isEmpty())
            MoveImageFileClass->setObjectName(QString::fromUtf8("MoveImageFileClass"));
        MoveImageFileClass->resize(480, 270);
        MoveImageFileClass->setMinimumSize(QSize(480, 270));
        MoveImageFileClass->setMaximumSize(QSize(480, 270));
        verticalLayout = new QVBoxLayout(MoveImageFileClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(MoveImageFileClass);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        checkBox_originalFolder = new QCheckBox(groupBox);
        checkBox_originalFolder->setObjectName(QString::fromUtf8("checkBox_originalFolder"));
        checkBox_originalFolder->setGeometry(QRect(350, 110, 110, 20));
        lineEdit_sourceFolder = new QLineEdit(groupBox);
        lineEdit_sourceFolder->setObjectName(QString::fromUtf8("lineEdit_sourceFolder"));
        lineEdit_sourceFolder->setGeometry(QRect(100, 30, 240, 20));
        pushButton_sourceFolder = new QPushButton(groupBox);
        pushButton_sourceFolder->setObjectName(QString::fromUtf8("pushButton_sourceFolder"));
        pushButton_sourceFolder->setGeometry(QRect(350, 30, 70, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 90, 20));
        pushButton_execute = new QPushButton(groupBox);
        pushButton_execute->setObjectName(QString::fromUtf8("pushButton_execute"));
        pushButton_execute->setGeometry(QRect(330, 160, 75, 20));
        pushButton_destFolder = new QPushButton(groupBox);
        pushButton_destFolder->setObjectName(QString::fromUtf8("pushButton_destFolder"));
        pushButton_destFolder->setGeometry(QRect(350, 70, 70, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 90, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 90, 20));
        lineEdit_destFolder = new QLineEdit(groupBox);
        lineEdit_destFolder->setObjectName(QString::fromUtf8("lineEdit_destFolder"));
        lineEdit_destFolder->setGeometry(QRect(100, 70, 240, 20));
        comboBox_fileType = new QComboBox(groupBox);
        comboBox_fileType->setObjectName(QString::fromUtf8("comboBox_fileType"));
        comboBox_fileType->setGeometry(QRect(100, 110, 240, 20));
        progressBar = new QProgressBar(groupBox);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 160, 300, 20));
        progressBar->setValue(24);
        checkBox_originalFolder->raise();
        lineEdit_sourceFolder->raise();
        pushButton_sourceFolder->raise();
        label->raise();
        pushButton_execute->raise();
        pushButton_destFolder->raise();
        label_2->raise();
        lineEdit_destFolder->raise();
        label_3->raise();
        comboBox_fileType->raise();
        progressBar->raise();

        verticalLayout->addWidget(groupBox);


        retranslateUi(MoveImageFileClass);

        QMetaObject::connectSlotsByName(MoveImageFileClass);
    } // setupUi

    void retranslateUi(QDialog *MoveImageFileClass)
    {
        MoveImageFileClass->setWindowTitle(QApplication::translate("MoveImageFileClass", "MoveImageFile", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MoveImageFileClass", "MoveImageFile", 0, QApplication::UnicodeUTF8));
        checkBox_originalFolder->setText(QApplication::translate("MoveImageFileClass", "original Folder", 0, QApplication::UnicodeUTF8));
        pushButton_sourceFolder->setText(QApplication::translate("MoveImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MoveImageFileClass", "Source Folder:", 0, QApplication::UnicodeUTF8));
        pushButton_execute->setText(QApplication::translate("MoveImageFileClass", "Execute", 0, QApplication::UnicodeUTF8));
        pushButton_destFolder->setText(QApplication::translate("MoveImageFileClass", "Browser...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MoveImageFileClass", "Dest Folder:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MoveImageFileClass", "File Type:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MoveImageFileClass: public Ui_MoveImageFileClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEIMAGEFILE_H
