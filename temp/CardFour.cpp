#include "CardFour.h"
//Ziyad
CardFour::CardFour(const CellPosition& pos) : Card(pos)
{
	cardNumber = 4;
}

CardFour::~CardFour(void) {}

void CardFour::ReadCardParameters(Grid* pGrid) {}

Card* CardFour::PasteOldParameters(CellPosition pos)
{
	CardFour* ptr = new CardFour(pos);
	return ptr;
}

//void CardFour::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
//}
//void CardFour::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	//here we add a fuction that makes the player loses his turn then make the data member (prevented) of class player
	pGrid->PrintErrorMessage("You lose your next turn, click to continue...");
	pPlayer->SetTurnstoSkip(1);
}
