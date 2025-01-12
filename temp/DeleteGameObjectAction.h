#pragma once

#include "Action.h"

class DeleteGameObjectAction : public Action
{
	// Always add action parameters as private data members

	// [Action Parameters]
	CellPosition ObjectPos;   // 2- The end position of the ladder

	// Note: These parameters should be read in ReadActionParameters()

public:

	DeleteGameObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads DeleteGameObjectAction action parameters 

	virtual void Execute(); 


	virtual ~DeleteGameObjectAction(); // Virtual Destructor

};

