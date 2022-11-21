#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* prev = nullptr;
	struct cell* next = nullptr;//構造体

}CELL;

void Create(CELL* currentCell, int insertNum)
{
	CELL* newCell;
	//メモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = insertNum;
	newCell->prev = currentCell;
	newCell->next = currentCell->next;

	//挿入
	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}
	currentCell->next = newCell;
}

void Index(CELL* cellStart)
{
	int no = 1;
	//出力
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		printf("no:%d ", no);
		printf("prev:%p ", cellStart->prev);
		printf("val:%5d ", cellStart->val);//五桁右揃え
		printf("this:(%p) ", cellStart);
		printf("next:%p \n", cellStart->next);
		no++;
	}
}

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum)
{
	for (int i = 0; i < cellNum - 1; i++)
	{
		if (cellStart->next)
		{
			cellStart = cellStart->next;
		}
		else
		{
			break;
		}
	}
	return cellStart;
}

void DeleteCell(CELL* cellStart, int cellNum)
{
	for (int i = 0; i < cellNum; i++)
	{
		if (cellStart->next)
		{
			cellStart = cellStart->next;
		}
		else
		{
			break;
		}
	}
	cellStart->prev->next = cellStart->next;
	cellStart->next->prev = cellStart->prev;

	delete cellStart;
}


void EditCell(CELL* cellStart, int cellNum, int insertNum)
{
	for (int i = 0; i < cellNum; i++)
	{
		if (cellStart->next)
		{
			cellStart = cellStart->next;
		}
		else
		{
			break;
		}
	}
	cellStart->val = insertNum;
}


int main()
{
	CELL cellStart;

	for (int i = 0; i < 10; i++)
	{
		Create(GetInsertCellAddres(&cellStart, i + 1), i + 1);
	}
	Create(GetInsertCellAddres(&cellStart, 6), 200112);
	Index(&cellStart);

	system("pause");
	return 0;
}