#pragma once
#include "Cell.h"

class CellManager;

class CellState
{
protected:
	CellManager* cellManager = nullptr;

public:
	void SetCellManager(CellManager* cellManager);
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

class CellManager
{
private:
	CellState* cellState = nullptr;
	CELL* cell = nullptr;

	int num = 0;

	char insertStr[128];

	int order[100];

public:
	CellManager();
	~CellManager();

	void Update();
	void Draw();

	CELL* GetCell() { return cell; }
	int* GetNum() { return &num; }
	int* GetOrder() { return order; }
	const char* GetInsertStr() { return insertStr; }

	void SetNum(int num) { this->num = num; }
	void SetInsertStr(const char* str) { strcpy_s(insertStr, str); }

	void ClearOrder();

	void ChangeState(CellState* cellState);
};

class InitialState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

class DisplayState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

class EditState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

class InsertState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

class DeleteState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};