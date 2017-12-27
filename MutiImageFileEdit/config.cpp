/*Copyright 2017 UNIC Technologies.All rights Reserved.

*/

#include "config.h"
#include "commonheader.h"

QString Config::m_sourceFolder = CSTRING_TO_QSTRING("");
QString Config::m_destFolder = CSTRING_TO_QSTRING("");
QStringList Config::m_fileFormat = QStringList();

MoveFileData Config::m_moveFileData;
RenameFileData Config::m_renameFileData;
ModifyFileData Config::m_modifyFileData;
RenameFolderData Config::m_renameFolderData;

const QString CONFIGFILEPATH = "config\\config.xml";
const QString DEFAULTSOURCEFOLDER = "D:\\";
const QString DEFAULTDESTFOLDER = "D:\\";
//const QString CONFIGFILEPATH = "config\\config.xml";
//const QString CONFIGFILEPATH = "config\\config.xml";

Config::Config(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

Config::~Config()
{

}

void Config::init()
{
	creatConfigFile();
	readConfigFile();
	setUpConnection();
	initUI();
	initData();
}

void Config::setUpConnection()
{
	connect(ui.lineEdit_sourceFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onSourceFolderChanged(const QString &)));
	connect(ui.lineEdit_destFolder, SIGNAL(textChanged(const QString &)), this, SLOT(onDestFolderChanged(const QString &)));

	connect(ui.pushButton_browseSourceFolder, SIGNAL(clicked()), this, SLOT(onBrowseSourFolder()));
	connect(ui.pushButton_browseDestFolder, SIGNAL(clicked()), this, SLOT(onBrowseDestFolder()));
}

void Config::initUI()
{
	ui.lineEdit_sourceFolder->setText(m_sourceFolder);
	ui.lineEdit_destFolder->setText(m_destFolder);
}

void Config::initData()
{

}

void Config::readConfigFile()
{
	//QString path = QCoreApplication::applicationDirPath();
	QFile CFile(CONFIGFILEPATH);
	if(false == CFile.open(QFile::ReadOnly | QFile::Text))
	{
		CFile.close();
		return ;
	}

	QDomDocument CDomDocument;
	QString strErrorText;
	int nRow = 0, nColumn=0;
	if(false == CDomDocument.setContent(&CFile, false, &strErrorText, &nRow, &nColumn))
	{
		CFile.close();
		return ;
	}

	if(true == CDomDocument.isNull())
	{
		CFile.close();
		return ;
	}

	QDomElement CRoot = CDomDocument.documentElement();
	if(true == CRoot.isNull())
	{
		CFile.close();
		return ;
	}

	QDomElement fileTypes = CRoot.firstChildElement("m_fileType");
	QDomNodeList listFileType = fileTypes.childNodes();

	QString allimage = "*.allimage(";
	for (int i = 0; i < listFileType.count(); ++i)
	{
		QDomNode fileType = listFileType.item(i);
		QDomElement fileTypeElement = fileType.toElement();
		m_fileFormat << fileTypeElement.text();
		allimage += fileTypeElement.text();
		allimage += ",";
	}

	int nSplash = allimage.lastIndexOf(",");
	allimage.replace(nSplash , 1 ,")");
	m_fileFormat << allimage;
	
	readDefaultConfig(CRoot);
	readMoveFileConfig(CRoot);
	readRenameFileConfig(CRoot);
	readModifyFileConfig(CRoot);
	readRenameFolderConfig(CRoot);

	CFile.close();

}

void Config::readDefaultConfig(QDomElement &CRoot)
{
	QDomElement CDefaultConfig = CRoot.firstChildElement("m_config");

	QDomElement sourceFolder = CDefaultConfig.firstChildElement("m_sourceFolder");
	m_sourceFolder = sourceFolder.text();
	QDomElement destFolder = CDefaultConfig.firstChildElement("m_destFolder");
	m_destFolder = destFolder.text();
}

