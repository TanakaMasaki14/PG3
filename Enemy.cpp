#include "Enemy.h"
#include <stdio.h>

bool Enemy::isAlive = true;

void Enemy::Initialize(const int num)
{
	this->num = num;
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("%d¶‘¶,", num);
	}
	else
	{
		printf("%d€–S,", num);
	}
}