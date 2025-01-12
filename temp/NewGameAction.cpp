#include "NewGameAction.h"

#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{

}

void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();


	const CellPosition start(1);
	Player* p;


	for (int i = 0; i < MaxPlayerCount; i++)
	{

		p = pGrid->GetCurrentPlayer();

		p->Reset();

		pGrid->UpdatePlayerCell(p, start);

		pGrid->AdvanceCurrentPlayer();
	}

	pGrid->ResetGrid();
}