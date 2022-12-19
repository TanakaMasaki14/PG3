#include "Enemy.h"
#include <stdio.h>
#include <Windows.h>
#include <iostream>


void Enemy::Update()
{
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::Draw()
{
}

//-------------------------------------------------------------
void (Enemy::* Enemy::spFuncTable[])() = {
	&Enemy::MeleeAttack,
	&Enemy::Shot,
	&Enemy::Secession
};

void Enemy::MeleeAttack()
{
	std::system("cls");
	printf("ãﬂê⁄");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::Shot;
}

void Enemy::Shot()
{
	std::system("cls");
	printf("éÀåÇ");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::Secession;
}

void Enemy::Secession()
{
	std::system("cls");
	printf("ó£íE");

	Sleep(3 * 1000);

	phase_ = Enemy::Phase::MeleeAttack;
}


