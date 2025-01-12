#pragma once

#include "Action.h"

class CutCardAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]

	CellPosition CardPos;
	Card* pCard;
	// Note: These parameters should be read in ReadActionParameters()

public:

	CutCardAction(ApplicationManager* pApp); // A Constructor

	void CutCardAction::ReadActionParameters(); //Reads action of user

	virtual void Execute(); // Creates a new card Object 
	// then Sets this card object to the ClipBoard in Grid class


	virtual ~CutCardAction(); // Virtual Destructor

};
#pragma once
