#include "AddSnakeAction.h"
#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}



void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	if (startPos.IsValidCell() != true) { //Execute function checks validation but this is to print message to user
		pGrid->PrintErrorMessage("Error: The start Cell is invalid! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}

	if (pGrid->GetCellFromCellPosition(startPos)->HasCard() != NULL) {
		pGrid->PrintErrorMessage("Error: The start Cell cannot be a special cell (a card cell)! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}
	else if (startPos.VCell() == 8) {
		pGrid->PrintErrorMessage("Snake can't be in the first row ! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}





	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();


	if (startPos.IsValidCell() != true) { //Execute function checks validation but this is to print message to user
		pGrid->PrintErrorMessage("Error: The start Cell is invalid! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}


	if (startPos.HCell() != endPos.HCell()) {
		pGrid->PrintErrorMessage("Error: The start cell and the end cell must be in the same column! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;

	}


	if (startPos.VCell() > endPos.VCell()) {
		pGrid->PrintErrorMessage("Snake's start cell should be after end cell ! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;

	}
	if (startPos.HCell() == endPos.HCell() && startPos.VCell() == endPos.VCell())
	{
		pGrid->PrintErrorMessage("Error: The start cell and the end cell are the same! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;

	}
	 if (pGrid->thisColumnHasSnake(startPos, endPos) == 1) {
		pGrid->PrintErrorMessage("Error: Two snakes cannot overlap! Click to continue ...");
		startPos = CellPosition(-1, -1);
	}
	if (pGrid->GetCellFromCellPosition(endPos)->HasCard() != NULL) {
		pGrid->PrintErrorMessage("Error: The end Cell cannot be a special cell (a card cell)! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}
	if (pGrid->GetCellFromCellPosition(endPos)->HasSnake() != NULL) {
		pGrid->PrintErrorMessage("Error: The end Cell of a snake cannot be the start cell of a another snake! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}
	if (pGrid->GetCellFromCellPosition(endPos)->HasLadder() != NULL) {
		pGrid->PrintErrorMessage("Error: The end Cell cannot be the start cell of a ladder! Click to continue ...");
		startPos = CellPosition(-1, -1);
		return;
	}






	// Clear messages
	pOut->ClearStatusBar();
}



// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	if (startPos.HCell() == -1 || startPos.VCell() == -1)
		return;

	// Create a snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the Ladder object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the snake is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction
}
AddSnakeAction::~AddSnakeAction()
{
}
