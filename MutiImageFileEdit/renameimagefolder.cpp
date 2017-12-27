/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "renameimagefolder.h"
#include <QTime>  

RenameImageFolder::RenameImageFolder(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

void RenameImageFolder::init()
{
	setUpConnection();
	initData();
	initUI();
}

RenameImageFolder::~RenameImageFolder()
{

}

void RenameImageFolder::setUpConnection()
{
	connect(ui.lineEdit_sourceFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFolderChanged(const QString &)));
	connect(ui.lineEdit_nameFilter, SIGNAL(textChanged(const QString &)), this, SLOT(onNameFilterChanged(const QString &)));
	connect(ui.lineEdit_destFilter, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFilterChanged(const QString &)));

	connect(ui.comboBox_fileType, SIGNAL(currentIndexChanged(int)), this, SLOT(onFileTypeChanged(int)));
	connect(ui.checkBox_addNum, SIGNAL(clicked()), this, SLOT(onAddNum()));
	connect(ui.checkBox_addTime, SIGNAL(clicked()), this, SLOT(onAddTime()));
	connect(ui.checkBox_folderOnly, SIGNAL(clicked()), this, SLOT(onFolderOnly()));

	connect(ui.pushButton_browseSourceFolder, SIGNAL(clicked()), this, SLOT(onBrowseSourFolder()));
	connect(ui.pushButton_execute, SIGNAL(clicked()), this, SLOT(onExecute()));
	connect(ui.pushButton_undo, SIGNAL(clicked()), this, SLOT(onUndo()));
}

void RenameImageFolder::initUI()
{
	ui.lineEdit_sourceFolder->setText(m_sourceFolder);
	ui.lineEdit_nameFilter->setText(m_nameFilter);
	ui.lineEdit_destFilter->setText(m_destFilter);
	ui.comboBox_fileType->setCurrentIndex(ui.comboBox_fileType->findText(m_fileType));
	Qt::CheckState state;
	m_addNumIsChecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_addNum->setCheckState(state);
	m_addTimeIsChecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_addTime->setCheckState(state);
	m_FolderOnlyIsChecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_folderOnly->setCheckState(state);

}

void RenameImageFolder::initData()
{
	RenameFolderData data = Config::getrenameFolderData();
	m_sourceFolder = data.m_sourceFolder;
	m_nameFilter = data.m_nameFilter;
	m_destFilter = data.m_destFilter;
	m_addNumIsChecked = data.m_addNum.toInt();
	m_addTimeIsChecked = data.m_addTime.toInt();
	m_FolderOnlyIsChecked = data.m_folderOnly.toInt();
	
	initCombox();
	m_fileType = data.m_filterType;
}

void RenameImageFolder::initCombox()
{
	ui.comboBox_fileType->clear();

	QStringList fileFormat = Config::getFileFormat();
	fileFormat<<"allfile(*.*)";
	for(int i = 0;i < fileFormat.size();i++)
	{
		QStringList format;
		format<<fileFormat[i];
		ui.comboBox_fileType->addItems(format);
	}

	m_fileType = ui.comboBox_fileType->currentText();
}

void RenameImageFolder::onSourceFolderChanged(const QString &sourceFolder)
{
	QDir dir(sourceFolder);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_sourceFolder);
		return;
	}
	m_sourceFolder = sourceFolder;
	Config::updateConfigFile("m_renameFolder","m_sourceFolder",m_sourceFolder);
}

void RenameImageFolder::onNameFilterChanged(const QString &nameFilter)
{
	m_nameFilter = nameFilter;
	Config::updateConfigFile("m_renameFolder","m_nameFilter",m_nameFilter);
}

void RenameImageFolder::onDestFilterChanged(const QString &nameFilter)
{
	m_destFilter = nameFilter;
	Config::updateConfigFile("m_renameFolder","m_destFilter",m_destFilter);
}

void RenameImageFolder::onFileTypeChanged(int index)
{
	m_fileType = ui.comboBox_fileType->currentText();
	Config::updateConfigFile("m_renameFolder","m_filterType",m_fileType);
}

