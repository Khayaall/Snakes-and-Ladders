#pragma once

#include "Card.h"
#include "ApplicationManager.h"
//Ziyad
class CardSeven : public Card
{
	ApplicationManager* pManager;

public:
	CardSeven(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	Card* PasteOldParameters(CellPosition);

	virtual void Apply(Grid* pGrid, Player* pPlayer);
	
	virtual ~CardSeven();
};
