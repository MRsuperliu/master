/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "moveimagefile.h"

int MoveImageFile::imageFileCount = 0;

MoveImageFile::MoveImageFile(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

MoveImageFile::~MoveImageFile()
{

}

void MoveImageFile::init()
{
	setUpConnection();
	initData();
	initUI();
}

void MoveImageFile::setUpConnection()
{
	connect(ui.lineEdit_sourceFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFolderChanged(const QString &)));
	connect(ui.lineEdit_destFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFolderChanged(const QString &)));

	connect(ui.comboBox_fileType, SIGNAL(currentIndexChanged(int)), this, SLOT(onFileTypeChanged(int)));
	connect(ui.checkBox_originalFolder, SIGNAL(clicked()), this, SLOT(onOriginalFolder()));

	connect(ui.pushButton_sourceFolder, SIGNAL(clicked()), this, SLOT(onBrowseSourFolder()));
	connect(ui.pushButton_destFolder, SIGNAL(clicked()), this, SLOT(onBrowseDestFolder()));
	connect(ui.pushButton_execute, SIGNAL(clicked()), this, SLOT(onExecute()));
}

void MoveImageFile::initUI()
{
	ui.progressBar->setVisible(false);
	ui.progressBar->setValue(0);
	ui.lineEdit_sourceFolder->setText(m_sourceFolder);
	ui.lineEdit_destFolder->setText(m_destFolder);
	ui.comboBox_fileType->setCurrentIndex(ui.comboBox_fileType->findText(m_fileType));
	Qt::CheckState state;
	m_originalFolderIsCkecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_originalFolder->setCheckState(state);
}

void MoveImageFile::initData()
{
	MoveFileData data = Config::getmoveFileData();
	m_sourceFolder = data.m_sourceFolder;
	m_destFolder = data.m_destFolder;
	m_originalFolderIsCkecked = data.m_originalFolder.toInt();
	m_fileCount = 0;

	initCombox();
	m_fileType = data.m_fileType;
}

void MoveImageFile::initCombox()
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

void MoveImageFile::onSourceFolderChanged(const QString &sourceFolder)
{
	QDir dir(sourceFolder);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_sourceFolder);
		return;
	}
	m_sourceFolder = sourceFolder;
	Config::updateConfigFile("m_moveFile","m_sourceFolder",m_sourceFolder);
}

void MoveImageFile::onDestFolderChanged(const QString &DestFolser)
{
	int nSplash =DestFolser.lastIndexOf("\\");
	QDir dir(DestFolser.left(nSplash));
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal dest folder!");
		ui.lineEdit_destFolder->setText(m_destFolder);
		return;
	}
	m_destFolder = DestFolser;
	Config::updateConfigFile("m_moveFile","m_destFolder",m_destFolder);
}

void MoveImageFile::onFileTypeChanged(int index)
{
	m_fileType = ui.comboBox_fileType->currentText();
	Config::updateConfigFile("m_moveFile","m_fileType",m_fileType);
}

void MoveImageFile::onOriginalFolder()
{
	m_originalFolderIsCkecked = ui.checkBox_originalFolder->isChecked();
	if(m_originalFolderIsCkecked)
	{
		Config::updateConfigFile("m_moveFile","m_originalFolder","1");
	}
	else
	{
		Config::updateConfigFile("m_moveFile","m_originalFolder","0");
	}
}

void MoveImageFile::onBrowseSourFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Source Image Folder"),m_sourceFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_sourceFolder->setText(strSrcDir);

	return;
}

void MoveImageFile::onBrowseDestFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("dest Image Folder"),m_destFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_destFolder->setText(strSrcDir);
}

void MoveImageFile::onExecute()
{
	if(m_sourceFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select source folder!");
		return;
	}

	if(m_destFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select dest folder!");
		return;
	}

	if(m_sourceFolder == m_destFolder)
	{
		QMessageBox::information(NULL, "Information", "dest is equal to source,won't move!");
		return;
	}

	QDir dirDest(m_destFolder); 
	if(!dirDest.exists())
	{
		int ok = dirDest.mkdir(m_destFolder);
		if(!ok)
		{
			QMessageBox::information(NULL, "Information", "please input legal dest folder name!");
			return;
		}
	}

	QDir dir(m_sourceFolder); 
	QStringList nameFilters;  
	nameFilters << m_fileType;
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	getFileCount(m_sourceFolder);
	m_fileCount = imageFileCount;
	imageFileCount = 0;

	if(0 == m_fileCount)
	{
		QMessageBox::information(NULL, "Information", "0 file to modify!");
		return;
	}

	ui.progressBar->setVisible(true);

	if(m_originalFolderIsCkecked)
		CopyImageFile(m_sourceFolder,m_destFolder);
	else
		CopyImageFile(m_sourceFolder,m_destFolder,QString(""));

	imageFileCount = 0;
	QString strInformation;
	strInformation.setNum(m_fileCount);
	QMessageBox::information(NULL, "Information", strInformation + " files was renamed!");
	ui.progressBar->setVisible(false);
	ui.progressBar->setValue(0);
}

void MoveImageFile::CopyImageFile(QString sourceFile,QString destFile)
{
	QStringList nameFilters;  
	nameFilters = getNameFilter();
	QDir dir(sourceFile); 
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		QString strOldName = sourceFile + "\\" + *it;
		QFile file(strOldName);
		QString strNewName = destFile + "\\" + *it;
		file.copy(strNewName);

		imageFileCount++;
		int progressBar = imageFileCount * 100 / m_fileCount;
		ui.progressBar->setValue(progressBar);
	}
	
	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFile + "\\" + *it;
		QString newDest = destFile + "\\" + *it;
		QDir dir(newDest);
		if(dir.exists())
		{
		}
		else
		{
			bool ok = dir.mkdir(newDest);//只创建一级子目录，即必须保证上级目录存在
		}
		CopyImageFile(newSource,newDest);
	}
}

void MoveImageFile::CopyImageFile(QString sourceFile,QString destFile ,QString dirHeader)
{
	QStringList nameFilters;  
	nameFilters = getNameFilter();
	QDir dir(sourceFile); 
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		QString strOldName = sourceFile + "\\" + *it;
		QFile file(strOldName);
		QString strNewName = destFile + "\\" + dirHeader + *it;
		file.copy(strNewName);

		imageFileCount++;
		int progressBar = imageFileCount * 100 / m_fileCount;
		ui.progressBar->setValue(progressBar);
	}

	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newheader = dirHeader + *it + "_";
		QString newSource = sourceFile + "\\" + *it;
		QStringList dirfiles;
		CopyImageFile(newSource,destFile,newheader);
	}
}

void MoveImageFile::getFileCount(QString sourceFolder)
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

QStringList MoveImageFile::getNameFilter()
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