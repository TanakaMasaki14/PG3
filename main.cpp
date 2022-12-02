#include"CellManager.h"

int main()
{
	CellManager* cellManager = new CellManager;

	while (true)
	{
		cellManager->Draw();
		cellManager->Update();
	}

	delete cellManager;

	return 0;
}