#include "CardSix.h"
//Ziyad
CardSix::CardSix(CellPosition& p) :Card(p) {
	cardNumber = 6;
}
void CardSix::ReadCardParameters(Grid* pGrid) {

	pGrid->GetOutput()->PrintMessage("Please, Click on the destination cell");
	cellToMove = pGrid->GetInput()->GetCellClicked();

	CardSix* ptr = dynamic_cast<CardSix*>(pGrid->GetCellFromCellPosition(cellToMove)->GetGameObject());
	while (cellToMove.GetCellNum() == position.GetCellNum() || ptr)
	{
		pGrid->GetOutput()->PrintMessage("The destination cell can't be a Card6,click on another cell");
		cellToMove = pGrid->GetInput()->GetCellClicked();
		ptr = dynamic_cast<CardSix*>(pGrid->GetCellFromCellPosition(cellToMove)->GetGameObject());
	}
	pGrid->GetOutput()->ClearStatusBar();
}

Card* CardSix::PasteOldParameters(CellPosition pos)
{
	CardSix* ptr = new CardSix(pos);
	ptr->cellToMove = cellToMove;
	return ptr;
}

//void CardSix::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << cellToMove.GetCellNum() << endl;
//}
//void CardSix::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	int cellNum = cellToMove.GetCellNum();
//	Infile >> vstart >> h >> cellNum;
//
//	cellToMove = CellPosition(cellNum);
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//}
void CardSix::Apply(Grid* pGrid, Player* pPlayer) {

	Card::Apply(pGrid, pPlayer);

	pGrid->PrintErrorMessage("You go to cell number " + to_string(cellToMove.GetCellNum()) + ", click to continue...");
	pGrid->UpdatePlayerCell(pPlayer, cellToMove);
}