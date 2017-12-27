/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "modifyimagefile.h"

int ModifyImageFile::imageFileCount = 0;

ModifyImageFile::ModifyImageFile(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

ModifyImageFile::~ModifyImageFile()
{

}

void ModifyImageFile::init()
{
	setUpConnection();
	initData();
	initUI();
}

void ModifyImageFile::setUpConnection()
{
	connect(ui.lineEdit_sourceFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFolderChanged(const QString &)));
	connect(ui.lineEdit_destFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFolderChanged(const QString &)));

	connect(ui.comboBox_sourceFileFormat, SIGNAL(currentIndexChanged(int)), this, SLOT(onSourceFileFormatChanged(int)));
	connect(ui.comboBox_destFileFormat, SIGNAL(currentIndexChanged(int)), this, SLOT(onDestFileFormatChanged(int)));

	connect(ui.lineEdit_left, SIGNAL(textChanged(const QString &)), this, SLOT(onLeftChanged(const QString &)));
	connect(ui.lineEdit_right, SIGNAL(textChanged(const QString &)), this, SLOT(onTopChanged(const QString &)));
	connect(ui.lineEdit_width, SIGNAL(textChanged(const QString &)), this, SLOT(onWidthChanged(const QString &)));
	connect(ui.lineEdit_height, SIGNAL(textChanged(const QString &)), this, SLOT(onHeightChanged(const QString &)));

	connect(ui.pushButton_sourceFolder, SIGNAL(clicked()), this, SLOT(onBrowseSourFolder()));
	connect(ui.pushButton_destFolder, SIGNAL(clicked()), this, SLOT(onBrowseDestFolder()));
	connect(ui.checkBox_modifyFileFormat, SIGNAL(clicked()), this, SLOT(onModifyFileFormat()));
	connect(ui.checkBox_modifyFileSize, SIGNAL(clicked()), this, SLOT(onModifyFileSize()));
	connect(ui.pushButton_execute, SIGNAL(clicked()), this, SLOT(onExecute()));
}

void ModifyImageFile::initUI()
{
	ui.progressBar->setValue(0);
	ui.progressBar->setVisible(false);
	ui.comboBox_sourceFileFormat->setEnabled(m_modifyFileFormatIsCheched | m_modifyFileSizeIsChecked);
	ui.comboBox_destFileFormat->setEnabled(m_modifyFileFormatIsCheched);

	ui.lineEdit_left->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_right->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_width->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_height->setEnabled(m_modifyFileSizeIsChecked);

	ui.lineEdit_sourceFolder->setText(m_sourceFolder);
	ui.lineEdit_destFolder->setText(m_destFolder);
	ui.comboBox_sourceFileFormat->setCurrentIndex(ui.comboBox_sourceFileFormat->findText(m_sourceFormat));
	ui.comboBox_destFileFormat->setCurrentIndex(ui.comboBox_destFileFormat->findText(m_destFormat));
	ui.lineEdit_left->setText(QString("%1").arg(m_left));
	ui.lineEdit_right->setText(QString("%1").arg(m_top));
	ui.lineEdit_width->setText(QString("%1").arg(m_width));
	ui.lineEdit_height->setText(QString("%1").arg(m_height));

	Qt::CheckState state;
	m_modifyFileFormatIsCheched ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_modifyFileFormat->setCheckState(state);
	m_modifyFileSizeIsChecked ? state = Qt::Checked :state = Qt::Unchecked;
	ui.checkBox_modifyFileSize->setCheckState(state);
}

void ModifyImageFile::initData()
{
	ModifyFileData data = Config::getmodifyFileData();
	m_sourceFolder = data.m_sourceFolder;
	m_destFolder = data.m_destFolder;
	m_modifyFileFormatIsCheched = data.m_modifyFormate.toInt();
	m_modifyFileSizeIsChecked = data.m_modifySize.toInt();
	m_left = data.m_left.toInt();
	m_top = data.m_top.toInt();
	m_width = data.m_width.toInt();
	m_height = data.m_height.toInt();

	m_fileCount = 0;

	initCombox();
	m_sourceFormat = data.m_sourceFileFormat;
	m_destFormat = data.m_destFileFormat;
}

void ModifyImageFile::initCombox()
{
	ui.comboBox_sourceFileFormat->clear();
	ui.comboBox_destFileFormat->clear();

	QStringList fileFormat = Config::getFileFormat();

	for(int i = 0;i < fileFormat.size();i++)
	{
		QStringList format;
		format<<fileFormat[i];
		ui.comboBox_sourceFileFormat->addItems(format);
		if(!fileFormat[i].contains("allimage"))
		ui.comboBox_destFileFormat->addItems(format);
	}

	m_sourceFormat = ui.comboBox_sourceFileFormat->currentText();
	m_destFormat = ui.comboBox_destFileFormat->currentText();
}

