
#pragma once

#include "Action.h"

class SwitchToPlayModeAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	string decission;
	// Note: These parameters should be read in ReadActionParameters()

public:

	SwitchToPlayModeAction(ApplicationManager* pApp); // A Constructor

	void SwitchToPlayModeAction::ReadActionParameters(); //Reads action of user

	virtual void Execute(); // Creates a new card Object 
	// then Sets this card object to the ClipBoard in Grid class


	virtual ~SwitchToPlayModeAction(); // Virtual Destructor

};
