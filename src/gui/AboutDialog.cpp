/*
Copyright (C) 2016  The AlterPCB team
Contact: Maarten Baert <maarten-baert@hotmail.com>

This file is part of AlterPCB.

AlterPCB is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

AlterPCB is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this AlterPCB.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "AboutDialog.h"

#include "GlobalDirs.h"

#include <cholmod.h>

#include <sstream>

std::string GetVersionInfo() {
	std::ostringstream ss;
	ss << "AlterPCB-TLineSim " << ALTERPCB_VERSION << "\n";

#if defined(__clang__)
	ss << "Compiled with Clang " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << "\n";
#elif defined(__MINGW32__)
	ss << "Compiled with MinGW " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
#elif defined(__GNUC__)
	ss << "Compiled with GCC " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << "\n";
#else
	ss << "Compiled with unknown compiler.\n";
#endif

	ss << "Qt: header " << QT_VERSION_STR << ", lib " << qVersion() << "\n";

#ifdef CHOLMOD_HAS_VERSION_FUNCTION
	int cholmod_ver[3];
	cholmod_version(cholmod_ver);
	ss << "CHOLMOD: header " << CHOLMOD_MAIN_VERSION << "." << CHOLMOD_SUB_VERSION << "." << CHOLMOD_SUBSUB_VERSION
	   << ", lib " << cholmod_ver[0] << "." << cholmod_ver[1] << "." << cholmod_ver[2] << "\n";
#else
	ss << "CHOLMOD: " << CHOLMOD_MAIN_VERSION << "." << CHOLMOD_SUB_VERSION << "." << CHOLMOD_SUBSUB_VERSION << "\n";
#endif



	return ss.str();
}

AboutDialog::AboutDialog(QWidget *parent)
	: QDialog(parent) {

	setWindowTitle(tr("About AlterPCB-TLineSim"));

	QString html_about;
	{
		QFile file(g_application_data_dir + "/about.htm");
		if(file.open(QIODevice::ReadOnly | QIODevice::Text))
			html_about = file.readAll();
	}

	html_about.replace("%VERSION%", ALTERPCB_VERSION);
	html_about.replace("%VERSIONINFO%", QString::fromStdString(GetVersionInfo()).replace("\n", "<br>\n"));

	QTextBrowser *textbrowser = new QTextBrowser(this);
	textbrowser->setHtml(html_about);
	textbrowser->setOpenExternalLinks(true);
	textbrowser->setMinimumSize(700, 500);

	QPushButton *pushbutton_close = new QPushButton("Close", this);

	connect(pushbutton_close, SIGNAL(clicked()), this, SLOT(accept()));

	QVBoxLayout *layout = new QVBoxLayout(this);
	layout->addWidget(textbrowser);
	{
		QHBoxLayout *layout2 = new QHBoxLayout();
		layout->addLayout(layout2);
		layout2->addStretch();
		layout2->addWidget(pushbutton_close);
		layout2->addStretch();
	}

}
