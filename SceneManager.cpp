#include "SceneManager.h"
#include <iostream>

void SceneManager::ChangeScene(const int sceneNo)
{
	switch (sceneNo)
	{
	case 0:
		std::cout << "SceneNo: 0" << std::endl;
		break;

	case 1:
		std::cout << "SceneNo: 1" << std::endl;
		break;

	case 2:
		std::cout << "SceneNo: 2" << std::endl;
		break;

	case 3:
		std::cout << "SceneNo: 3" << std::endl;
		break;

	default:
		break;
	}
}
