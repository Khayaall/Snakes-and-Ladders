#include "DeleteGameObjectAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"
DeleteGameObjectAction::DeleteGameObjectAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void DeleteGameObjectAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Delete Game Object: Click on its a Cell ...");
	ObjectPos = pIn->GetCellClicked();
	if (ObjectPos.IsValidCell() != true) {
		pGrid->PrintErrorMessage("Error: The start Cell is invalid! Click to continue ...");
		ObjectPos = CellPosition(-1, -1);
		return;
	}
	if (pGrid->GetCellFromCellPosition(ObjectPos)->GetGameObject() == NULL) {
		pGrid->PrintErrorMessage("Error: The Cell Doesn't have an object! Click to continue ...");
		ObjectPos = CellPosition(-1, -1);
		return;
	
	
	}

	pOut->ClearStatusBar();

}
void DeleteGameObjectAction::Execute()
{
	ReadActionParameters();
	if (ObjectPos.HCell() == -1 || ObjectPos.VCell() == -1)
		return;
	Grid* pGrid = pManager->GetGrid();
	pGrid->RemoveObjectFromCell(ObjectPos);

	pGrid->GetOutput()->PrintMessage("Object has been successfully removed");

}




DeleteGameObjectAction::~DeleteGameObjectAction() {

}