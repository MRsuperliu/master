/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "renameimagefile.h"

int RenameImageFile::imageFileCount = 0;

RenameImageFile::RenameImageFile(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

RenameImageFile::~RenameImageFile()
{

}

void RenameImageFile::init()
{
	setUpConnection();
	initData();
	initUI();
}

void RenameImageFile::setUpConnection()
{
	connect(ui.lineEdit_sourceFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFolderChanged(const QString &)));
	connect(ui.lineEdit_destFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFolderChanged(const QString &)));
	connect(ui.lineEdit_sourceFileName, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFileNameChanged(const QString &)));
	connect(ui.lineEdit_destFileName, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFileNameChanged(const QString &)));
	
	connect(ui.comboBox_fileType, SIGNAL(currentIndexChanged(int)), this, SLOT(onFileTypeChanged(int)));

	connect(ui.pushButton_sourceFolder, SIGNAL(clicked()), this, SLOT(onBrowseSourFolder()));
	connect(ui.pushButton_destFolder, SIGNAL(clicked()), this, SLOT(onBrowseDestFolder()));
	connect(ui.checkBox_selfFolder, SIGNAL(clicked()), this, SLOT(onSelfFolder()));
	connect(ui.pushButton_execute, SIGNAL(clicked()), this, SLOT(onExecute()));
}

void RenameImageFile::initUI()
{
	ui.progressBar->setValue(0);
	ui.progressBar->setVisible(false);
	ui.pushButton_destFolder->setEnabled(!m_selfFolderIsCkecked);
	ui.lineEdit_destFolder->setEnabled(!m_selfFolderIsCkecked);

	ui.lineEdit_sourceFolder->setText(m_sourceFolder);
	ui.lineEdit_destFolder->setText(m_destFolder);
	ui.lineEdit_sourceFileName->setText(m_sourceFileName);
	ui.lineEdit_destFileName->setText(m_destFileName);
	ui.comboBox_fileType->setCurrentIndex(ui.comboBox_fileType->findText(m_fileType));
	Qt::CheckState state;
	m_selfFolderIsCkecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_selfFolder->setCheckState(state);

}

void RenameImageFile::initData()
{
	RenameFileData data = Config::getrenameFileData();
	m_sourceFolder = data.m_sourceFolder;
	m_destFolder = data.m_destFolder;
	m_sourceFileName = data.m_sourceFileName;
	m_destFileName = data.m_destFileName;
	
	m_selfFolderIsCkecked = data.m_selfFolder.toInt();
	m_fileCount = 0;

	initCombox();
	m_fileType = data.m_fileType;
}

void RenameImageFile::initCombox()
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

void RenameImageFile::renameImageFile(QString sourceFolder,QString destFolder)
{
	QDir dir(sourceFolder); 
	QStringList	nameFilters;
	nameFilters = getNameFilter();
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		QString strOldName = sourceFolder + "\\" + *it;
		QFile file(strOldName);
		
		QString strNewName;
		if(m_sourceFileName.isEmpty())
		{
			int nSplash = it->lastIndexOf(".");
			strNewName = destFolder + "\\" + it->left(nSplash) + m_destFileName + it->right(it->size() - nSplash);
		}
		else
		{
			int nSplash = it->indexOf(m_sourceFileName);
			strNewName = destFolder + "\\" + it->replace(nSplash,m_sourceFileName.size(),m_destFileName);
		}
		file.copy(strNewName);
		imageFileCount++;
		int progressBar = imageFileCount * 100 / m_fileCount;
		ui.progressBar->setValue(progressBar);
	}
	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFolder + "\\" + *it;
		QString newDest = destFolder + "\\" + *it;
		QDir dir(newDest);
		if(dir.exists())
		{
		}
		else
		{
			bool ok = dir.mkdir(newDest);//只创建一级子目录，即必须保证上级目录存在
		}
		renameImageFile(newSource,newDest);
	}
}

