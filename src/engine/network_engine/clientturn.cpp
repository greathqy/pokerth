/***************************************************************************
 *   Copyright (C) 2007 by Lothar May                                      *
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
#include "clientturn.h"
#include <game_defs.h>
#include <handinterface.h>

//using namespace std;

ClientBeRoTurn::ClientBeRoTurn(HandInterface* bR, int id, int qP, int dP, int sB)
: myHand(bR), myID(id), actualQuantityPlayers(qP), dealerPosition(dP), smallBlindPosition(0), smallBlind(sB), highestSet(0), firstTurnRun(1), firstTurnRound(1), playersTurn(dP)
{
}

ClientBeRoTurn::~ClientBeRoTurn()
{
}

int
ClientBeRoTurn::getMyBeRoID() const
{
	return GAME_STATE_TURN;
}

void
ClientBeRoTurn::setPlayersTurn(int theValue)
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	playersTurn = theValue;
}

int
ClientBeRoTurn::getPlayersTurn() const
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	return playersTurn;
}

void
ClientBeRoTurn::setHighestSet(int theValue)
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	highestSet = theValue;
}

int
ClientBeRoTurn::getHighestSet() const
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	return highestSet;
}

void
ClientBeRoTurn::setFirstTurnRound(bool theValue)
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	firstTurnRound = theValue;
}

bool
ClientBeRoTurn::getFirstTurnRound() const
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	return firstTurnRound;
}

void
ClientBeRoTurn::setSmallBlindPosition(int theValue)
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	smallBlindPosition = theValue;
}

int
ClientBeRoTurn::getSmallBlindPosition() const
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	return smallBlindPosition;
}

void
ClientBeRoTurn::setSmallBlind(int theValue)
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	smallBlind = theValue;
}

int
ClientBeRoTurn::getSmallBlind() const
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	return smallBlind;
}

void
ClientBeRoTurn::resetFirstRun()
{
	boost::recursive_mutex::scoped_lock lock(m_syncMutex);
	firstTurnRun = false;
}

void
ClientBeRoTurn::run()
{
}

