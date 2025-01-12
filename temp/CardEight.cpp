#include "CardEight.h"
//Ziyad
CardEight::CardEight(const CellPosition& pos) : Card(pos)
{
	cardNumber = 8;
}

CardEight::~CardEight(void)
{
}
//void CardEight::Save(ofstream& OutFile) {
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << GoOut << endl;
//}
//void CardEight::Load(ifstream& Infile) {
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h >> GoOut;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//}
void CardEight::ReadCardParameters(Grid* pGrid)
{

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Card 8: Enter the amount of coins needed to go out of the prison");
	GoOut = pIn->GetInteger(pOut);

	while (GoOut < 10)
	{
		pOut->PrintMessage("You entered an invalid amount. Plase enter the amount of coins needed to go out of the prison");
		GoOut = pIn->GetInteger(pOut);
	}
	pOut->ClearStatusBar();
}

Card* CardEight::PasteOldParameters(CellPosition pos)
{
	CardEight* ptr = new CardEight(pos);
	ptr->GoOut = GoOut;
	return ptr;
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Now you have to choose 1- Pay " + to_string(GoOut) + " coins and continue playing 2- Don't play for 3 turns");
	int x = pIn->GetInteger(pOut);
	while (x != 1 && x != 2)
	{
		pOut->PrintMessage("Invalid, please choose again: 1- Pay " + to_string(GoOut) + " coins and continue playing 2- Don't play for 3 turns");
		GoOut = pIn->GetInteger(pOut);
	}

	if (x == 1)
		pPlayer->SetWallet(pPlayer->GetWallet() - GoOut);

	if (x == 2)
		pPlayer->SetTurnstoSkip(3);
	pOut->ClearStatusBar();
}