#pragma once
#include"CellManager.h"

//要素があるとき1
class EditState2 : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};
//要素があるとき2
class EditState3 : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};

//要素がない時
class EditState4 : public CellState
{
private:


public:
	void Update() override;
	void Draw() override;
};