#ifndef MUTIIMAGEFILEEDIT_H
#define MUTIIMAGEFILEEDIT_H

#include <QtGui/QDialog>
#include<QMouseEvent>
#include "ui_mutiimagefileedit.h"
#include "config.h"
#include "modifyimagefile.h"
#include "moveimagefile.h"
#include "renameimagefile.h"
#include "renameimagefolder.h"

class MutiImageFileEdit : public QDialog
{
	Q_OBJECT

public:
	MutiImageFileEdit(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MutiImageFileEdit();

private:
	void setUpConnection();
	void initUI();
	void initData();

	void initToolbox();
	void insertWidget(QString strWidgetTitle, QWidget *pWidget);
	

public slots:
	void onPageChange(int nIndex);
	void mousePressEvent(QMouseEvent *event);
	void restart();
private:
	Ui::MutiImageFileEditClass ui;
	MoveImageFile *pMoveImageFile;
	RenameImageFile *pRenameImageFile;
	ModifyImageFile *pModifyImageFile;
	RenameImageFolder *pRenameImageFolder;
	Config *pConfig;
};

#endif // MUTIIMAGEFILEEDIT_H
