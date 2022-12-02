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

	//挿入用要素番号
	int num = 0;
	//挿入用
	char insertStr[128];
	//順番指定用
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

	//オーダーをクリア
	void ClearOrder();

	void ChangeState(CellState* cellState);
};



//--------------------------------------------------
//初期画面
class InitialState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//---------------------------------------------------
//要素の表示
class DisplayState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//----------------------------------------------------
//要素の編集
class EditState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//-----------------------------------------------------
//要素の挿入
class InsertState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//------------------------------------------------------
//要素の削除
class DeleteState : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};