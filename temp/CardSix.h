#pragma once
#include "Card.h"
//Ziyad
class CardSix :public Card
{
	CellPosition cellToMove;

public:
	CardSix(CellPosition&);
	virtual void Apply(Grid*, Player*);
	virtual void ReadCardParameters(Grid*);
	Card* PasteOldParameters(CellPosition);
};
