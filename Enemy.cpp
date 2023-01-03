#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>

void Enemy::Update()
{
	(this->*Table[static_cast<size_t>(type_)])();
}

void Enemy::Draw()
{
}

//-------------------------------------------------------------
void (Enemy::* Enemy::Table[])() = {
	&Enemy::Melee,
	&Enemy::Shot,
	&Enemy::Evacuation
};

void Enemy::Melee()
{
	std::system("cls");
	printf("�ߐ�");

	Sleep(3 * 1000);

	type_ = Enemy::Type::Shot;
}

void Enemy::Shot()
{
	std::system("cls");
	printf("�ˌ�");

	Sleep(3 * 1000);

	type_ = Enemy::Type::Evacuation;
}

void Enemy::Evacuation()
{
	std::system("cls");
	printf("���E");

	Sleep(3 * 1000);

	type_ = Enemy::Type::Melee;
}