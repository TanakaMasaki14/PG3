#pragma once
#include "Singleton.h"
#include <memory>

template<typename T> class Singleton;

class SceneManager : public Singleton<SceneManager>
{
private:
	friend Singleton<SceneManager>;

public:
	void ChangeScene(const int sceneNo);
};

