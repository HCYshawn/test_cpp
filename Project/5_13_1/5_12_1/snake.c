#define _CRT_SECURE_NO_WARNINGS 1

#include"snake.h"

void SetPos(short x, short y)
{
	//��ȡ��׼����豸���
	HANDLE houtput = NULL;
	houtput = GetStdHandle(STD_OUTPUT_HANDLE);

	//��λ���
	COORD pos = { x,y };
	SetConsoleCursorPosition(houtput, pos);
}

//��ӭ�����ӡ
void welcomeToGame()
{
	//����SetPos��������λ���λ��
	SetPos(40, 14);
	wprintf(L"��ӭ����̰����С��Ϸ\n");
	SetPos(42, 20);
	system("pause");
	system("cls");
	SetPos(25, 14);
	wprintf(L"�� ��.��.��.�� �������ߵ��ƶ�����F3���٣�F4����\n");
	SetPos(25, 15);
	wprintf(L"�����ܹ��õ�����ķ���\n");

	SetPos(42, 20);
	system("pause");
	system("cls");

}

//��ͼ����
void CreateMap()
{
	int i = 0;
	//��
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//��
	SetPos(0, 26);
	for (i = 0; i < 29; i++)
	{
		wprintf(L"%lc", WALL);
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(0, i);
		wprintf(L"%lc", WALL);
	}

	//��
	for (i = 1; i <= 25; i++)
	{
		SetPos(56, i);
		wprintf(L"%lc", WALL);
	}
}

//������
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

		//ͷ�巨��������
		if (ps->_pSnake == NULL)
		{
			//�����������
			//ps->_psnake��Ϊ�ڱ�λ��ͷ�ڵ㣩
			ps->_pSnake = cur;
		}
		else
		{
			//�ǿ����������
			cur->next = ps->_pSnake;
			ps->_pSnake = cur;
		}
	}

	//��ӡ����
	cur = ps->_pSnake;
	while (cur)
	{
		//��λ����ڵ㣬�ֱ��ӡ
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}

	//����̰��������
	ps->_dir = RIGHT;
	ps->_score = 0;
	ps->_food_weight = 10;
	ps->_sleep_time = 200;
	ps->_status = OK;
}

//����ʳ��
void CreateFood(pSnake ps)
{
	int x = 0;
	int y = 0;
	//���ɵ�x����Ϊ2�ı���
	//x��2~54
	//y��1~25
again:
	//ѭ��������Ϊ����������������ż��Ϊֹ
	do
	{
		x = rand() % 53 + 2;
		y = rand() % 25 + 1;
	} while (x % 2 != 0);

	//x��y�����겻�����ߵ������ͻ

	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		if (x == cur->x && y == cur->y)
		{
			goto again;
		}
		cur = cur->next;
	}

	//����ʳ��ڵ�
	pSnakeNode pFood = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pFood == NULL)
	{
		perror("CreateFood()::malloc()");
		return;
	}

	pFood->x = x;
	pFood->y = y;
	pFood->next = NULL;

	//��ӡʳ��ڵ�
	SetPos(x, y);
	wprintf(L"%lc", FOOD);

	ps->_pFood = pFood;
}

//��Ϸ��ʼ��
void GameStart(pSnake ps)
{
	//���ô��ڴ�С
	system("mode con cols=100 lines=30");
	system("title ̰����");
	HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
	//���ع��
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(houtput, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(houtput, &CursorInfo);

	//1.��ӡ��������͹��ܽ���
	welcomeToGame();
	//2.���Ƶ�ͼ
	CreateMap();
	//3.������
	InitSnake(ps);
	//4.����ʳ��
	CreateFood(ps);
}

//��ӡ������Ϣ
void PrintHelpInfo()
{
	SetPos(64,14);
	wprintf(L"%ls",L"���ܴ�ǽ������ҧ���Լ�");
	SetPos(64,15);
	wprintf(L"%ls",L"�á�.��.��.�� �������ߵ��ƶ�");
	SetPos(64,16);
	wprintf(L"%ls",L"��F3���٣�F4����");
	SetPos(64,17);
	wprintf(L"%ls",L"��ESC�˳���Ϸ�����ո���ͣ��Ϸ");
	SetPos(64,18);
	wprintf(L"%ls",L"CSDN.����Ĳ����� ����");
}

//����ո�SPACE���¼����
#define KEY_PRESS(vk)  ((GetAsyncKeyState(vk)&1)?1:0)

//����ˢ��ʱ��
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

//��һ����ʳ��
int NextIsFood(pSnakeNode pn, pSnake ps)
{
	return (ps->_pFood->x == pn->x && ps->_pFood->y == pn->y);
}

//��һ��λ����ʳ��
void EatFood(pSnakeNode pn, pSnake ps)
{
	//ͷ�巨
	ps->_pFood->next = ps->_pSnake;
	ps->_pSnake = ps->_pFood;

	free(pn);
	pn = NULL;

	//��ӡ����
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		SetPos(cur->x, cur->y);
		wprintf(L"%lc", BODY);
		cur = cur->next;
	}
	ps->_score += ps->_food_weight;

	//���´���ʳ��
	CreateFood(ps);
}

//��һ��λ�ò���ʳ��
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
	//�����һ������ӡ�ɿո�
	SetPos(cur->next->x, cur->next->y);
	printf("  ");

	//�ͷ����һ�����
	free(cur->next);

	//�������ڶ����ڵ�ĵ�ַ��ΪNULL
	cur->next = NULL;
}

//������Ƿ�ײǽ
void KillByWall(pSnake ps)
{
	if (ps->_pSnake->x ==0|| ps->_pSnake->x == 56 ||
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		ps->_status = KILL_BY_WALL;
	}
}

//������Ƿ�ײ���Լ�
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

//�ߵ��ƶ�������һ��
void SnakeMove(pSnake ps)
{
	//����һ����㣬��ʾ�߼����������һ���ڵ�
	pSnakeNode pNextNode = (pSnakeNode)malloc(sizeof(SnakeNode));
	if (pNextNode == NULL)
	{
		perror("SnakeMove()::malloc()");
		return;
	}

	//�����һ��·��
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
	//�����һ�������Ƿ���ʳ��
	if (NextIsFood(pNextNode, ps))
	{
		EatFood(pNextNode, ps);
	}
	else
	{
		NoFood(pNextNode, ps);
	}
	//������Ƿ�ײǽ
	KillByWall(ps);
	//������Ƿ�ײ���Լ�
	KillBySelf(ps);
}

//��Ϸ���л����߼�
void GameRun(pSnake ps)
{
	PrintHelpInfo();
	do
	{
		SetPos(64, 10);
		printf("�ܷ�����%d\n", ps->_score);
		SetPos(64, 11);
		printf("��ǰʳ��ķ�����%2d\n", ps->_food_weight);

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
			//�����˳���Ϸ
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

//��Ϸ�ƺ�Ĺ���
void GameEnd(pSnake ps)
{
	SetPos(24, 12);
	switch (ps->_status)
	{
		case END_NORMAL:
			wprintf(L"������������Ϸ\n");
			break;
		case KILL_BY_WALL:
			wprintf(L"��ײ��ǽ�ϣ���Ϸ����\n");
			break;
		case KILL_BY_SELF:
			wprintf(L"��ײ�����Լ�����Ϸ����\n");
			break;
	}

	//�ͷ����������	
	pSnakeNode cur = ps->_pSnake;
	while (cur)
	{
		pSnakeNode del = cur;
		cur = cur->next;
		free(del);
	}
}