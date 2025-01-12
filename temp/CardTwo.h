#pragma once
#include "Card.h"
//Ziyad
class CardTwo : public Card
{
public:
	CardTwo(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	
	Card* PasteOldParameters(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardTwo();
};
