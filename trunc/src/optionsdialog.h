/******************************************************************************
 *   Copyright (C) 2008 by                                                    *
 *                     Victor Sklyar (bouyantgrambler@users.sourceforge.net), *
 *                     Alex Chmykhalo (alexchmykhalo@users.sourceforge.net)   *
 *                                                                            *
 *                                                                            *
 *   This program is free software: you can redistribute it and/or modify     *
 *   it under the terms of the GNU General Public License as published by     *
 *   the Free Software Foundation, either version 3 of the License, or        *
 *   (at your option) any later version.                                      *
 *                                                                            *
 *   This program is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            *
 *   GNU General Public License for more details.                             *
 *                                                                            *
 *   You should have received a copy of the GNU General Public License        *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>     *
 ******************************************************************************/

#ifndef OPTIONSDIALOG_H
#define OPTIONSDIALOG_H

#include <QObject>
#include <QDialog>
#include <QPalette>
#include <QSettings>
#include <QTranslator>
#include <QTextStream>
#include <QFile>
#include <QDir>
#include <QStyleFactory>
//#include "kuzya.h"
#include "ui_optionsdialog.h"
#include "kuzya.h"


class QsciScintilla;
class Kuzya;

/**
	@author Volodymyr Shevchyk <>
*/
class OptionsDialog : public QDialog, private Ui::optionsForm
{
Q_OBJECT
public:
    OptionsDialog(QWidget *parent = 0);
	~OptionsDialog();
	void writeSettings(void);
	void readODWSettings();	
	void openLastProject();
	void saveLastProjectName(QString);
	void retranslate(void);
        bool ukrIsCheked();

public slots:
	void slotCommOptions(void);
private slots:
	
	void slotClose(void);
	void slotApply(void);
	void slotOk(void);
        void slotChangeFont(void);
	void slotDefaultAll(void);
	void slotChangeFormColor(void);
	void slotChangeDefDir(int);
        void slotChangeStyle(int);
        void slotChangeSkin(QString);
      //  void slotLoadCompilerSettings(void);
        void slotUpdateSkinsCBox(void);
        void slotUpdateCompilerCBox(QString);
        void slotLoadCompilerOptions(QString);
        void slotChangeCompilerLocation();

private:
	QTranslator* trans_ua;
	QTranslator* trans_en;
        Kuzya* mw;
	QFile file;
        QSettings *settings;
	QsciScintilla* textEditor;
	QTranslator translator;
	QFont font;
        QDir stylesDir;
        QStringList filters;
public:	
    bool isLineMarginVisible;
	
private:
	
public: 
	
	
};

#endif
