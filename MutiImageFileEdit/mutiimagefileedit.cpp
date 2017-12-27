/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "mutiimagefileedit.h"
#include <QMenu>

MutiImageFileEdit::MutiImageFileEdit(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
	,pMoveImageFile(NULL)
	,pRenameImageFile(NULL)
	,pModifyImageFile(NULL)
	,pRenameImageFolder(NULL)
	,pConfig(NULL)
{
	ui.setupUi(this);
	setUpConnection();
	initUI();
	initData();
}

MutiImageFileEdit::~MutiImageFileEdit()
{
	if(NULL != pMoveImageFile)
	{
		delete pMoveImageFile;
		pMoveImageFile = NULL;
	}

	if(NULL != pRenameImageFile)
	{
		delete pRenameImageFile;
		pRenameImageFile = NULL;
	}

	if(NULL != pModifyImageFile)
	{
		delete pModifyImageFile;
		pModifyImageFile = NULL;
	}

	if(NULL != pRenameImageFolder)
	{
		delete pRenameImageFolder;
		pRenameImageFolder = NULL;
	}

	if(NULL != pConfig)
	{
		delete pConfig;
		pConfig = NULL;
	}	
}

void MutiImageFileEdit::setUpConnection()
{
	connect(ui.toolBox_function, SIGNAL(currentChanged(int)), this, SLOT(onPageChange(int)));
}

void MutiImageFileEdit::initUI()
{
	initToolbox();
}

void MutiImageFileEdit::initData()
{

}

void MutiImageFileEdit::initToolbox()
{
	if(NULL == pConfig)
	{
		pConfig = new Config(this);
		pConfig->init();
	}

	if(NULL == pMoveImageFile)
	{
		pMoveImageFile = new MoveImageFile(this);
		pMoveImageFile->init();
	}

	if(NULL == pRenameImageFile)
	{
		pRenameImageFile = new RenameImageFile(this);
		pRenameImageFile->init();
	}

	if(NULL == pModifyImageFile)
	{
		pModifyImageFile = new ModifyImageFile(this);
		pModifyImageFile->init();
	}

	if(NULL == pRenameImageFolder)
	{
		pRenameImageFolder = new RenameImageFolder(this);
		pRenameImageFolder->init();
	}

	insertWidget(CSTRING_TO_QSTRING("Config"),pConfig);
	insertWidget(CSTRING_TO_QSTRING("MoveFile"),pMoveImageFile);
	insertWidget(CSTRING_TO_QSTRING("RenameFile"),pRenameImageFile);
	insertWidget(CSTRING_TO_QSTRING("ModifyFile"),pModifyImageFile);
	insertWidget(CSTRING_TO_QSTRING("RenameFolder"),pRenameImageFolder);

	return ;
}

void MutiImageFileEdit::insertWidget(QString strWidgetTitle, QWidget *pWidget)
{
	if(NULL == pWidget)
	{
		return;
	}
	if(-1 != ui.stackedWidget_function->indexOf(pWidget))
	{
		return;
	}
	ui.toolBox_function->addItem(new QWidget, strWidgetTitle);
	ui.stackedWidget_function->addWidget(pWidget);
	return;
}

void MutiImageFileEdit::onPageChange(int nIndex)
{
	ui.stackedWidget_function->setCurrentIndex(nIndex);
	return;
}

void MutiImageFileEdit::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        QMenu *menu = new QMenu(this);
		QAction *pAction = new QAction("restart",this);
		menu->addAction(pAction);
		menu->show();
		menu->move(cursor().pos());
		connect(pAction,SIGNAL(triggered()),this,SLOT(restart()));
    }
    
    return ;
}

void MutiImageFileEdit::restart()
{
	qApp->exit(EXIT_CODE_REBOOT);
	return;
}