void ModifyImageFile::onSourceFolderChanged(const QString &sourceFolder)
{
	QDir dir(sourceFolder);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_sourceFolder);
		return;
	}
	m_sourceFolder = sourceFolder;
	Config::updateConfigFile("m_modifyFile","m_sourceFolder",m_sourceFolder);
}

void ModifyImageFile::onDestFolderChanged(const QString &DestFolser)
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
	Config::updateConfigFile("m_modifyFile","m_destFolder",m_destFolder);
}

void ModifyImageFile::onSourceFileFormatChanged(int index)
{
	m_sourceFormat = ui.comboBox_sourceFileFormat->currentText();
	Config::updateConfigFile("m_modifyFile","m_sourceFileFormat",m_sourceFormat);
}

void ModifyImageFile::onDestFileFormatChanged(int index)
{
	m_destFormat = ui.comboBox_destFileFormat->currentText();
	Config::updateConfigFile("m_modifyFile","m_destFileFormat",m_destFormat);
}

void ModifyImageFile::onLeftChanged(const QString &left)
{
	std::string strLeft = left.toStdString();
	for(size_t i = 0; i < strLeft.size(); i++)
	{
		if('0' <= strLeft[i] && '9'>= strLeft[i])
			continue;
		else
		{
			QMessageBox::information(NULL, "Information", "please input num!");
			QString num;
			num.setNum(m_left);
			ui.lineEdit_left->setText(num);
			return;
		}
	}
	m_left = left.toInt();
	Config::updateConfigFile("m_modifyFile","m_left",QString("%1").arg(m_left));
}

void ModifyImageFile::onTopChanged(const QString &top)
{
	std::string strTop = top.toStdString();
	for(size_t i = 0; i < strTop.size(); i++)
	{
		if('0' <= strTop[i] && '9'>= strTop[i])
			continue;
		else
		{
			QMessageBox::information(NULL, "Information", "please input num!");
			QString num;
			num.setNum(m_top);
			ui.lineEdit_right->setText(num);
			return;
		}
	}
	m_top = top.toInt();
	Config::updateConfigFile("m_modifyFile","m_top",QString("%1").arg(m_top));
}

void ModifyImageFile::onWidthChanged(const QString &width)
{
	std::string strWidth = width.toStdString();
	for(size_t i = 0; i < strWidth.size(); i++)
	{
		if('0' <= strWidth[i] && '9'>= strWidth[i])
			continue;
		else
		{
			QMessageBox::information(NULL, "Information", "please input num!");
			QString num;
			num.setNum(m_width);
			ui.lineEdit_width->setText(num);
			return;
		}
	}
	m_width = width.toInt();
	Config::updateConfigFile("m_modifyFile","m_width",QString("%1").arg(m_width));
}

void ModifyImageFile::onHeightChanged(const QString &height)
{
	std::string strHeight = height.toStdString();
	for(size_t i = 0; i < strHeight.size(); i++)
	{
		if('0' <= strHeight[i] && '9'>= strHeight[i])
			continue;
		else
		{
			QMessageBox::information(NULL, "Information", "please input num!");
			QString num;
			num.setNum(m_height);
			ui.lineEdit_height->setText(num);
			return;
		}
	}
	m_height = height.toInt();
	Config::updateConfigFile("m_modifyFile","m_height",QString("%1").arg(m_height));
}

void ModifyImageFile::onBrowseSourFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Source Image Folder"),m_sourceFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_sourceFolder->setText(strSrcDir);

	return;
}

void ModifyImageFile::onBrowseDestFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Dest Image Folder"),m_destFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_destFolder->setText(strSrcDir);
}

void ModifyImageFile::onModifyFileFormat()
{
	m_modifyFileFormatIsCheched = ui.checkBox_modifyFileFormat->isChecked();
	ui.comboBox_sourceFileFormat->setEnabled(m_modifyFileFormatIsCheched | m_modifyFileSizeIsChecked);
	ui.comboBox_destFileFormat->setEnabled(m_modifyFileFormatIsCheched);
	QString stata;
	m_modifyFileFormatIsCheched ? stata = QString("1"): stata = QString("0");
	Config::updateConfigFile("m_modifyFile","m_modifyFormate",stata);
}

