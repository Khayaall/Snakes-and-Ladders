#pragma once
#include"Card.h"
class CardNine : public Card
{
private:
	int price;
	int fee;
	Player* owner;
public:
	CardNine(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid, int price, int fees);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	void setprice(int p);
	void setfee(int gf);
	void setowner(Player* pp);
	Player* getowner();
	int getprice();
	int getfee();
	virtual Card* PasteOldParameters(const CellPosition PastePos);

};

