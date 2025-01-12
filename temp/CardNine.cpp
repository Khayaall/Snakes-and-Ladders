#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos) :Card(pos)
{
	cardNumber = 9;
	owner = NULL;
}

void CardNine::ReadCardParameters(Grid* pGrid, int price, int fees)
{
	pGrid->AddObjectToCell(this);
	setprice(price);
	setfee(fees);
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
}

void CardNine::setprice(int p)
{
	price = p;
}

void CardNine::setfee(int gf)
{
	fee = gf;
}

void CardNine::setowner(Player* pp)
{
	owner = pp;
}

Player* CardNine::getowner()
{
	return owner;
}

int CardNine::getprice()
{
	return price;
}

int CardNine::getfee()
{
	return fee;
}
Card* CardNine::PasteOldParameters(const CellPosition PastePos) {
	Card* pNewCard = new CardNine(PastePos);

	((CardNine*)pNewCard)->price = this->price;
	((CardNine*)pNewCard)->fee = this->fee;
	((CardNine*)pNewCard)->owner = this->owner;

	return pNewCard;
}

