//
// C++ Interface: localberofactory
//
// Description: 
//
//
// Author: FThauer FHammer <webmaster@pokerth.net>, (C) 2007
//
// Copyright: See COPYING file that comes with this distribution
//
//
#ifndef LOCALBEROFACTORY_H
#define LOCALBEROFACTORY_H

#include <istream>

#include <vector>

#include <boost/shared_ptr.hpp>

#include <berofactoryinterface.h>
#include <berointerface.h>
#include <handinterface.h>

/**
	@author FThauer FHammer <webmaster@pokerth.net>
*/
class LocalBeRoFactory : public BeRoFactoryInterface
{
public:
    LocalBeRoFactory(HandInterface* hi, int id, int aP, int dP, int sB);

    ~LocalBeRoFactory();

	BeRoInterface* switchRounds(BeRoInterface*, int);

	BeRoInterface* createBeRoPreflop();

	std::vector<boost::shared_ptr<BeRoInterface> > createBeRo();


private:

    HandInterface* myHand;

	int myID;
	int actualQuantityPlayers;	
	int dealerPosition;
	int bigBlindPosition;

	int smallBlind;
	int highestSet;

	bool preflopFirstRound;
	int playersTurn;

};

#endif
