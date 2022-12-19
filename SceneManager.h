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
	//コンストラクタをprivate
	SceneManager();
	//デストラクタも
	~SceneManager();

public:
	//コピーコンストラクタを無効
	SceneManager(const SceneManager& obj) = delete;
	//代入演算子も
	SceneManager& operator=(const SceneManager& obj) = delete;

	//インスタンス取得
	static SceneManager* GetInstance();

	void ChangeScene(int sceneNo);

	void Update();
	void Draw();
};