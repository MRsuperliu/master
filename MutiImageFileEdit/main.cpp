#include <QtGui/QApplication>
#include <QProcess>
#include "mutiimagefileedit.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MutiImageFileEdit w;
	w.show();

	int nCode = a.exec();
	if(nCode == EXIT_CODE_REBOOT)
	{
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
	}
	return nCode;
}
