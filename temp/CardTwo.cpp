#include "CardTwo.h"
#include "Ladder.h"

//Ziyad
CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

CardTwo::~CardTwo(void) {}

void CardTwo::ReadCardParameters(Grid* pGrid) {}

Card* CardTwo::PasteOldParameters(CellPosition pos)
{
	CardTwo* ptr = new CardTwo(pos);
	return ptr;
}

//void CardTwo::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
//}
//void CardTwo::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//
//
//}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("You go to the next ladder, click to continue...");
	Ladder* nextLadder = pGrid->GetNextLadder(pPlayer->GetCell()->GetCellPosition());
	if (nextLadder != NULL) {
		pGrid->UpdatePlayerCell(pPlayer, nextLadder->GetPosition());
		nextLadder->Apply(pGrid, pPlayer);
	}

}