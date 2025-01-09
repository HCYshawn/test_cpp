#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"

void SetPos(short x, short y)
{
	//获取标准输出设备句柄
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//定位光标
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}

//欢迎界面打印
void welcomeToGame()
{
	//调用SetPos函数，定位光标位置
	SetPos(40, 14);
	wprintf(L"欢迎来到贪吃蛇小游戏\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"用 ↑.↓.←.→ 来控制蛇的移动，按F3加速，F4减速\n");
	SetPos(25, 15);
	wprintf(L"加速能够得到更多的分数\n");

	SetPos(42, 20);
	system("pause");
	system("cls");

}

//地图绘制
void CreateMap()
{
	int i = 0;
	//上
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//下
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//左
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//右
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

//创建蛇
void InitSnake(pSnake ps)
{
	int i = 0;
	pSnakeNode cur = NULL;

	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));
		if (cur == NULL)
		{
			perror("InitSnake()::malloc()");
			return;
		}
		cur->next = NULL;
		cur->x = POS_X + 2 * i;
		cur->y = POS_Y;

		//头插法插入链表
		if (ps->_pSnake == NULL)
		{
			//空链表情况下
			//ps->_psnake即为哨兵位（头节点）
			ps->_pSnake = cur;
		}
		else
		{
			//非空链表情况下
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	//打印蛇身
	cur = ps->_pSnake;
	while (cur)
	{
		//定位蛇身节点，分别打印
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//设置贪吃蛇属性
	ps->_dir = RIGHT;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}

//创建食物
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
	//生成的x必须为2的倍数
	//x：2~54
	//y：1~25
again:
	//循环主体若为奇数，则继续随机至偶数为止
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);

	//x和y的坐标不能与蛇的身体冲突

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//创建食物节点
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	//打印食物节点
	SetPos(x, y);
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

//游戏初始化
void GameStart(pSnake ps)
{
	//设置窗口大小
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//隐藏光标
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//1.打印环境界面和功能介绍
	welcomeToGame();
	//2.绘制地图
	CreateMap();
	//3.创捷蛇
	InitSnake(ps);
	//4.创建食物
	CreateFood(ps);
}

//打印帮助信息
void PrintHelpInfo()
{
	SetPos(64,14);
	wprintf(L"%ls",L"不能穿墙，不能咬到自己");
	SetPos(64,15);
	wprintf(L"%ls",L"用↑.↓.←.→ 来控制蛇的移动");
	SetPos(64,16);
	wprintf(L"%ls",L"按F3加速，F4减速");
	SetPos(64,17);
	wprintf(L"%ls",L"按ESC退出游戏，按空格暂停游戏");
	SetPos(64,18);
	wprintf(L"%ls",L"CSDN.南天的波江座 制作");
}

//定义空格SPACE按下计算宏
#define KEY_PRESS(vk)  ((GetAsyncKeyState(vk)&1)?1:0)

//设置刷新时间
void Pause()
{
	while (1)
	{
		Sleep(200);
		if (KEY_PRESS(VK_SPACE))
		{
			break;
		}
	}
}

//下一步是食物
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

//下一个位置是食物
void EatFood(pSnakeNode pn, pSnake ps)
{
	//头插法
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	free(pn);
	pn = NULL;

	//打印蛇身
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;

	//重新创建食物
	CreateFood(ps);
}

//下一个位置不是食物
void NoFood(pSnakeNode pn, pSnake ps)
{
	pn->next = ps->_pSnake;
	ps->_pSnake = pn;

	pSnakeNode cur = ps->_pSnake;
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	//把最后一个结点打印成空格
	SetPos(cur->next->x, cur->next->y);
	printf("  ");

	//释放最后一个结点
	free(cur->next);

	//将倒数第二个节点的地址置为NULL
	cur->next = NULL;
}

//检测蛇是否撞墙
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x ==0|| ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

//检测蛇是否撞上自己
void KillBySelf(pSnake ps)
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur)
	{
		if (cur->x == ps->_pSnake->x && cur->y == ps->_pSnake->y)
		{
			ps->_status = KILL_BY_SELF;
			break;
		}
		cur = cur->next;
	}
}

//蛇的移动——走一步
void SnakeMove(pSnake ps)
{
	//创建一个结点，表示蛇即将到达的下一个节点
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}

	//检测下一步路径
	switch (ps->_dir)
	{
	case UP:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y - 1;
		break;
	case DOWN:
		pNextNode->x = ps->_pSnake->x;
		pNextNode->y = ps->_pSnake->y + 1;
		break;
	case LEFT:
		pNextNode->x = ps->_pSnake->x - 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	case RIGHT:
		pNextNode->x = ps->_pSnake->x + 2;
		pNextNode->y = ps->_pSnake->y;
		break;
	}
	//检测下一个坐标是否是食物
	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	//检测蛇是否撞墙
	KillByWall(ps);
	//检测蛇是否撞上自己
	KillBySelf(ps);
}

//游戏运行基本逻辑
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("总分数：%d\n", ps->_score);
		SetPos(64, 11);
		printf("当前食物的分数：%2d\n", ps->_food_weight);

		if (KEY_PRESS(VK_UP) && ps->_dir != DOWN)
		{
			ps->_dir = UP;
		}
		else if (KEY_PRESS(VK_DOWN) && ps->_dir != UP)
		{
			ps->_dir = DOWN;
		}
		else if (KEY_PRESS(VK_LEFT) && ps->_dir != RIGHT)
		{
			ps->_dir = LEFT;
		}
		else if (KEY_PRESS(VK_RIGHT) && ps->_dir != LEFT)
		{
			ps->_dir = RIGHT;
		}
		else if (KEY_PRESS(VK_SPACE))
		{
			Pause();
		}
		else if (KEY_PRESS(VK_ESCAPE))
		{
			//正常退出游戏
			ps->_status = END_NORMAL;
		}
		else if (KEY_PRESS(VK_F3))
		{
			if (ps->_sleep_time > 80)
			{
				ps->_sleep_time -= 30;
				ps->_food_weight += 2;
			}
		}
		else if (KEY_PRESS(VK_F4))
		{
			if (ps->_food_weight > 2)
			{
				ps->_sleep_time += 30;
				ps->_food_weight -= 2;
			}
		}

		SnakeMove(ps);

		Sleep(ps->_sleep_time);

	} while (ps->_status==OK);
}

//游戏善后的工作
void GameEnd(pSnake ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
		case END_NORMAL:
			wprintf(L"您主动结束游戏\n");
			break;
		case KILL_BY_WALL:
			wprintf(L"您撞到墙上，游戏结束\n");
			break;
		case KILL_BY_SELF:
			wprintf(L"您撞到了自己，游戏结束\n");
			break;
	}

	//释放蛇身的链表	
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}