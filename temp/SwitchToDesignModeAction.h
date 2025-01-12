
#pragma once

#include "Action.h"

class SwitchToDesignModeAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	string decission;
	// Note: These parameters should be read in ReadActionParameters()

public:

	SwitchToDesignModeAction(ApplicationManager* pApp); // A Constructor

	void SwitchToDesignModeAction::ReadActionParameters(); //Reads action of user

	virtual void Execute(); // Creates a new card Object 
	// then Sets this card object to the ClipBoard in Grid class


	virtual ~SwitchToDesignModeAction(); // Virtual Destructor

};
