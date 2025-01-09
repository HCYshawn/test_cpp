#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("*****      1. play      ******\n");
	printf("*****      0. over      ******\n");
	printf("******************************\n");
}
void game()
{
	char mine[ROWS][COLS];//基础棋盘
	char show[ROWS][COLS];//打印棋盘

	//初始化基础棋盘和打印棋盘
	gameinitial(mine, ROWS, COLS,'0');
	gameinitial(show, ROWS, COLS, '*');

	//打印棋盘的函数
	printchess(show, ROW, COL);
	
	//埋雷函数
	arrangemine(mine, ROW, COL);
	
	//排雷函数
	finemine(mine, show, ROW, COL);
}


int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束....\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
	} while (input);
	return 0;
}