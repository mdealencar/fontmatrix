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
#include "typotekadaptator.h"
#include "typotek.h"
#include "fontitem.h"

TypotekAdaptator::TypotekAdaptator(QObject *parent)
 : QDBusAbstractAdaptor(parent)
{
}


TypotekAdaptator::~TypotekAdaptator()
{
}

void TypotekAdaptator::signal(int i, QString fontname)
{
	if (i == 1)
		emit activated(fontname);
	if( i == 0)
		emit desactivated(fontname);
	
}

void TypotekAdaptator::lock(QString fontname)
{
	typotek::getInstance()->getFont(fontname)->lock();
}

void TypotekAdaptator::unlock(QString fontname)
{
	typotek::getInstance()->getFont(fontname)->unLock();
}

