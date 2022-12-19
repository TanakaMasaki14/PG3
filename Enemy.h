#pragma once
class Enemy
{
private:
	static bool isAlive;
	int num = 0;

public:
	void Initialize(const int num);

	static void Update();
	void Draw();

	void SetIsAlive(const bool isAlive) { this->isAlive = isAlive; }
	bool GetIsAlive() { return isAlive; }
};

