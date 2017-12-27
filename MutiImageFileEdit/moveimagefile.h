#ifndef MOVEIMAGEFILE_H
#define MOVEIMAGEFILE_H

#include <QDialog>
#include "ui_moveimagefile.h"
#include "commonheader.h"

class MoveImageFile : public QDialog
{
	Q_OBJECT

public:
	MoveImageFile(QWidget *parent = 0);
	~MoveImageFile();

	void init();

private:
	void setUpConnection();
	void initUI();
	void initData();
	void initCombox();
	void CopyImageFile(QString sourceFile,QString destFile);
	void CopyImageFile(QString sourceFile,QString destFile,QString dirHeader);
	void getFileCount(QString sourceFolder);
	QStringList getNameFilter();

public slots:
	void onSourceFolderChanged(const QString &sourceFolder);
	void onDestFolderChanged(const QString &DestFolser);

	void onFileTypeChanged(int index);
	void onOriginalFolder();

	void onBrowseSourFolder();
	void onBrowseDestFolder();
	void onExecute();

private:
	Ui::MoveImageFileClass ui;
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_fileType;
	bool m_originalFolderIsCkecked;
	int m_fileCount;

	static int imageFileCount;
};

#endif // MOVEIMAGEFILE_H
