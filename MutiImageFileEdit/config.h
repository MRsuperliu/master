#ifndef CONFIG_H
#define CONFIG_H

#include <QWidget>
#include<QtXml/QDomDocument>
#include <QtXml\QtXml>  
#include "ui_config.h"

struct MoveFileData
{
	QString m_moveFile;
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_fileType;
	QString m_originalFolder;

	MoveFileData():
	m_moveFile(QString(""))
	,m_sourceFolder(QString(""))
	,m_destFolder(QString(""))
	,m_fileType(QString(""))
	,m_originalFolder(QString(""))
	{

	}
};

struct RenameFileData
{
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_sourceFileName;
	QString m_destFileName;
	QString m_fileType;
	QString m_selfFolder;

	RenameFileData():
	m_sourceFolder(QString(""))
	,m_destFolder(QString(""))
	,m_sourceFileName(QString(""))
	,m_destFileName(QString(""))
	,m_fileType(QString(""))
	,m_selfFolder(QString(""))
	{

	}
};

struct ModifyFileData
{
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_sourceFileFormat;
	QString m_destFileFormat;
	QString m_modifyFormate;
	QString m_modifySize;
	QString m_left;
	QString m_top;
	QString m_width;
	QString m_height;

	ModifyFileData():
	m_sourceFolder(QString(""))
	,m_destFolder(QString(""))
	,m_sourceFileFormat(QString(""))
	,m_destFileFormat(QString(""))
	,m_modifyFormate(QString(""))
	,m_modifySize(QString(""))
	,m_left(QString(""))
	,m_top(QString(""))
	,m_width(QString(""))
	,m_height(QString(""))
	{

	}
};

struct RenameFolderData
{
	QString m_sourceFolder;
	QString m_nameFilter;
	QString m_destFilter;
	QString m_filterType;
	QString m_addNum;
	QString m_addTime;
	QString m_folderOnly;

	RenameFolderData():
	m_sourceFolder(QString(""))
	,m_nameFilter(QString(""))
	,m_destFilter(QString(""))
	,m_filterType(QString(""))
	,m_addNum(QString(""))
	,m_addTime(QString(""))
	,m_folderOnly(QString(""))
	{

	}
};

class Config : public QWidget
{
	Q_OBJECT

public:
	Config(QWidget *parent = 0);
	~Config();

	void init();
	static QString getSourceFolder();
	static QString getDestFolder();
	static QStringList getFileFormat();
	static MoveFileData getmoveFileData();
	static RenameFileData getrenameFileData();
	static ModifyFileData getmodifyFileData();
	static RenameFolderData getrenameFolderData();
	static bool updateConfigFile(QString module,QString field,QString value);

private:
	void setUpConnection();
	void initUI();
	void initData();
	void creatConfigFile();
	void creatMoveFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot);
	void creatRenameFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot);
	void creatModifyFileConfig(QDomDocument &CDomDocument ,QDomElement &CRoot);
	void creatRenameFolderConfig(QDomDocument &CDomDocument ,QDomElement &CRoot);

	void readConfigFile();
	void readDefaultConfig(QDomElement &CRoot);
	void readMoveFileConfig(QDomElement &CRoot);
	void readRenameFileConfig(QDomElement &CRoot);
	void readModifyFileConfig(QDomElement &CRoot);
	void readRenameFolderConfig(QDomElement &CRoot);

public slots:
	void onSourceFolderChanged(const QString &sourceFolder);
	void onDestFolderChanged(const QString &DestFolser);

	void onBrowseSourFolder();
	void onBrowseDestFolder();

private:
	Ui::ConfigClass ui;
	static QString m_sourceFolder;
	static QString m_destFolder;
	static QStringList m_fileFormat;

	static MoveFileData m_moveFileData;
	static RenameFileData m_renameFileData;
	static ModifyFileData m_modifyFileData;
	static RenameFolderData m_renameFolderData;

};

#endif // CONFIG_H
