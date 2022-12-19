#include"SceneManager.h"

int main()
{
	while (true)
	{
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Draw();
	}

	return 0;
}