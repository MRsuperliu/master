#ifndef MODIFYIMAGEFILE_H
#define MODIFYIMAGEFILE_H

#include <QDialog>
#include "ui_modifyimagefile.h"
#include "commonheader.h"

class ModifyImageFile : public QDialog
{
	Q_OBJECT

public:
	ModifyImageFile(QWidget *parent = 0);
	~ModifyImageFile();

	void init();

private:
	void setUpConnection();
	void initUI();
	void initData();
	void initCombox();
	void ModifyImageFormat(QString sourceFolder,QString destFolder);
	void ModifyImageSize(QString sourceFolder,QString destFolder);
	void getFileCount(QString sourceFolder);
	QStringList getNameFilter();

public slots:
	void onSourceFolderChanged(const QString &sourceFolder);
	void onDestFolderChanged(const QString &DestFolser);

	void onSourceFileFormatChanged(int index);
	void onDestFileFormatChanged(int index);

	void onLeftChanged(const QString &left);
	void onTopChanged(const QString &top);
	void onWidthChanged(const QString &width);
	void onHeightChanged(const QString &height);

	void onBrowseSourFolder();
	void onBrowseDestFolder();
	void onModifyFileFormat();
	void onModifyFileSize();
	void onExecute();

private:
	Ui::ModifyImageFileClass ui;
	bool m_modifyFileFormatIsCheched;
	bool m_modifyFileSizeIsChecked;
	QString m_sourceFolder;
	QString m_destFolder;
	QString m_sourceFormat;
	QString m_destFormat;
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	int m_fileCount;

	static int imageFileCount;
};

#endif // MODIFYIMAGEFILE_H
