#pragma once
#include "Card.h"
//Ziyad
class CardFive : public Card
{
public:
	CardFive(CellPosition&);
	virtual void Apply(Grid*, Player*);
	Card* PasteOldParameters(CellPosition);

	
};
