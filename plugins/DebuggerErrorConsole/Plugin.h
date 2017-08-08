/*
Copyright (C) 2017 Ruslan Kabatsayev <b7.10110111@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEBUGGER_ERROR_CONSOLE_H_20170808
#define DEBUGGER_ERROR_CONSOLE_H_20170808

#include "IPlugin.h"
#include "edb.h"
#include <QDialog>

class QPlainTextEdit;

namespace DebuggerErrorConsole
{

class DebuggerErrorConsole : public QDialog
{
	Q_OBJECT

public:
	DebuggerErrorConsole(QWidget* parent=nullptr);
private Q_SLOTS:
	void compareDisassemblers();
};

class Plugin : public QObject, public IPlugin
{
	Q_OBJECT
	Q_INTERFACES(IPlugin)
#if QT_VERSION >= 0x050000
	Q_PLUGIN_METADATA(IID "edb.IPlugin/1.0")
#endif
	Q_CLASSINFO("author", "Ruslan Kabatsayev")
	Q_CLASSINFO("email", "b7.10110111@gmail.com")

	QPlainTextEdit* textWidget_=nullptr;
	QMenu* menu_=nullptr;
	static Plugin* instance;

	static void debugMessageIntercept(QtMsgType type, const char* messge);
public:
	Plugin();
	~Plugin();
	virtual QMenu* menu(QWidget* parent = 0) override;
};

}

#endif
