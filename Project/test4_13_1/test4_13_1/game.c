#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��ʼ�����̵ĺ���
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

//��ӡ���̵ĺ���
void printchess(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf(" ������ɨ �� �� Ϸ������ \n");
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

//���׺���
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

//���׺���
void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row * col - GAMEMINE)
	{
		printf("������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����...\n");
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
			printf("����ֵ�������������룡\n");
		}
	}
	if (win == row * col - GAMEMINE)
	{
		printf("��ϲ�����׳ɹ�����Ϸͨ�أ�\n");
		printchess(mine, ROW, COL);
	}
}