void Config::readMoveFileConfig(QDomElement &CRoot)
{
	QDomElement moveFile = CRoot.firstChildElement("m_moveFile");

	QDomElement sourceFolder = moveFile.firstChildElement("m_sourceFolder");
	m_moveFileData.m_sourceFolder = sourceFolder.text();
	QDomElement destFolder = moveFile.firstChildElement("m_destFolder");
	m_moveFileData.m_destFolder = destFolder.text();
	QDomElement fileType = moveFile.firstChildElement("m_fileType");
	m_moveFileData.m_fileType = fileType.text();
	QDomElement originalFolder = moveFile.firstChildElement("m_originalFolder");
	m_moveFileData.m_originalFolder = originalFolder.text();
}

void Config::readRenameFileConfig(QDomElement &CRoot)
{
	QDomElement renameFile = CRoot.firstChildElement("m_renameFile");

	QDomElement sourceFolder = renameFile.firstChildElement("m_sourceFolder");
	m_renameFileData.m_sourceFolder = sourceFolder.text();
	QDomElement destFolder = renameFile.firstChildElement("m_destFolder");
	m_renameFileData.m_destFolder = destFolder.text();
	QDomElement sourceFileName = renameFile.firstChildElement("m_sourceFileName");
	m_renameFileData.m_sourceFileName = sourceFileName.text();
	QDomElement destFileName = renameFile.firstChildElement("m_destFileName");
	m_renameFileData.m_destFileName = destFileName.text();
	QDomElement fileType = renameFile.firstChildElement("m_fileType");
	m_renameFileData.m_fileType = fileType.text();
	QDomElement selfFolder = renameFile.firstChildElement("m_selfFolder");
	m_renameFileData.m_selfFolder = selfFolder.text();
}

void Config::readModifyFileConfig(QDomElement &CRoot)
{
	QDomElement modifyFile = CRoot.firstChildElement("m_modifyFile");

	QDomElement sourceFolder = modifyFile.firstChildElement("m_sourceFolder");
	m_modifyFileData.m_sourceFolder = sourceFolder.text();
	QDomElement destFolder = modifyFile.firstChildElement("m_destFolder");
	m_modifyFileData.m_destFolder = destFolder.text();
	QDomElement sourceFileFormat = modifyFile.firstChildElement("m_sourceFileFormat");
	m_modifyFileData.m_sourceFileFormat = sourceFileFormat.text();
	QDomElement destFileFormat = modifyFile.firstChildElement("m_destFileFormat");
	m_modifyFileData.m_destFileFormat = destFileFormat.text();
	QDomElement modifyFormate = modifyFile.firstChildElement("m_modifyFormate");
	m_modifyFileData.m_modifyFormate = modifyFormate.text();
	QDomElement modifySize = modifyFile.firstChildElement("m_modifySize");
	m_modifyFileData.m_modifySize = modifySize.text();
	QDomElement left = modifyFile.firstChildElement("m_left");
	m_modifyFileData.m_left = left.text();
	QDomElement top = modifyFile.firstChildElement("m_top");
	m_modifyFileData.m_top = top.text();
	QDomElement width = modifyFile.firstChildElement("m_width");
	m_modifyFileData.m_width = width.text();
	QDomElement height = modifyFile.firstChildElement("m_height");
	m_modifyFileData.m_height = height.text();
}

void Config::readRenameFolderConfig(QDomElement &CRoot)
{
	QDomElement RenameFolder = CRoot.firstChildElement("m_renameFolder");

	QDomElement sourceFolder = RenameFolder.firstChildElement("m_sourceFolder");
	m_renameFolderData.m_sourceFolder = sourceFolder.text();
	QDomElement nameFilter = RenameFolder.firstChildElement("m_nameFilter");
	m_renameFolderData.m_nameFilter = nameFilter.text();
	QDomElement destFilter = RenameFolder.firstChildElement("m_destFilter");
	m_renameFolderData.m_destFilter = destFilter.text();
	QDomElement filterType = RenameFolder.firstChildElement("m_filterType");
	m_renameFolderData.m_filterType = filterType.text();
	QDomElement addNum = RenameFolder.firstChildElement("m_addNum");
	m_renameFolderData.m_addNum = addNum.text();
	QDomElement addTime = RenameFolder.firstChildElement("m_addTime");
	m_renameFolderData.m_addTime = addTime.text();
	QDomElement folderOnly = RenameFolder.firstChildElement("m_folderOnly");
	m_renameFolderData.m_folderOnly = folderOnly.text();
}

