#include "SwitchToDesignModeAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void SwitchToDesignModeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Switching to design Mode : are you sure you want to end this game? enter(y)for yes and (n) for no");
	decission = pIn->GetSrting(pOut);
	if (!(decission == "y" || decission == "n"))
	{
		pGrid->PrintErrorMessage("Error: you entered wrong value! Click to continue ...");
		decission == "i";
	}
	pOut->ClearStatusBar();

}
void SwitchToDesignModeAction::Execute()
{
	ReadActionParameters();

	if (decission == "i")
		return;
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();


	if (decission == "y") {
		pOut->ClearStatusBar();
		pOut->PrintMessage("Switched to Design Mode Successfully");
		pOut->CreateDesignModeToolBar();
		pManager->ExecuteAction(NEW_GAME);


	}
}
SwitchToDesignModeAction::~SwitchToDesignModeAction() {

}
