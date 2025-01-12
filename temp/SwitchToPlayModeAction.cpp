#include "SwitchToPlayModeAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void SwitchToPlayModeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Switching to Play Mode : Do you want to save current grid? enter(y)for yes and (n) for no");
	decission = pIn->GetSrting(pOut);
	
	pOut->ClearStatusBar();

}
void SwitchToPlayModeAction::Execute()
{
	ReadActionParameters();
	

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	

	if (!(decission == "y" || decission == "n")) {
		pGrid->PrintErrorMessage("Error : you entered wrong value! click to continue....");
		return;
	}

	if (decission == "y") {
		pManager->ExecuteAction(SAVE_GRID);
		pOut->ClearStatusBar();
		pOut->CreatePlayModeToolBar();
		pOut->PrintMessage("Grid saved Successfully,Switched to Play Mode Successfully");

	}
	else {
		pOut->ClearStatusBar();
		pOut->CreatePlayModeToolBar();
		pOut->PrintMessage("Switched to Play Mode Successfully");
	}

}




SwitchToPlayModeAction::~SwitchToPlayModeAction() {

}
