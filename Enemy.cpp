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
		printf("%d”Ô¶‚«‚Ä‚Ü‚·,", num);
	}
	else
	{
		printf("%d”Ô€‚ñ‚Å‚Ü‚·,", num);
	}
}