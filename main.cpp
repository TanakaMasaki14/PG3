#include<stdio.h>
#include"Enemy.h"


int main()
{
	Enemy enemy;

	while (true)
	{
		enemy.Update();
		enemy.Draw();
	}

	return 0;
}