#include<stdio.h>
#include"Enemy.h"

int main()
{
	static const int numMax = 5;

	Enemy enemy[numMax];
	for (int i = 0; i < numMax; i++)
	{
		enemy[i].Initialize(i);
	}

	printf("EnterƒL[‚Å“|‚·\n");

	static const int strMax = 128;
	static char str[strMax];

	while (true)
	{
		for (int i = 0; i < numMax; i++)
		{
			enemy[i].Update();
			enemy[i].Draw();
		}

		fgets(str, strMax, stdin);

		if (str[0] == '\n')
		{
			enemy[0].SetIsAlive(false);
		}
	}

	return 0;
}