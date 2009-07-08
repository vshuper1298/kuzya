/***************************************************************************
 *   Copyright (C) 2009 by Andriy Shevchyk   *
 *   sheva@sheva.immeditek   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef READSTDIN_H
#define READSTDIN_H

#include <QThread>

/**
	@author Andriy Shevchyk <sheva@sheva.immeditek>
*/
class ReadStdIn : public QThread
{
Q_OBJECT
public:
    ReadStdIn(QObject *parent = 0);
    ~ReadStdIn();
	void run();

        public:
            bool readKomand;

	signals:
	void commandAppeared(QString command);
};

#endif
