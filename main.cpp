#include<stdio.h>
#include<stdlib.h>


typedef struct cell
{
	int val = 0;
	struct cell* next = nullptr;//�\����

}CELL;

void Create(CELL* cellStart, int insertNum)
{
	CELL* newCell;
	//�V�K�쐬����Z�����̃��������m��
	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = insertNum;
	newCell->next = nullptr;

	//�ŏ��̃Z���̃A�h���X���Y������
	while (cellStart->next != nullptr)
	{
		cellStart = cellStart->next;
	}
	cellStart->next = newCell;
}

void Index(CELL* cellStart)
{
	//�Ō�̃Z���ɂȂ�܂ŏo��
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

	//�\����
	struct cellstr* next = nullptr;

}CELLSTR;

void Create(CELLSTR* cellStart, const char* insertStr)
{
	CELLSTR* newCell;
	//�V�K�쐬����Z�����̃��������m��
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
	//�Ō�̃Z���ɂȂ�܂ŏo��
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
	cellStrStart.str = "�X���C��";
	Create(&cellStrStart, "�L���O�X���C��");
	Create(&cellStrStart, "�������X���C��");
	Create(&cellStrStart, "�Ԃ��X���C��");

	Index(&cellStrStart);

	system("pause");
	return 0;
}