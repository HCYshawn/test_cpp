#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<easyx.h>
#include<math.h>
#include<graphics.h>

#define WIDTH 960  //���ڿ��
#define HEIGTH 640  //���ڸ߶�
#define STR_NUM 128 //�ַ�������
#define STR_SIZE 20 //������󳤶�
#define STR_WIDTH 12 //�ַ������

//������ṹ��
struct rain 
{
	int x;
	int y;
	int speed;
	char str[STR_SIZE];
}rain[STR_NUM];

//��ȡ����ַ�
char Createch()
{
	//��Ϊֻ��Ҫ�������͵��ַ�����д��ĸ��Сд��ĸ�����֣�����ֻ��Ҫ����ѡ���
	int mid = rand() % 3;
	switch (mid)
	{
		case 0:
			//���ش�д��ĸ
			return rand() % 26 + 'A';
			break;
		case 1:
			//����Сд��ĸ
			return rand() % 26 + 'a';
			break;
		case 2:
			//��������
			return rand() % 10 + '0';
			break;
		default:
			break;
	}
}

//��ʼ���ṹ��
void GetInit()
{
	int i = 0;
	for (i = 0; i < STR_NUM; i++)
	{
		rain[i].x = i * STR_WIDTH;
		rain[i].y = rand() % HEIGTH;
		rain[i].speed = rand() % 5 + 5;
	}
	for (i = 0; i < STR_NUM; i++)
	{
		for (int j = 0; j < STR_SIZE; j++)
		{
			rain->str[j] = Createch();
		}
	}
}

//���
void GameDraw()
{
	//��ջ�ͼ��ɫ
	cleardevice();
	for (int i = 0; i < STR_NUM; i++)
	{
		for (int j = 0; j < STR_NUM; j++)
		{
			//��������ַ���ɫ���ʽ���ɫ��
			settextcolor(RGB(255.0 / STR_SIZE * i, 255.0 / STR_SIZE * j, 0));
			//��ָ���ط���ӡ,������������Ϊ�ַ�
			outtextxy(rain[i].x, rain[i].y + j * STR_WIDTH, rain[i].str[j]);
		}
	}
}

//ʵ���ַ��ƶ�
void Gameplay()
{
	for (int i = 0; i < STR_NUM; i++)
	{
		rain[i].y += rain[i].speed;
		if (rain[i].y - STR_SIZE * STR_WIDTH > WIDTH)
		{
			rain[i].y = 0;
		}
	}
}

//����任�ṹ�������λ�õ��ַ�
void Changech()
{
	for (int i = 0; i < STR_NUM; i++)
	{
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = Createch();
	}
}
int main()
{
	initgraph(WIDTH, HEIGTH);  //��easyxͼ�λ�����
	srand(GetTickCount());	   //��ȡ���ASCII�����ֵ
	GetInit();
	DWORD t1, t2;
	t1 = t2 = GetTickCount();
	while (1)
	{
		//����������ͼ��ֱ������
		BeginBatchDraw();
		GameDraw();
		Changech();
		if (t2 - t1 > 20)
		{
			Gameplay();
			t1 = t2;
		}
		//���»�ȡ���ֵ
		t2 = GetTickCount();
		EndBatchDraw();
	}
	getchar();
	closegraph();
	return 0;
}