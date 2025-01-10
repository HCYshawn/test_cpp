#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<easyx.h>
#include<math.h>
#include<graphics.h>

#define WIDTH 960  //窗口宽度
#define HEIGTH 640  //窗口高度
#define STR_NUM 128 //字符串数量
#define STR_SIZE 20 //数组最大长度
#define STR_WIDTH 12 //字符串宽度

//数字雨结构体
struct rain 
{
	int x;
	int y;
	int speed;
	char str[STR_SIZE];
}rain[STR_NUM];

//获取随机字符
char Createch()
{
	//因为只需要三个类型的字符（大写字母、小写字母、数字，所以只需要三种选项即可
	int mid = rand() % 3;
	switch (mid)
	{
		case 0:
			//返回大写字母
			return rand() % 26 + 'A';
			break;
		case 1:
			//返回小写字母
			return rand() % 26 + 'a';
			break;
		case 2:
			//返回数字
			return rand() % 10 + '0';
			break;
		default:
			break;
	}
}

//初始化结构体
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

//输出
void GameDraw()
{
	//清空绘图颜色
	cleardevice();
	for (int i = 0; i < STR_NUM; i++)
	{
		for (int j = 0; j < STR_NUM; j++)
		{
			//设置输出字符颜色，呈渐变色彩
			settextcolor(RGB(255.0 / STR_SIZE * i, 255.0 / STR_SIZE * j, 0));
			//在指定地方打印,第三个参数即为字符
			outtextxy(rain[i].x, rain[i].y + j * STR_WIDTH, rain[i].str[j]);
		}
	}
}

//实现字符移动
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

//随机变换结构体中随机位置的字符
void Changech()
{
	for (int i = 0; i < STR_NUM; i++)
	{
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = Createch();
	}
}
int main()
{
	initgraph(WIDTH, HEIGTH);  //打开easyx图形化窗口
	srand(GetTickCount());	   //获取随机ASCII随机码值
	GetInit();
	DWORD t1, t2;
	t1 = t2 = GetTickCount();
	while (1)
	{
		//开启批量绘图，直至结束
		BeginBatchDraw();
		GameDraw();
		Changech();
		if (t2 - t1 > 20)
		{
			Gameplay();
			t1 = t2;
		}
		//重新获取随机值
		t2 = GetTickCount();
		EndBatchDraw();
	}
	getchar();
	closegraph();
	return 0;
}