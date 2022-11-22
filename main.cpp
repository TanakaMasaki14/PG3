#include <iostream>
#include <memory>
#include <Windows.h>
#include "SceneManager.h"

int main()
{
	int number = 0;
	const int maxNumber = 3;

	while (true)
	{
		SceneManager::GetInstance()->ChangeScene(number);

		number++;
		if (number > maxNumber)
		{
			number = 0;
		}

		Sleep(1000);
	}
	return 0;
}