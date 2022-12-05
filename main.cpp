#include <stdio.h>
#include <string>
#include <iostream>

typedef struct cell
{
	char val[64];
	struct cell* next;
	struct cell* preview;
}CELL;

using namespace std;

CELL* CellAddress(CELL* endCELL, int iterator);
void create(CELL* begin, char val[64]);
void out(CELL* justCell);
void change(CELL* cellA, CELL* cellB);
void move(CELL* justCell, char val[64]);
void index(CELL* begin);
int GetSize(CELL* endCell);
void Begining();

int main()
{
	int InputVal;
	int select = 0;
	CELL initial;
	initial.next = nullptr;
	initial.preview = nullptr;

	while (true)
	{
		switch (select)
		{
		default:
			printf("\n[要素の操作]\n1. 要素の表示\n2. 要素の挿入\n");
			if (GetSize(&initial) > 0)
			{
				printf("3. 要素の編集\n4. 要素の削除\n5. 要素の並び替え(オプション)\n");
			}
			printf("\n------------------------\n操作を選択してください\n");
			scanf_s("%d", &InputVal);
			select = InputVal;
			break;

		case 1:
			printf("\n[要素の表示]\n1. 要素の一覧表示\n2. 順番を指定して要素を表示\n9. 要素選択に戻る\n\n操作を選択してください\n");
			scanf_s("%d", &InputVal);
			switch (InputVal)
			{
			case 1:
				printf("\n[要素の一覧表示]\n要素一覧: {\n");
				index(&initial);
				printf("}\n\n要素数: %d\n", GetSize(&initial));
				Begining();
				scanf_s("%d", &InputVal);
				if (InputVal == 2)
				{
					select = 0;
				}
				break;

			case 2:
				printf("\n[順番を指定して要素を表示]\n表示したい要素の順番を指定ください。\n");
				scanf_s("%d", &InputVal);

				if (GetSize(&initial) > InputVal && InputVal >= 0)
				{
					printf("\n%d: %s\n\n", InputVal, CellAddress(&initial, InputVal + 1)->val);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", InputVal);
				}
				Begining();
				scanf_s("%d", &InputVal);
				if (InputVal == 2)
				{
					select = 0;
				}
				break;

			case 9:
				select = 0;
			}
			break;

		case 2:
		{
			int itr;
			char val[64];

			string GetSelect;
			printf("\n[要素の挿入]\n要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください。\n");

			cin.clear();
			cin.ignore(1024, '\n');
			getline(cin, GetSelect);

			if (GetSelect == "")
			{
				itr = GetSize(&initial);
			}
			else
			{
				itr = stoi(GetSelect);
			}

			itr = max(min(itr, GetSize(&initial)), 0);

			printf("\n追加する要素の値を入力してください。\n");
			scanf_s("%s", val, 64);

			create(CellAddress(&initial, itr), val);
			printf("\n要素\"%s\"が%d番目に挿入されました。\n", val, itr);
		}
		select = 0;
		break;

		case 3:
			if (GetSize(&initial) > 0)
			{
				int itr;
				char val[64];
				printf("\n[要素の編集]\n編集したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					printf("\n%d番目の要素の変更する値を入力してください。\n", itr);
					scanf_s("%s", val, 64);

					move(CellAddress(&initial, itr + 1), val);
					printf("\n%d番目の要素の値が\"%s\"に変更されました。\n", itr, val);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			select = 0;
			break;

		case 4:
			if (GetSize(&initial) > 0)
			{
				int itr;
				printf("\n[要素の削除]\n削除したい要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					out(CellAddress(&initial, itr + 1));
					printf("\n%d番目の要素を削除しました。\n", itr);
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			select = 0;
			break;

		case 5:
			if (GetSize(&initial) > 0)
			{
				int itr;
				int itr2;

				printf("\n[要素の並び替え]\n入れ替える一方の要素の番号を指定してください。\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					printf("\n%d番目の要素と入れ替える要素の番号を指定してください。\n", itr);
					scanf_s("%d", &itr2);
					itr2 = max(0, itr2);
					if (GetSize(&initial) > itr2)
					{
						change(CellAddress(&initial, itr + 1), CellAddress(&initial, itr2 + 1));
						printf("\n%d番目の要素と%d番目の要素を入れ替えました。\n", itr, itr2);
					}
					else
					{
						printf("\n%d番目の要素が見つかりませんでした。\n", itr2);
					}
				}
				else
				{
					printf("\n%d番目の要素が見つかりませんでした。\n", itr);
				}
			}
			select = 0;
			break;
		}
	}
	return 0;
}

CELL* CellAddress(CELL* endCELL, int iterator)
{
	for (int i = 0; i < iterator; i++)
	{
		if (endCELL->next)
		{
			endCELL = endCELL->next;
		}
		else
		{
			break;
		}
	}
	return endCELL;
}

void create(CELL* JustCell, char val[64])
{
	CELL* newCell;
	newCell = (CELL*)malloc(sizeof(CELL));
	newCell->next = JustCell->next;
	newCell->preview = JustCell;
	strcpy_s(newCell->val, 64, val);

	if (JustCell->next)
	{
		CELL* NextCell = JustCell->next;
		NextCell->preview = newCell;
	}
	JustCell->next = newCell;
}

void out(CELL* JustCell)
{
	CELL* PreviewCell = JustCell->preview;
	PreviewCell->next = JustCell->next;

	if (JustCell->next)
	{
		CELL* NextCell = JustCell->next;
		NextCell->preview = JustCell->preview;
	}
	delete JustCell;
}

void move(CELL* JustCell, char val[64])
{
	strcpy_s(JustCell->val, 64, val);
}

void index(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		printf(" %d: %s\n", no, endCell->val);
		no++;
	}
}

int GetSize(CELL* endCell)
{
	int no = 0;
	while (endCell->next != nullptr)
	{
		endCell = endCell->next;
		no++;
	}
	return no;
}

void change(CELL* cellA, CELL* cellB)
{
	char ChangeVal[64];
	strcpy_s(ChangeVal, 64, cellA->val);
	strcpy_s(cellA->val, 64, cellB->val);
	strcpy_s(cellB->val, 64, ChangeVal);
}

void Begining()
{
	printf("------------------------\n1. 要素の表示に戻る\n2. 要素の操作に戻る\n");
}