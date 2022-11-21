#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* next = nullptr;//構造体

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//新規作成するセル分のメモリを確保
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	newCell->next = nullptr;

	//最初のセルのアドレスが該当する
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELL* cellStart)
{
	//最後のセルになるまで出力
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

	//構造体
	struct cellstr* next = nullptr;

}CELLSTR;

void Create(CELLSTR* cellStart, const char* insertStr)
{
	CELLSTR* newCell;
	//新規作成するセル分のメモリを確保
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
	//最後のセルになるまで出力
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
	Create(&cellStrStart, "キングスライム");
	Create(&cellStrStart, "もりもりスライム");
	Create(&cellStrStart, "ぶちスライム");

	Index(&cellStrStart);

	system("pause");
	return 0;
}