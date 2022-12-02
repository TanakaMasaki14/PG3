#include"CellManager.h"

//-------------------------------------------------------------
void InitialState::Update()
{
	int num = 0;

	scanf_s("%d", &num);

	switch (num)
	{
	case 1:
		cellManager->ChangeState(new DisplayState);
		break;
	case 2:
		cellManager->ChangeState(new InsertState);
		break;
	case 3:
		cellManager->ChangeState(new EditState);
		break;
	case 4:
		cellManager->ChangeState(new DeleteState);
		break;
		//case 5:
			//cellManager->ChangeState(new );
		break;
	}
}

void InitialState::Draw()
{
	printf("\n------------------------------------------------------\n");
	printf("[要素の操作]\n");
	printf("1.要素の表示\n");
	printf("2.要素の挿入\n");

	if (GetCellSize(cellManager->GetCell()))
	{
		printf("3.要素の編集\n");
		printf("4.要素の削除\n");
	}

	printf("\n---------------------------------\n");
	printf("操作を選択してください\n");
	printf("-\n\n");
}