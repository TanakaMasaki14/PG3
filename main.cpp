#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <functional>

void SetTimeout(std::function<void()> func, int second)
{
	Sleep(second);
	func();
}

int main(int argc, const char* argv[])
{
	//入力
	int select;
	printf("入力:偶数なら0 奇数なら1\n");
	scanf_s("%d", &select);

	//答えの決定
	int ans = 0;
	srand(time(nullptr));

	ans = rand() % 100;

	//関数の作成
	std::function<void()> judgeFunc = [&]()
	{

		printf("%d\n", ans);
		if (ans % 2 == 0 and select == 0)
		{
			printf("正解\n");
		}
		else if (ans % 2 == 1 and select == 1)
		{
			printf("正解\n");
		}
		else
		{
			printf("不正解\n");
		}

	};

	//実行
	SetTimeout(judgeFunc, 2700);

	return 0;
}