#include "CardOne.h"

CardOne::CardOne(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

//void CardOne::Save(ofstream& OutFile)
//{
//	OutFile << GetCardNumber() << " " << position.VCell() << " " << position.HCell() << " " << walletAmount <<endl;
//}
//
//void CardOne::Load(ifstream& Infile)
//{
//	int vstart = -1, h = -1;
//
//	Infile >> vstart >> h >> walletAmount;
//	position.SetHCell(h);
//	position.SetVCell(vstart);
//}

CardOne::~CardOne(void)
{
}

void CardOne::SetWalletamount(int w)
{
	walletAmount = w;
}

void CardOne::ReadCardParameters(Grid* pGrid)
{


	///Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();  //Ziyad
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."
	pOut->PrintMessage("New CardOne: Enter its wallet amount ...");
	walletAmount = pIn->GetInteger(pOut);
	while (walletAmount < 1)
	{
		pOut->PrintMessage("You entered an invalid Number: Plase enter the wallet value to decrease from the player ...");
		walletAmount = pIn->GetInteger(pOut);
	}   //Ziyad

	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar
	pOut->ClearStatusBar(); //Ziyad
}



void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	///Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer); //Ziyad
	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne
	pGrid->PrintErrorMessage("You lose " + to_string(walletAmount) + " coins, click to continue");
	pPlayer->SetWallet(pPlayer->GetWallet() - walletAmount);   //Ziyad
}

Card* CardOne::PasteOldParameters(const CellPosition PastePos) {
	Card* pNewCard=new CardOne(PastePos);

	((CardOne*)pNewCard)->walletAmount = this->walletAmount;


	return pNewCard;
}
