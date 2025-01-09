#define _CRT_SECURE_NO_WARNINGS 1

#include<locale.h>
#include"snake.h"

void test()
{
	int ch = 0;
	do 
	{
		ch = 0;
		system("cls");
		Snake snake = { 0 };
		//游戏开始
		GameStart(&snake);
		//游戏运行
		GameRun(&snake);
		//游戏结束
		GameEnd(&snake);
		SetPos(20, 15);
		printf("再来一局吗?(Y?N):");
		ch = getchar();
		/*getchar();*/
		while (getchar() != '\n');

	} while (ch=='Y'||ch=='y');
	SetPos(0, 27);
}

int main()
{
	//设置本地环境
	setlocale(LC_ALL, "");
	srand((unsigned int)time(NULL));
	test();
	return 0;
}