void ModifyImageFile::onModifyFileSize()
{
	m_modifyFileSizeIsChecked = ui.checkBox_modifyFileSize->isChecked();
	ui.lineEdit_left->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_right->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_width->setEnabled(m_modifyFileSizeIsChecked);
	ui.lineEdit_height->setEnabled(m_modifyFileSizeIsChecked);
	ui.comboBox_sourceFileFormat->setEnabled(m_modifyFileSizeIsChecked | m_modifyFileFormatIsCheched);

	QString stata;
	m_modifyFileSizeIsChecked ? stata = QString("1"): stata = QString("0");
	Config::updateConfigFile("m_modifyFile","m_modifySize",stata);
}

void ModifyImageFile::onExecute()
{
	QString sourceFolder = m_sourceFolder;
	if(sourceFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select source folder!");
		return;
	}

	QString destFolder = m_destFolder;
	if(destFolder.isEmpty())
	{
		QMessageBox::information(NULL, "Information", "please select dest folder!");
		return;
	}

	if(!(m_modifyFileFormatIsCheched|m_modifyFileSizeIsChecked))
	{
		QMessageBox::information(NULL, "Information", "please select a function!");
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

	QString sourceFormat = m_sourceFormat;
	QString destFormat = m_destFormat;

	getFileCount(m_sourceFolder);
	m_fileCount = imageFileCount;
	imageFileCount = 0;

	if(0 == m_fileCount)
	{
		QMessageBox::information(NULL, "Information", "0 file to modify!");
		return;
	}

	if(m_modifyFileFormatIsCheched)
	{
		if(sourceFormat == destFormat)
		{
			QMessageBox::information(NULL, "Information", "please select different format!");
			return;
		}		
		ui.progressBar->setVisible(true);
		ModifyImageFormat(sourceFolder,destFolder);
		imageFileCount = 0;
	}
	else		
	{
		ui.progressBar->setVisible(true);
		ModifyImageSize(sourceFolder,destFolder);
		imageFileCount = 0;
	}

	QString strInformation;
	strInformation.setNum(m_fileCount);
	QMessageBox::information(NULL, "Information", strInformation + " files was modified!");
	ui.progressBar->setVisible(false);
	ui.progressBar->setValue(0);
}

void ModifyImageFile::ModifyImageFormat(QString sourceFolder,QString destFolder)
{
	QString destFormat = m_destFormat;
	QDir dir(sourceFolder); 
	QStringList	nameFilters = getNameFilter();
	
	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		QString strOldName = sourceFolder + "\\" + *it;
		QImage qImage;
		qImage.load(strOldName);
		if(m_modifyFileSizeIsChecked)
		{
			QRect qrct(m_left, m_top, m_width, m_height);
			qImage = qImage.copy(qrct);
		}	
		int nSplash = it->lastIndexOf(".");
		QString strNewName = destFolder + "\\" + it->left(nSplash) + destFormat.right(destFormat.size() - 1);
		qImage.save(strNewName);

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
		ModifyImageFormat(newSource,newDest);
	}
}

void ModifyImageFile::ModifyImageSize(QString sourceFolder,QString destFolder)
{
	QString sourceFormat = m_sourceFormat;
	QRect qrct(m_left, m_top, m_width, m_height);
	QDir dir(sourceFolder); 
	QStringList	nameFilters = getNameFilter();

	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);

	for(QList<QString>::Iterator it = files.begin();it != files.end();it++)
	{
		QString strOldName = sourceFolder + "\\" + *it;
		QImage qImage;
		qImage.load(strOldName);
		QImage qRectImg = qImage.copy (qrct);
		QString strNewName = destFolder + "\\" + *it;
		qRectImg.save(strNewName);

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
		ModifyImageSize(newSource,newDest);
	}
}

void ModifyImageFile::getFileCount(QString sourceFolder)
{
	QDir dir(sourceFolder); 
	QStringList	nameFilters = getNameFilter();

	QStringList files = dir.entryList(nameFilters,QDir::Files|QDir::Readable, QDir::Name);
	imageFileCount += files.size();

	QStringList dirs = dir.entryList(QDir::Dirs|QDir::Readable| QDir::NoDotAndDotDot, QDir::Name);
	for(QList<QString>::Iterator it = dirs.begin();it != dirs.end();it++)
	{
		QString newSource = sourceFolder + "\\" + *it;
		getFileCount(newSource);
	}
}

QStringList ModifyImageFile::getNameFilter()
{
	QStringList	nameFilters;

	if(m_sourceFormat.contains("allimage"))
	{
		nameFilters = Config::getFileFormat();
	}
	else
	{
		nameFilters << m_sourceFormat;
	}
	return nameFilters;
}