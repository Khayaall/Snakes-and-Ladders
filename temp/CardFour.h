#pragma once
#include "Card.h"
//Ziyad
class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	virtual Card* PasteOldParameters(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardFour();
};