void Config::creatConfigFile()
{
	QFile CFile(CONFIGFILEPATH);
	if(true == CFile.exists())
	{
		return ;
	}

	QDomDocument CDomDocument;
	QString strHead = CSTRING_TO_QSTRING("version=\"1.0\" encoding=\"GB2312\"");
	CDomDocument.appendChild(CDomDocument.createProcessingInstruction(CSTRING_TO_QSTRING("xml"), strHead));
	QDomElement CRoot = CDomDocument.createElement(CSTRING_TO_QSTRING("root"));
	CDomDocument.appendChild(CRoot);

	QDomElement CConfig = CDomDocument.createElement(CSTRING_TO_QSTRING("m_config"));
	CRoot.appendChild(CConfig);
	QDomElement CSourceFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFolder"));
	CConfig.appendChild(CSourceFolder);
	QDomText sourceFolder = CDomDocument.createTextNode(DEFAULTSOURCEFOLDER);
	CSourceFolder.appendChild(sourceFolder);
	QDomElement CDestFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFolder"));
	CConfig.appendChild(CDestFolder);
	QDomText destFolder = CDomDocument.createTextNode(DEFAULTDESTFOLDER);
	CDestFolder.appendChild(destFolder);
	QDomElement CFileType = CDomDocument.createElement(CSTRING_TO_QSTRING("m_fileType"));
	CRoot.appendChild(CFileType);
	QDomElement CFileType1 = CDomDocument.createElement(CSTRING_TO_QSTRING("fileType"));
	QDomText fileType1 = CDomDocument.createTextNode("*.jpg");
	CFileType1.appendChild(fileType1);
	CFileType.appendChild(CFileType1);
	CFileType1 = CDomDocument.createElement(CSTRING_TO_QSTRING("fileType"));
	fileType1 = CDomDocument.createTextNode("*.png");
	CFileType1.appendChild(fileType1);
	CFileType.appendChild(CFileType1);
	CFileType1 = CDomDocument.createElement(CSTRING_TO_QSTRING("fileType"));
	fileType1 = CDomDocument.createTextNode("*.jpeg");
	CFileType1.appendChild(fileType1);
	CFileType.appendChild(CFileType1);
	CFileType1 = CDomDocument.createElement(CSTRING_TO_QSTRING("fileType"));
	fileType1 = CDomDocument.createTextNode("*.bmp");
	CFileType1.appendChild(fileType1);
	CFileType.appendChild(CFileType1);

	creatMoveFileConfig(CDomDocument,CRoot);
	creatRenameFileConfig(CDomDocument,CRoot);
	creatModifyFileConfig(CDomDocument,CRoot);
	creatRenameFolderConfig(CDomDocument,CRoot);
	

	if(false == CFile.open(QFile::WriteOnly | QIODevice::Text))
	{
		CFile.close();
		qDebug()<<CFile.errorString();
		return ;
	}

	QTextStream CoutStream(&CFile);
	CFile.reset();
	CDomDocument.save(CoutStream, 4, QDomNode::EncodingFromTextStream);
	CFile.close();

	return ;
}

