#pragma once

class Enemy
{
private:

	static void (Enemy::* Table[])();

	static enum class Type
	{
		Melee,
		Shot,
		Evacuation
	};

	Type type_ = Type::Melee;

	void Melee();
	void Shot();
	void Evacuation();

public:
	void Update();
	void Draw();
};