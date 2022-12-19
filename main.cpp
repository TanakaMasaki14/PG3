#include"SceneManager.h"


int main()
{
	//ŒJ‚è•Ô‚µ
	while (true)
	{
		SceneManager::GetInstance()->Update();
		SceneManager::GetInstance()->Draw();
	}

	return 0;
}