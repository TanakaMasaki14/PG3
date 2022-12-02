#include"DisplayState.h"
#include<string>

//-------------------------------------------------------------
void DisplayState::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new AllDisplay);
		break;
	case 2:
		cellManager->ChangeState(new OrderDisplay);
		break;
	case 9:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void DisplayState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[要素の表示]\n");
	printf("1.要素の一覧表示\n");
	printf("2.順番を指定して要素を表示\n");
	printf("9.要素操作に戻る\n");
	printf("\n操作を選択してください\n");
	printf("-\n\n");
}

//-------------------------------------------------
void AllDisplay::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DisplayState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void AllDisplay::Draw()
{
	printf("[要素の一覧表示]\n");
	printf("要素一覧:{\n");
	Index(cellManager->GetCell());
	printf("}\n");
	printf("\n要素数:%d\n", GetCellSize(cellManager->GetCell()));
	printf("\n------------------------------------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}


//--------------------------------------------------
void OrderDisplay::Update()
{
	cellManager->ClearOrder();

	int num = 0;

	*cellManager->GetNum() = 0;

	int i = 0;
	char buff[100];
	fgets(buff, sizeof(buff), stdin);
	while (true)
	{
		fgets(buff, sizeof(buff), stdin);

		if (buff[0] == '\n') { break; }
		else
		{
			printf(",");

			cellManager->GetOrder()[i] = atoi(buff);

			i++;
			(*cellManager->GetNum()) = i;
		}
	}

	cellManager->ChangeState(new OrderDisplay2);
}

void OrderDisplay::Draw()
{
	printf("[順番を指定して要素を表示]\n");
	printf("表示したい要素の順番を指定してください。何も入力なしで確定。\n");
	printf("\n\n-\n");
}

void OrderDisplay2::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DisplayState);
		break;
	case 2:
		cellManager->ChangeState(new InitialState);
		break;
	}
}

void OrderDisplay2::Draw()
{
	printf("{\n");

	int i = 0;
	while (true)
	{
		if (*cellManager->GetNum() - 1 < i) { break; }

		printf(" %d: \"%s\",\n", cellManager->GetOrder()[i],
			GetInsertCellAddres(cellManager->GetCell(), cellManager->GetOrder()[i])->val);

		i++;
	}

	printf("}\n");

	printf("\n------------------------------------------------------\n");
	printf("1.要素の表示に戻る\n");
	printf("2.要素の操作に戻る\n");
	printf("-\n\n");
}