void Config::creatMoveFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot)
{
	QDomElement CMoveFile = CDomDocument.createElement(CSTRING_TO_QSTRING("m_moveFile"));
	CRoot.appendChild(CMoveFile);
	QDomElement CMoveFileSourceFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFolder"));
	CMoveFile.appendChild(CMoveFileSourceFolder);
	QDomText moveFileSourceFolder = CDomDocument.createTextNode(DEFAULTSOURCEFOLDER);
	CMoveFileSourceFolder.appendChild(moveFileSourceFolder);
	QDomElement CMoveFileDestFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFolder"));
	CMoveFile.appendChild(CMoveFileDestFolder);
	QDomText moveFileDestFolder = CDomDocument.createTextNode(DEFAULTDESTFOLDER);
	CMoveFileDestFolder.appendChild(moveFileDestFolder);
	QDomElement CMoveFileFileType = CDomDocument.createElement(CSTRING_TO_QSTRING("m_fileType"));
	CMoveFile.appendChild(CMoveFileFileType);
	QDomText moveFileFileType = CDomDocument.createTextNode("allfile(*.*)");
	CMoveFileFileType.appendChild(moveFileFileType);
	QDomElement CMoveFileOriginalFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_originalFolder"));
	CMoveFile.appendChild(CMoveFileOriginalFolder);
	QDomText moveFileOriginalFolder = CDomDocument.createTextNode("0");
	CMoveFileOriginalFolder.appendChild(moveFileOriginalFolder);
}

void Config::creatRenameFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot)
{
	QDomElement CRenameFile = CDomDocument.createElement(CSTRING_TO_QSTRING("m_renameFile"));
	CRoot.appendChild(CRenameFile);
	QDomElement CRenameFileSourceFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFolder"));
	CRenameFile.appendChild(CRenameFileSourceFolder);
	QDomText renameFileSourceFolder = CDomDocument.createTextNode(DEFAULTSOURCEFOLDER);
	CRenameFileSourceFolder.appendChild(renameFileSourceFolder);
	QDomElement CRanameFileDestFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFolder"));
	CRenameFile.appendChild(CRanameFileDestFolder);
	QDomText renameFileDestFolder = CDomDocument.createTextNode(DEFAULTDESTFOLDER);
	CRanameFileDestFolder.appendChild(renameFileDestFolder);
	QDomElement CRenameFileSourceFileName = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFileName"));
	CRenameFile.appendChild(CRenameFileSourceFileName);
	QDomText renameFileSourceFileName = CDomDocument.createTextNode("NG");
	CRenameFileSourceFileName.appendChild(renameFileSourceFileName);
	QDomElement CRanameFileDestFileName = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFileName"));
	CRenameFile.appendChild(CRanameFileDestFileName);
	QDomText renameFileDestFileName = CDomDocument.createTextNode("NG");
	CRanameFileDestFileName.appendChild(renameFileDestFileName);
	QDomElement CRanameFileFileType = CDomDocument.createElement(CSTRING_TO_QSTRING("m_fileType"));
	CRenameFile.appendChild(CRanameFileFileType);
	QDomText ranameFileFileType = CDomDocument.createTextNode("allfile(*.*)");
	CRanameFileFileType.appendChild(ranameFileFileType);
	QDomElement CRenameFileSelfFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_selfFolder"));
	CRenameFile.appendChild(CRenameFileSelfFolder);
	QDomText renameFileSelfFolder = CDomDocument.createTextNode("0");
	CRenameFileSelfFolder.appendChild(renameFileSelfFolder);

}	

