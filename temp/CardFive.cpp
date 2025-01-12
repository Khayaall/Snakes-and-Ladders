#include "CardFive.h"
//Ziyad
CardFive::CardFive(CellPosition& pos) :Card(pos) {
	cardNumber = 5;
}

//void CardFive::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
//}
//
//void CardFive::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//
//
//}

Card* CardFive::PasteOldParameters(CellPosition pos)
{
	CardFive* ptr = new CardFive(pos);
	return ptr;
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer) {
	Card::Apply(pGrid, pPlayer);

	int x = pPlayer->GetJustRolledDice();

	pGrid->PrintErrorMessage("You return the same number you just rolled,click to continue");
	int newCell = pPlayer->GetCell()->GetCellPosition().GetCellNum() - x;

	if (CellPosition::GetCellPositionFromNum(newCell).IsValidCell())
		pGrid->UpdatePlayerCell(pPlayer, CellPosition::GetCellPositionFromNum(newCell));
}