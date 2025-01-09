#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GAMEMINE 10

#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2


//初始化基础棋盘
void gameinitial(char mine[ROWS][COLS], int rows, int cols, char re);
//初始化打印棋盘
void mineinitial(char show[ROWS][COLS], int rows, int cols, char we);

//打印棋盘的函数
void printchess(char show[ROWS][COLS], int rows, int cols);
//埋雷函数
void arrangemine(char mine[ROW][COLS], int row,int col);
//排雷函数
void finemine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);