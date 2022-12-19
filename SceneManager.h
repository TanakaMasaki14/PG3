#pragma once
#include<stdio.h>
#include <stdlib.h>

class SceneManager final
{
private:
	enum SCENE
	{
		TITLE,
		NEW_GAME,
		GAME_PLAY,
		GAME_CLEAR
	};

	int sceneNum = SCENE::TITLE;

private:
	SceneManager();

	~SceneManager();

public:

	SceneManager(const SceneManager& obj) = delete;

	SceneManager& operator=(const SceneManager& obj) = delete;

	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	void Update();
	void Draw();
};