void Config::creatModifyFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot)
{
	QDomElement CModifyFile = CDomDocument.createElement(CSTRING_TO_QSTRING("m_modifyFile"));
	CRoot.appendChild(CModifyFile);
	QDomElement CModifyFileSourceFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFolder"));
	CModifyFile.appendChild(CModifyFileSourceFolder);
	QDomText modifyFileSourceFolder = CDomDocument.createTextNode(DEFAULTSOURCEFOLDER);
	CModifyFileSourceFolder.appendChild(modifyFileSourceFolder);
	QDomElement CModifyFileDestFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFolder"));
	CModifyFile.appendChild(CModifyFileDestFolder);
	QDomText modifyFileDestFolder = CDomDocument.createTextNode(DEFAULTDESTFOLDER);
	CModifyFileDestFolder.appendChild(modifyFileDestFolder);
	QDomElement CModifyFileSourceFileFormat = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFileFormat"));
	CModifyFile.appendChild(CModifyFileSourceFileFormat);
	QDomText modifyFileSourceFileFormat = CDomDocument.createTextNode("*.png");
	CModifyFileSourceFileFormat.appendChild(modifyFileSourceFileFormat);
	QDomElement CModifyFileDestFileFormat = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFileFormat"));
	CModifyFile.appendChild(CModifyFileDestFileFormat);
	QDomText modifyFileDestFileFormat = CDomDocument.createTextNode("*.png");
	CModifyFileDestFileFormat.appendChild(modifyFileDestFileFormat);
	QDomElement CModiyFileFormate = CDomDocument.createElement(CSTRING_TO_QSTRING("m_modifyFormate"));
	CModifyFile.appendChild(CModiyFileFormate);
	QDomText modifyFileFormat = CDomDocument.createTextNode("0");
	CModiyFileFormate.appendChild(modifyFileFormat);
	QDomElement CModiyFileSize = CDomDocument.createElement(CSTRING_TO_QSTRING("m_modifySize"));
	CModifyFile.appendChild(CModiyFileSize);
	QDomText modifyFileSize = CDomDocument.createTextNode("0");
	CModiyFileSize.appendChild(modifyFileSize);
	QDomElement CModiyFileLeft = CDomDocument.createElement(CSTRING_TO_QSTRING("m_left"));
	CModifyFile.appendChild(CModiyFileLeft);
	QDomText modifyFileLeft = CDomDocument.createTextNode("0");
	CModiyFileLeft.appendChild(modifyFileLeft);
	QDomElement CModiyFileTop = CDomDocument.createElement(CSTRING_TO_QSTRING("m_top"));
	CModifyFile.appendChild(CModiyFileTop);
	QDomText modifyFileTop = CDomDocument.createTextNode("0");
	CModiyFileTop.appendChild(modifyFileTop);
	QDomElement CModiyFileWidth = CDomDocument.createElement(CSTRING_TO_QSTRING("m_width"));
	CModifyFile.appendChild(CModiyFileWidth);
	QDomText modifyFileWidth = CDomDocument.createTextNode("0");
	CModiyFileWidth.appendChild(modifyFileWidth);
	QDomElement CModiyFileHeight = CDomDocument.createElement(CSTRING_TO_QSTRING("m_height"));
	CModifyFile.appendChild(CModiyFileHeight);
	QDomText modifyFileHeight = CDomDocument.createTextNode("0");
	CModiyFileHeight.appendChild(modifyFileHeight);
}

void Config::creatRenameFolderConfig(QDomDocument &CDomDocument ,QDomElement &CRoot)
{
	QDomElement CRenameFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_renameFolder"));
	CRoot.appendChild(CRenameFolder);
	QDomElement CRenameFolderSourceFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_sourceFolder"));
	CRenameFolder.appendChild(CRenameFolderSourceFolder);
	QDomText renameFolderSourceFolder = CDomDocument.createTextNode(DEFAULTDESTFOLDER);
	CRenameFolderSourceFolder.appendChild(renameFolderSourceFolder);
	QDomElement CRenameFolderNameFolder = CDomDocument.createElement(CSTRING_TO_QSTRING("m_nameFilter"));
	CRenameFolder.appendChild(CRenameFolderNameFolder);
	QDomText renameFolderNameFolder = CDomDocument.createTextNode("");
	CRenameFolderNameFolder.appendChild(renameFolderNameFolder);
	QDomElement CRenameFolderDestFilter = CDomDocument.createElement(CSTRING_TO_QSTRING("m_destFilter"));
	CRenameFolder.appendChild(CRenameFolderDestFilter);
	QDomText renameFolderDestFilter = CDomDocument.createTextNode("");
	CRenameFolderDestFilter.appendChild(renameFolderDestFilter);
	QDomElement CRenameFolderFilterType = CDomDocument.createElement(CSTRING_TO_QSTRING("m_filterType"));
	CRenameFolder.appendChild(CRenameFolderFilterType);
	QDomText renameFolderFilterType = CDomDocument.createTextNode("allfile(*.*)");
	CRenameFolderFilterType.appendChild(renameFolderFilterType);
	QDomElement CRenameFolderAddNum = CDomDocument.createElement(CSTRING_TO_QSTRING("m_addNum"));
	CRenameFolder.appendChild(CRenameFolderAddNum);
	QDomText renameFolderAddNum = CDomDocument.createTextNode("0");
	CRenameFolderAddNum.appendChild(renameFolderAddNum);
	QDomElement CRenameFolderAddTime = CDomDocument.createElement(CSTRING_TO_QSTRING("m_addTime"));
	CRenameFolder.appendChild(CRenameFolderAddTime);
	QDomText renameFolderAddTime = CDomDocument.createTextNode("0");
	CRenameFolderAddTime.appendChild(renameFolderAddTime);
	QDomElement CRenameFolderFolderOnly = CDomDocument.createElement(CSTRING_TO_QSTRING("m_folderOnly"));
	CRenameFolder.appendChild(CRenameFolderFolderOnly);
	QDomText renameFolderFolderOnly = CDomDocument.createTextNode("0");
	CRenameFolderFolderOnly.appendChild(renameFolderFolderOnly);
}

