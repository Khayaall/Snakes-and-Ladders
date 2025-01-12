#include "CutCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void CutCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Cut Card: Click on a Cell to cut ...");
	CardPos = pIn->GetCellClicked();
	if (CardPos.IsValidCell() != true) {
		pGrid->PrintErrorMessage("Error: The Cell is invalid! Click to continue ...");
		CardPos = CellPosition(-1, -1);
		return;
	}

	if (pGrid->GetCellFromCellPosition(CardPos)->HasCard() == NULL) {
		pGrid->PrintErrorMessage("Error: The Cell you clicked on doesn't have a card! Click to continue ...");
		CardPos = CellPosition(-1, -1);
		return;
	}

	pOut->ClearStatusBar();

}
void CutCardAction::Execute()
{
	ReadActionParameters();

	if (CardPos.HCell() == -1 || CardPos.VCell() == -1)
		return;

	// Create a Card object with the parameters of the previously present card by calling a function from grid 
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	pCard = pGrid->GetCardFromPos(CardPos);
	pGrid->SetClipboard(pCard);
	pGrid->RemoveObjectFromCell(CardPos);
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Card Cut Successfully");

}




CutCardAction::~CutCardAction() {

}