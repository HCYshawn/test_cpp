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
void printchess(char show[ROWS][COLS], int row, int col,int win)
{
	int i = 0;
	int j = 0;
	printf(" ������ɨ �� �� Ϸ������ \n");
	printf("����ʤ������ %d ������\n", win1-10-win);
	printf("����0 0 ������˳���ǳ���\n");
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

//���㺯��
int retmine(char mine[ROWS][COLS], int x, int y)
{
	int mid = (mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1] + mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0');
	return mid;
}

//ɨ������
void install(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y,int *win)
{
	if (x<1 || x>ROW || y<1 || y>COL)
		return;
	if (show[x][y] != '*')
		return;
	int mid = retmine(mine, x, y);
	if (mid > 0)
	{
		(*win)++;
		show[x][y] = mid + '0';
		return;
	}
	else if (mid == 0)
	{
		(*win)++;
		show[x][y] = ' ';
		install(mine, show, x - 1, y,win);
		install(mine, show, x - 1, y - 1,win);
		install(mine, show, x - 1, y + 1,win);
		install(mine, show, x, y - 1,win);
		install(mine, show, x, y + 1,win);
		install(mine, show, x + 1, y,win);
		install(mine, show, x + 1, y - 1,win);
		install(mine, show, x + 1, y + 1,win);
	}
}

void tab(char show[ROWS][COLS], int row, int col)
{
	int x = 1;
	int y = 1;
	int j = 0;
	int k = 0;
	printf("����0 0�˳���������0 1ȡ�����\n");
	while (1)
	{
		printf("������Ҫ��ǵ����꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			show[x][y] = '!';
		}
		else if (x == 0&&y == 0)
		{
			printf("��ǳ������...\n");
			break;
		}
		else if (x == 0 && y == 1)
		{
			printf("���ٴ�����Ҫȡ����ǵ����꣺");
			scanf("%d %d", &j, &k);
			show[j][k] = '*';
		}
		else
			printf("����������������룡\n");

	}
	

}
//���׺���
void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - GAMEMINE)
	{
		printf("������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����...\n");
				printchess(mine, ROW, COL,win);
				break;
			}
			else
			{
				install(mine,show, x, y,&win);
				printchess(show, ROW, COL,win);
			}
		}
		else if (x == 0&&y == 0)
		{
			tab(show, ROWS, COLS);
			printchess(show, ROW, COL,win);
		}
		else
		{
			printf("����ֵ�������������룡\n");
		}
	}
	if (win == row * col - GAMEMINE)
	{
		printf("��ϲ�����׳ɹ�����Ϸͨ�أ�\n");
		printchess(mine, ROW, COL,win);
	}
}