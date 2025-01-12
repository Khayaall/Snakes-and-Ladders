#pragma once

#include "Action.h"

class PasteCardAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition PastePos;
	Card* pCard;
	// Note: These parameters should be read in ReadActionParameters()

public:

	PasteCardAction(ApplicationManager* pApp); // A Constructor

	void PasteCardAction::ReadActionParameters(); //Reads action of user

	virtual void Execute(); // Creates a new card Object 
	// then Sets this card object to the ClipBoard in Grid class


	virtual ~PasteCardAction(); // Virtual Destructor

};
