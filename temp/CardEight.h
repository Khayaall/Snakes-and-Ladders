#pragma once
#include "Card.h"
//Ziyad
class CardEight : public Card
{
	int GoOut;
public:
	CardEight(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	Card* PasteOldParameters(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
	virtual ~CardEight();
};
