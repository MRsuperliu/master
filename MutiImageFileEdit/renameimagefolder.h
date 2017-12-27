#ifndef RENAMEIMAGEFOLDER_H
#define RENAMEIMAGEFOLDER_H

#include <QDialog>
#include "ui_renameimagefolder.h"
#include "commonheader.h"

class RenameImageFolder : public QDialog
{
	Q_OBJECT

public:
	RenameImageFolder(QWidget *parent = 0);
	~RenameImageFolder();
	void init();

private:
	void setUpConnection();
	void initUI();
	void initData();
	void initCombox();
	bool renameImageFolder(QString sourceFolder);
	bool undoLastEdit(QString sourceFolder);
	QStringList getNameFilter();

public slots:
	void onSourceFolderChanged(const QString &sourceFolder);
	void onNameFilterChanged(const QString &nameFilter);
	void onDestFilterChanged(const QString &nameFilter);

	void onFileTypeChanged(int index);
	void onAddNum();
	void onAddTime();
	void onFolderOnly();

	void onBrowseSourFolder();
	void onExecute();
	void onUndo();

private:
	Ui::RenameImageFolderClass ui;
	QString m_sourceFolder;
	QString m_nameFilter;
	QString m_fileType;
	QString m_destFilter;
	bool m_addNumIsChecked;
	bool m_addTimeIsChecked;
	bool m_FolderOnlyIsChecked;

	QString m_lastSourceFolder;
	QString m_lastNameFilter;
	QString m_lastFileType;
	bool m_lastAddNumIsChecked;
	bool m_lastAddTimeIsChecked;
};

#endif // RENAMEIMAGEFOLDER_H
