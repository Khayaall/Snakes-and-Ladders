#include "Player.h"
#include "GameObject.h"

Player::Player(Cell* pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	TurnsToSkip = 0;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell* cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	this->wallet = wallet;
	// Make any needed validations
	if (wallet >= 0)
		this->wallet = wallet;
	else
		this->wallet = 0;       //Ziyad
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}
void Player::SetTurnCount(int t)
{
	if (t >= 0 && t < 3) {
		turnCount = t;
	}
}

void Player::TurnIncrement()
{
	turnCount++;
	if (turnCount == 3)
		turnCount = 0;
}

int Player::GetStepCount() const
{
	return stepCount;
}

void Player::SetStepCount(int cellNum)
{
	if (cellNum > 0 && cellNum <= NumVerticalCells * NumHorizontalCells)
		stepCount = cellNum;
}

void Player::SetTurnstoSkip(int turns)
{
	if (turns > 0)
	{
		TurnsToSkip = turns;
	}
}
int Player::GetPlayerNum() const {
	return playerNum;
}

int Player::GetJustRolledDice()const {
	return justRolledDiceNum;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];


	///use the appropriate output function to draw the player with "playerColor"
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor);      //Ziyad
}

void Player::ClearDrawing(Output* pOut) const
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;


	///use the appropriate output function to draw the player with "cellColor" (to clear it)
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor);      //Ziyad
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, int diceNumber)
{

	/// Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==


	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	TurnIncrement();

	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if (turnCount == 0) {
		wallet += diceNumber * 10;
		return;
	}

	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber;

	// Players can't move if their wallet is at 0
	if (wallet == 0)
	{
		pGrid->PrintErrorMessage("Player NO." + to_string(playerNum) + " doesn't have any coins so they can't move");
		return;
	}

	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	CellPosition pos = pCell->GetCellPosition();
	pos.AddCellNum(justRolledDiceNum);

	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	pGrid->UpdatePlayerCell(this, pos);

	// 6- Apply() the game object of the reached cell (if any)

	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if (GetStepCount() >= 94)
	{
		if (GetStepCount() + justRolledDiceNum == 100)
		{
			pGrid->SetEndGame(true);
			pGrid->UpdatePlayerCell(this, CellPosition::GetCellPositionFromNum(99));
			pGrid->PrintErrorMessage("Player No." + to_string(GetPlayerNum()) + " wins!");
			return;
		}
		else if (GetStepCount() + justRolledDiceNum > 100)
		{
			pGrid->PrintErrorMessage("More than 100, you need to reach exactly 100 to win!");
			return;
		}
	}
}
bool Player::IsPrevented() {
	
	return prevented;

}
void Player::Reset()
{
	SetWallet(100);                     // Initial Values for turncount , wallet and Prevented
	this->turnCount = 0;
	prevented = false;
}

void Player::AppendPlayerInfo(string& playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(";
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}