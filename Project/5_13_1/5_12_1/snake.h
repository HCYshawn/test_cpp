#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include<stdio.h>
#include<Stdlib.h>
#include<windows.h>
#include<stdbool.h>
#include<time.h>

#define POS_X 24
#define POS_Y 5

#define WALL L'□'
#define BODY L'●'
#define FOOD L'★'

//蛇的方向
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum GAME_STATUS
{
	OK,//游戏正常
	KILL_BY_WALL,//撞到墙
	KILL_BY_SELF,//撞到自己
	END_NORMAL//正常退出
};

//蛇的身体
typedef struct SnakeNode 
{
	int x;//x坐标
	int y;//y坐标
	struct SnakeNode* next;//蛇身节点
}SnakeNode,* pSnakeNode;

//贪吃蛇基本数据
typedef struct Snake
{
	pSnakeNode _pSnake;//指向蛇头的指针
	pSnakeNode _pFood;//指向食物节点的指针
	enum DIRECTION _dir;//蛇的方向
	enum GAME_STATUS _status;//游戏的状态
	int _food_weight;//一个食物的分数
	int _score;//总成绩
	int _sleep_time;//休息时间，时间越短速度越快
}Snake,*pSnake;

//定位光标位置
void SetPos(short x, short y);
//游戏初始化
void GameStart(pSnake ps);
//欢迎界面打印
void welcomeToGame();
//地图绘制
void CreateMap();
//创建蛇
void InitSnake(pSnake ps);
//创建食物
void CreateFood(pSnake ps);

//游戏运行基本逻辑
void GameRun(pSnake ps);

//蛇的移动——走一步
void SnakeMove(pSnake ps);
//下一步是食物
int NextIsFood(pSnakeNode pn, pSnake ps);
//下一个位置是食物
void EatFood(pSnakeNode pn,pSnake ps);
//下一个位置不是食物
void NoFood(pSnakeNode pn, pSnake ps);
//检测蛇是否撞墙
void KillByWall(pSnake ps);
//检测蛇是否撞上自己
void KillBySelf(pSnake ps);

//游戏善后的工作
void GameEnd(pSnake ps);