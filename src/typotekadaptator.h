/***************************************************************************
 *   Copyright (C) 2007 by Pierre Marchand   *
 *   pierre@oep-h.com   *
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
#ifndef TYPOTEKADAPTATOR_H
#define TYPOTEKADAPTATOR_H

#include <QtDBus>
#include <QDBusAbstractAdaptor>

/**
	@author Pierre Marchand <pierre@oep-h.com>
*/
class TypotekAdaptator : public QDBusAbstractAdaptor
{

		Q_OBJECT
		Q_CLASSINFO ( "D-Bus Interface", "org.freedesktop.typotek.FontActivation" )
	public:
		TypotekAdaptator ( QObject *parent );

		~TypotekAdaptator();
	signals:
		void activated ( QString );
		void desactivated ( QString );

	public slots:
		void signal ( int i, QString fontname );

};

#endif
