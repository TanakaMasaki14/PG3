#include "CellManager.h"


void CellState::SetCellManager(CellManager* cellManager)
{
	this->cellManager = cellManager;
}

CellManager::CellManager()
{
	this->cell = new CELL();
	ChangeState(new InitialState);
}

CellManager::~CellManager()
{
	delete cell;
	delete cellState;
}

void CellManager::Update()
{
	cellState->Update();
}

void CellManager::Draw()
{
	cellState->Draw();
}

void CellManager::ClearOrder()
{
	for (int i = 0; i < _countof(order); i++)
	{
		order[i] = 0;
	}
}

void CellManager::ChangeState(CellState* cellState)
{
	delete this->cellState;
	this->cellState = cellState;
	this->cellState->SetCellManager(this);
}