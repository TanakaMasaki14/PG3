#include <iostream>
#include <memory>
#include <Windows.h>
#include "SceneManager.h"

typedef struct cell
int main()
{
	int number = 0;
	const int maxNumber = 3;

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	while (true)
	{
		SceneManager::GetInstance()->ChangeScene(number);
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->val = insertNum;
	newCell->next = nullptr;

	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}
		number++;
		if (number > maxNumber)
		{
			number = 0;
		}
}
void Index(CELL* cellStart)
{
	while (cellStart->next != nullptr)
	{
		printf("%d\n", cellStart->val);
		cellStart = cellStart->next;
	}
	printf("%d\n", cellStart->val);
}

//----------------------------------------
typedef struct cellstr
{
	const char* str;

	struct cellstr* next = nullptr;

}CELLSTR;

void Create(CELLSTR* cellStart, const char* insertStr)
{
	CELLSTR* newCell;
	newCell = (CELLSTR*)malloc(sizeof(CELLSTR));

	newCell->str = insertStr;
	newCell->next = nullptr;

	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELLSTR* cellStart)
{
	while (cellStart->next != nullptr)
	{
		printf("%s\n", cellStart->str);
		cellStart = cellStart->next;
	}
	printf("%s\n", cellStart->str);
}

int main()
{
	CELL cellStart;
	cellStart.val = 1;

	for (int i = 0; i < 10; i++)
	{
		Create(&cellStart, i + 2);
	}

	Index(&cellStart);

	CELLSTR cellStrStart;
	cellStrStart.str = "スライム";
	Create(&cellStrStart, "ぶちスライム");
	Create(&cellStrStart, "メタルスライム");
	Create(&cellStrStart, "キングスライム");

	Index(&cellStrStart);

	system("pause");
	system("pause");
	return 0;
}