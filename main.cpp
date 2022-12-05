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
			printf("\n[�v�f�̑���]\n1. �v�f�̕\��\n2. �v�f�̑}��\n");
			if (GetSize(&initial) > 0)
			{
				printf("3. �v�f�̕ҏW\n4. �v�f�̍폜\n5. �v�f�̕��ёւ�(�I�v�V����)\n");
			}
			printf("\n------------------------\n�����I�����Ă�������\n");
			scanf_s("%d", &InputVal);
			select = InputVal;
			break;

		case 1:
			printf("\n[�v�f�̕\��]\n1. �v�f�̈ꗗ�\��\n2. ���Ԃ��w�肵�ėv�f��\��\n9. �v�f�I���ɖ߂�\n\n�����I�����Ă�������\n");
			scanf_s("%d", &InputVal);
			switch (InputVal)
			{
			case 1:
				printf("\n[�v�f�̈ꗗ�\��]\n�v�f�ꗗ: {\n");
				index(&initial);
				printf("}\n\n�v�f��: %d\n", GetSize(&initial));
				Begining();
				scanf_s("%d", &InputVal);
				if (InputVal == 2)
				{
					select = 0;
				}
				break;

			case 2:
				printf("\n[���Ԃ��w�肵�ėv�f��\��]\n�\���������v�f�̏��Ԃ��w�肭�������B\n");
				scanf_s("%d", &InputVal);

				if (GetSize(&initial) > InputVal && InputVal >= 0)
				{
					printf("\n%d: %s\n\n", InputVal, CellAddress(&initial, InputVal + 1)->val);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", InputVal);
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
			printf("\n[�v�f�̑}��]\n�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł��������B\n");

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

			printf("\n�ǉ�����v�f�̒l����͂��Ă��������B\n");
			scanf_s("%s", val, 64);

			create(CellAddress(&initial, itr), val);
			printf("\n�v�f\"%s\"��%d�Ԗڂɑ}������܂����B\n", val, itr);
		}
		select = 0;
		break;

		case 3:
			if (GetSize(&initial) > 0)
			{
				int itr;
				char val[64];
				printf("\n[�v�f�̕ҏW]\n�ҏW�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					printf("\n%d�Ԗڂ̗v�f�̕ύX����l����͂��Ă��������B\n", itr);
					scanf_s("%s", val, 64);

					move(CellAddress(&initial, itr + 1), val);
					printf("\n%d�Ԗڂ̗v�f�̒l��\"%s\"�ɕύX����܂����B\n", itr, val);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			select = 0;
			break;

		case 4:
			if (GetSize(&initial) > 0)
			{
				int itr;
				printf("\n[�v�f�̍폜]\n�폜�������v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					out(CellAddress(&initial, itr + 1));
					printf("\n%d�Ԗڂ̗v�f���폜���܂����B\n", itr);
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
				}
			}
			select = 0;
			break;

		case 5:
			if (GetSize(&initial) > 0)
			{
				int itr;
				int itr2;

				printf("\n[�v�f�̕��ёւ�]\n����ւ������̗v�f�̔ԍ����w�肵�Ă��������B\n");
				scanf_s("%d", &itr);
				itr = max(0, itr);
				if (GetSize(&initial) > itr)
				{
					printf("\n%d�Ԗڂ̗v�f�Ɠ���ւ���v�f�̔ԍ����w�肵�Ă��������B\n", itr);
					scanf_s("%d", &itr2);
					itr2 = max(0, itr2);
					if (GetSize(&initial) > itr2)
					{
						change(CellAddress(&initial, itr + 1), CellAddress(&initial, itr2 + 1));
						printf("\n%d�Ԗڂ̗v�f��%d�Ԗڂ̗v�f�����ւ��܂����B\n", itr, itr2);
					}
					else
					{
						printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr2);
					}
				}
				else
				{
					printf("\n%d�Ԗڂ̗v�f��������܂���ł����B\n", itr);
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
	printf("------------------------\n1. �v�f�̕\���ɖ߂�\n2. �v�f�̑���ɖ߂�\n");
}