void RenameImageFolder::onAddNum()
{
	m_addNumIsChecked = ui.checkBox_addNum->isChecked();
	QString stata;
	m_addNumIsChecked ? stata = QString("1") : stata = QString("0");
	Config::updateConfigFile("m_renameFolder","m_addNum",stata);
}

void RenameImageFolder::onAddTime()
{
	m_addTimeIsChecked = ui.checkBox_addTime->isChecked();
	QString stata;
	m_addTimeIsChecked ? stata = QString("1") : stata = QString("0");
	Config::updateConfigFile("m_renameFolder","m_addTime",stata);
}

void RenameImageFolder::onFolderOnly()
{
	m_FolderOnlyIsChecked = ui.checkBox_folderOnly->isChecked();
	QString stata;
	m_FolderOnlyIsChecked ? stata = QString("1") : stata = QString("0");
	Config::updateConfigFile("m_renameFolder","m_folderOnly",stata);
}

void RenameImageFolder::onBrowseSourFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Source Image Folder"),m_sourceFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_sourceFolder->setText(strSrcDir);

	m_sourceFolder = strSrcDir;
	return;
}

void RenameImageFolder::onExecute()
{
	if(m_sourceFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		return;
	}

	if(m_nameFilter.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please input legal name filter!");
		return;
	}

	m_lastSourceFolder = m_sourceFolder;
	m_lastNameFilter = m_nameFilter;
	m_lastFileType = m_fileType;
	m_lastAddNumIsChecked = m_addNumIsChecked;
	m_lastAddTimeIsChecked = m_addTimeIsChecked;

	renameImageFolder(m_sourceFolder);
	QMessageBox::information(NULL, "Information", "Rename finished!");
}

void RenameImageFolder::onUndo()
{
	if(QMessageBox::Yes == QMessageBox::information(NULL, "Information", "undo your last operating?",QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
	{		
		undoLastEdit(m_sourceFolder);
		QMessageBox::information(NULL, "Information", "undo rename finished!");
	}
}

bool RenameImageFolder::renameImageFolder(QString sourceFolder)
{
	bool isChanged = false;
	QDir dir(sourceFolder); 

	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	int countDir = 0;
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFolder + "\\" + *it;
		if(renameImageFolder(newSource) || it->contains(m_nameFilter))
		{			
			QString newFolderName = newSource + "_" + m_destFilter;

			if(m_addNumIsChecked)
			{
				countDir++;
				QString num;
				num.setNum(countDir);
				newFolderName += num;
			}

			if(m_addTimeIsChecked)
			{
				QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间

				QString str = time.toString("yyyyMMdd"); //设置显示格式yyyy-MM-dd hh:mm:ss ddd
				newFolderName += ("_" + str);
			}

			QFile::rename(newSource,newFolderName);
			isChanged = true;
		}
	}

	if(isChanged || m_FolderOnlyIsChecked)
	{		
		return isChanged;
	}

	QStringList	nameFilters;
	nameFilters = getNameFilter();
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		if(it->contains(m_nameFilter))
		{			
			return true;
		}
	}

	return isChanged;
}

bool RenameImageFolder::undoLastEdit(QString sourceFolder)
{
	bool isChanged = false;
	QDir dir(sourceFolder);
	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	int countDir = 0;
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFolder + "\\" + *it;
		if(undoLastEdit(newSource))
		{
			QString newNameFilter = "_" + m_destFilter;

			int nsplash = newSource.lastIndexOf(newNameFilter);
			
			QFile::rename(newSource,newSource.left(nsplash));
		}
	}

	int ndirSplash = sourceFolder.lastIndexOf("\\");
	QString sourceDirName = sourceFolder.right(sourceFolder.size() - ndirSplash - 1);
	if(sourceDirName.contains(m_destFilter))
	{		
		return true;
	}
	return isChanged;
}

QStringList RenameImageFolder::getNameFilter()
{
	QStringList	nameFilters;

	if(m_fileType.contains("allimage"))
	{
		nameFilters = Config::getFileFormat();
	}
	else if("allfile(*.*)" == m_fileType)
	{

	}
	else
	{
		nameFilters << m_fileType;
	}
	return nameFilters;
}