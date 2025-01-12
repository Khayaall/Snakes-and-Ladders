#include "CopyCardAction.h"
#include "Input.h"
#include "Output.h"
#include "Card.h"


CopyCardAction::CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void CopyCardAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("Copy Card: Click on a Cell having a card ...");
	CardPos = pIn->GetCellClicked();
	if (CardPos.IsValidCell() != true) {
		pGrid->PrintErrorMessage("Error: The Cell is invalid! Click to continue ...");
		CardPos = CellPosition(-1, -1);
		return;
	}

	if (pGrid->GetCellFromCellPosition(CardPos)->HasCard()==NULL) {
		pGrid->PrintErrorMessage("Error: The Cell you clicked on doesn't have a card! Click to continue ...");
		CardPos = CellPosition(-1, -1);
		return;
	}


	pOut->ClearStatusBar();

}
void CopyCardAction::Execute()
{
	ReadActionParameters();

	if (CardPos.HCell() == -1 || CardPos.VCell() == -1)
		return;

	// Create a Card object with the parameters of the previously present card by calling a function from grid 
	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	pCopy=pGrid->GetCardFromPos(CardPos);
	pGrid->SetClipboard(pCopy);
	Output* pOut=pGrid->GetOutput();
	pOut->PrintMessage("Card Copied Successfully");


}
	// Here, the copy of a card is created and added to the ClipBoard in Grid class, so we finished executing the CopyCardAction




CopyCardAction::~CopyCardAction() {

}