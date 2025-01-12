#include "CardSeven.h"
#include "RollDiceAction.h"
//Ziyad
CardSeven::~CardSeven(void) {}

CardSeven::CardSeven(const CellPosition& pos) : Card(pos)
{
	cardNumber = 7;
}

void CardSeven::ReadCardParameters(Grid* pGrid) {}

Card* CardSeven::PasteOldParameters(CellPosition pos)
{
	CardSeven* ptr = new CardSeven(pos);
	return ptr;
}

//void CardSeven::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << endl;
//}
//void CardSeven::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("The next player returns to the start,click to continue");

	/*CellPosition NextPlayerCell = pGrid->GetNextCellWithPlayers(position);

	if (&NextPlayerCell != NULL)
	{
		pGrid->RestartPlayersOnCell(&NextPlayerCell);
	}*/
}