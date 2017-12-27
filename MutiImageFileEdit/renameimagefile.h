#ifndef RENAMEIMAGEFILE_H
#define RENAMEIMAGEFILE_H

#include <QDialog>
#include "ui_renameimagefile.h"
#include "commonheader.h"

class RenameImageFile : public QDialog
{
	Q_OBJECT

public:
	RenameImageFile(QWidget *parent = 0);
	~RenameImageFile();

	void init();

private:
	void setUpConnection();
	void initUI();
	void initData();
	void initCombox();
	void renameImageFile(QString sourceFolder,QString destFolder);
	void getFileCount(QString sourceFolder);
	QStringList getNameFilter();

public slots:
	void onSourceFolderChanged(const QString &sourceFolder);
	void onDestFolderChanged(const QString &DestFolser);
	void onSourceFileNameChanged(const QString &sourceFileName);
	void onDestFileNameChanged(const QString &destFileName);

	void onFileTypeChanged(int index);

	void onBrowseSourFolder();
	void onBrowseDestFolder();
	void onSelfFolder();
	void onExecute();
	

private:
	Ui::RenameImageFileClass ui;
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_sourceFileName;
	QString m_destFileName;
	QString m_fileType;
	bool m_selfFolderIsCkecked;
	int m_fileCount;

	static int imageFileCount;
};

#endif // RENAMEIMAGEFILE_H
