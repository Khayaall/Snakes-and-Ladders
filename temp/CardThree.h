#pragma once

#include "Card.h"
#include "ApplicationManager.h"
//Ziyad
class CardThree : public Card
{
	ApplicationManager* pManager;

public:
	CardThree(const CellPosition& pos);

	virtual void ReadCardParameters(Grid* pGrid);
	Card* PasteOldParameters(CellPosition p);

	virtual void Apply(Grid* pGrid, Player* pPlayer);

	virtual ~CardThree();
};
