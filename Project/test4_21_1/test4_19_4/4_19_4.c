#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************************\n");
	printf("*****      1. play      ******\n");
	printf("*****      0. over      ******\n");
	printf("******************************\n");
}
void dif()
{
	printf("*********************************\n");
	printf("*****      1. 10 mine      ******\n");
	printf("*****      2. 40 mine      ******\n");
	printf("*****      3. 99 mine      ******\n");
	printf("*****      0. 40 mine      ******\n");
	printf("*********************************\n");
}
void game()
{
	int win = 0;
	char mine[ROWS][COLS];//��������
	char show[ROWS][COLS];//��ӡ����

	//��ʼ���������̺ʹ�ӡ����
	gameinitial(mine, ROWS, COLS, '0');
	gameinitial(show, ROWS, COLS, '*');

	//��ӡ���̵ĺ���
	printchess(show, ROW, COL,win);

	//���׺���
	arrangemine(mine, ROW, COL);

	//���׺���
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
			printf("��Ϸ����....\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}