void RenameImageFile::onSourceFolderChanged(const QString &sourceFolder)
{
	QDir dir(sourceFolder);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_sourceFolder);
		return;
	}
	m_sourceFolder = sourceFolder;
	Config::updateConfigFile("m_renameFile","m_sourceFolder",m_sourceFolder);
}

void RenameImageFile::onDestFolderChanged(const QString &DestFolser)
{
	int nSplash =DestFolser.lastIndexOf("\\");
	QDir dir(DestFolser.left(nSplash));
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal dest folder!");
		ui.lineEdit_sourceFolder->setText(m_destFolder);
		return;
	}
	m_destFolder = DestFolser;
	Config::updateConfigFile("m_renameFile","m_destFolder",DestFolser);
}

void RenameImageFile::onSourceFileNameChanged(const QString &sourceFileName)
{
	m_sourceFileName = sourceFileName;
	Config::updateConfigFile("m_renameFile","m_sourceFileName",m_sourceFileName);
}
void RenameImageFile::onDestFileNameChanged(const QString &destFileName)
{
	m_destFileName = destFileName;
	Config::updateConfigFile("m_renameFile","m_destFileName",m_destFileName);
}

void RenameImageFile::onFileTypeChanged(int index)
{
	m_fileType = ui.comboBox_fileType->currentText();
	Config::updateConfigFile("m_renameFile","m_fileType",m_fileType);
}

void RenameImageFile::onBrowseSourFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Source Image Folder"),m_sourceFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_sourceFolder->setText(strSrcDir);
	m_sourceFolder = strSrcDir;
	
	if (ui.checkBox_selfFolder->isChecked())
	{
		ui.lineEdit_destFolder->setText(ui.lineEdit_sourceFolder->text());
		m_destFolder = strSrcDir;
	}

	return;
}

void RenameImageFile::onBrowseDestFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Dest Image Folder"),m_destFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_destFolder->setText(strSrcDir);
	m_destFolder = strSrcDir;  
}

void RenameImageFile::onSelfFolder()
{
	m_selfFolderIsCkecked = ui.checkBox_selfFolder->isChecked();
	ui.pushButton_destFolder->setEnabled(!m_selfFolderIsCkecked);
	ui.lineEdit_destFolder->setEnabled(!m_selfFolderIsCkecked);
	if(m_selfFolderIsCkecked)
	ui.lineEdit_destFolder->setText(ui.lineEdit_sourceFolder->text());	
	QString stata;
	m_selfFolderIsCkecked ? stata = QString("1") : QString("0");
	Config::updateConfigFile("m_renameFile","m_selfFolder",stata);
}


void RenameImageFile::onExecute()
{
	if(m_sourceFolder.isEmpty()&&m_destFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder and dest folder!");		
		return;
	}

	if(m_sourceFileName == m_destFileName)
	{
		QMessageBox::information(NULL, "Information", "destfilename is equal to sourcefilename,nothing to change!");		
		return;
	}

	QDir dir(m_destFolder); 
	if(!dir.exists())
	{
		int ok = dir.mkdir(m_destFolder);
		if(!ok)
		{
			QMessageBox::information(NULL, "Information", "please input legal dest folder name!");
			return;
		}
	}
		
	getFileCount(m_sourceFolder);
	m_fileCount = imageFileCount;
	imageFileCount = 0;

	if(0 == m_fileCount)
	{
		QMessageBox::information(NULL, "Information", "0 file to modify!");
		return;
	}

	ui.progressBar->setVisible(true);
	renameImageFile(m_sourceFolder,m_destFolder);
	imageFileCount = 0;
	
	QString strInformation;
	strInformation.setNum(m_fileCount);
	QMessageBox::information(NULL, "Information", strInformation + " files was renamed!");
	ui.progressBar->setVisible(false);
	ui.progressBar->setValue(0);
}

void RenameImageFile::getFileCount(QString sourceFolder)
{
	QDir dir(sourceFolder); 
	QStringList	nameFilters;
	nameFilters = getNameFilter();
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);
	imageFileCount += files.size();
	
	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFolder + "\\" + *it;
		getFileCount(newSource);
	}
}

QStringList RenameImageFile::getNameFilter()
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