#pragma once

#include "Action.h"

class CopyCardAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition CardPos;
	Card* pCopy;
	// Note: These parameters should be read in ReadActionParameters()

public:

	CopyCardAction(ApplicationManager* pApp); // A Constructor

	void CopyCardAction::ReadActionParameters(); //Reads action of user

	virtual void Execute(); // Creates a new card Object 
	// then Sets this card object to the ClipBoard in Grid class
	//then deletes the selected object


	virtual ~CopyCardAction(); // Virtual Destructor

};
