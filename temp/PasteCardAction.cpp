#include "PasteCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void PasteCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Paste Card: Click on a Cell to paste card in ...");
	PastePos = pIn->GetCellClicked();
	if (PastePos.IsValidCell() != true) {
		pGrid->PrintErrorMessage("Error: The Cell is invalid! Click to continue ...");
		PastePos = CellPosition(-1, -1);
		return;
	}

	if (pGrid->GetCellFromCellPosition(PastePos)->HasCard() != NULL) {
		pGrid->PrintErrorMessage("Error: The Cell you clicked on already has a card! Click to continue ...");
		PastePos = CellPosition(-1, -1);
		return;
	}
	if (pGrid->GetCellFromCellPosition(PastePos)->HasSnake() != NULL) {
		pGrid->PrintErrorMessage("Error: The Cell you clicked on is the start of a snake! Click to continue ...");
		PastePos = CellPosition(-1, -1);
		return;
	}
	if (pGrid->GetCellFromCellPosition(PastePos)->HasLadder() != NULL) {
		pGrid->PrintErrorMessage("Error: The Cell you clicked on is the start of a ladder!Click to continue ...");
		PastePos = CellPosition(-1, -1);
		return;
	}

	pOut->ClearStatusBar();

}
void PasteCardAction::Execute()
{
	ReadActionParameters();

	if (PastePos.HCell() == -1 || PastePos.VCell() == -1)
		return;

	// Create a Card object with the parameters of the previously present card by calling a function from grid 
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	Output* pOut = pGrid->GetOutput();
	pCard=pGrid->GetClipboard();
	Card* pNewCard = pCard->PasteOldParameters(PastePos); //Here we take the members(parameters) of copied card to the new one and create new card with entered position


	if (pCard == NULL) {
	
		pGrid->PrintErrorMessage("Error: No Copied Card!Click to continue ...");
		return;

	}
	else  pGrid->AddObjectToCell(pNewCard);



	pOut->PrintMessage("Card Pasted Successfully");


}




PasteCardAction::~PasteCardAction() {

}