QString Config::getSourceFolder()
{
	return m_sourceFolder;
}
QString Config::getDestFolder()
{
	return m_destFolder;
}

QStringList Config::getFileFormat()
{
	return m_fileFormat;
}

MoveFileData Config::getmoveFileData()
{
	return m_moveFileData;
}

RenameFileData Config::getrenameFileData()
{
	return m_renameFileData;
}

ModifyFileData Config::getmodifyFileData()
{
	return m_modifyFileData;
}

RenameFolderData Config::getrenameFolderData()
{
	return m_renameFolderData;
}

bool Config::updateConfigFile(QString tagName,QString field,QString value)
{
	QFile CFile(CONFIGFILEPATH);
	if(true != CFile.exists())
	{
		return false;
	}

	if(false == CFile.open(QFile::ReadOnly | QIODevice::Text))
	{
		CFile.close();
		return false;
	}

	QDomDocument CDomDocument;
	QString strErrorText;
	int nRow = 0, nColumn=0;
	if(false == CDomDocument.setContent(&CFile, false, &strErrorText, &nRow, &nColumn))
	{
		CFile.close();
		return false;
	}
	CFile.close();

	QDomElement CRoot = CDomDocument.documentElement();
	QDomElement tag = CRoot.firstChildElement(tagName);
	QDomElement fiels = tag.firstChildElement(field);
	QDomNode oldNode = fiels.firstChild();
	
	if(!oldNode.isNull())
	{
		fiels.firstChild().setNodeValue(value);
		QDomNode newNode = fiels.firstChild();
		fiels.replaceChild(newNode,oldNode);
	}
	else
	{
		QDomText newDomText = CDomDocument.createTextNode(value);
		fiels.appendChild(newDomText);
	}

	if(false == CFile.open(QFile::WriteOnly | QIODevice::Text))
	{
		CFile.close();
		return false;
	}

	QTextStream CoutStream(&CFile);
	//CFile.reset();
	CDomDocument.save(CoutStream, 4);
	CFile.close();

	return true;
}

void Config::onSourceFolderChanged(const QString &sourceFolder)
{
	QDir dir(sourceFolder);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_sourceFolder);
		return;
	}
	m_sourceFolder = sourceFolder;
	updateConfigFile("m_config","m_sourceFolder",m_sourceFolder);
}

void Config::onDestFolderChanged(const QString &DestFolser)
{
	QDir dir(DestFolser);
	if(!dir.exists())
	{
		QMessageBox::information(NULL, "Information", "please select legal source folder!");
		ui.lineEdit_sourceFolder->setText(m_destFolder);
		return;
	}
	m_destFolder = DestFolser;
	updateConfigFile("m_config","m_destFolder",m_destFolder);
}

void Config::onBrowseSourFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("Source Image Folder"),m_sourceFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_sourceFolder->setText(strSrcDir);

	return;
}

void Config::onBrowseDestFolder()
{
	QString strSrcDir = QFileDialog::getExistingDirectory(this, tr("dest Image Folder"),m_destFolder);
	if ("" == strSrcDir)
	{
		return;
	}
	ui.lineEdit_destFolder->setText(strSrcDir);
}