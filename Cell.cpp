#include "Cell.h"


void Create(CELL* currentCell, const char* insertNum)
{
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	strcpy_s(newCell->val, insertNum);

	newCell->prev = currentCell;
	
	newCell->next = currentCell->next;

	if (currentCell->next)
	{
		CELL* nextCell = currentCell->next;
		nextCell->prev = newCell;
	}

	currentCell->next = newCell;
}

void Index(CELL* cellStart)
{
	int no = 0;
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		printf(" %d:", no);
		printf("\"%s\"", cellStart->val);
		no++;

		if (cellStart->next)
		{
			printf(",\n");
		}
	}

	printf("\n");
}

CELL* GetInsertCellAddres(CELL* cellStart, int cellNum)
{
	for (int i = 0; i < cellNum + 1; i++)
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

void DeleteCell(CELL* currentCell)
{
	if (currentCell->prev)
	{
		currentCell->prev->next = currentCell->next;
	}

	if (currentCell->next)
	{
		currentCell->next->prev = currentCell->prev;
	}

	delete currentCell;
}

void EditCell(CELL* currentCell, const char* insertNum)
{
	strcpy_s(currentCell->val, insertNum);
}

int GetCellSize(CELL* cellStart)
{
	int count = 0;

	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
		count++;
	}

	return count;
}