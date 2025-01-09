#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化棋盘的函数
void gameinitial(char mine[ROWS][COLS], int rows, int cols, char re)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			mine[i][j] = re;
		}
	}
}

//打印棋盘的函数
void printchess(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf(" ———扫 雷 游 戏——— \n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		j = 0;
		for (j = 1; j <= col; j++)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
}

//埋雷函数
void arrangemine(char mine[ROW][COLS], int row, int col)
{
	int mid = GAMEMINE;
	while (mid)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			mid--;
		}
	}
}

int retmine(char mine[ROWS][COLS], int x, int y)
{
	int mid = (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
	return mid;
}

//排雷函数
void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row * col - GAMEMINE)
	{
		printf("请输入要排查的坐标：");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了...\n");
				printchess(mine, ROW, COL);
				break;
			}
			else
			{
				int mid = retmine(mine, x, y);
				show[x][y] = mid + '0';
				printchess(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标值错误，请重新输入！\n");
		}
	}
	if (win == row * col - GAMEMINE)
	{
		printf("恭喜你排雷成功！游戏通关！\n");
		printchess(mine, ROW, COL);
	}
}