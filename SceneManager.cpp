#include "SceneManager.h"


SceneManager::SceneManager()
{

}

SceneManager::~SceneManager()
{

}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::ChangeScene(int sceneNo)
{
	if (sceneNo > SCENE::GAME_CLEAR) sceneNum = SCENE::TITLE;
	else                             sceneNum = sceneNo;
}

void SceneManager::Update()
{
	system("pause");
}

void SceneManager::Draw()
{
	switch (sceneNum)
	{
	case SCENE::TITLE:
		printf("TITLE\n\n");
		break;
	case SCENE::NEW_GAME:
		printf("NewGame\n\n");
		break;
	case SCENE::GAME_PLAY:
		printf("GamePlay\n\n");
		break;
	case SCENE::GAME_CLEAR:
		printf("GameClear\n\n");
		break;
	}

	ChangeScene(sceneNum + 1);
}