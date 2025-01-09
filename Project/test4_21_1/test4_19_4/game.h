#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GAMEMINE 10

#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2

#define win1 81
#define win2 256
#define win3 480
//��ʼ����������
void gameinitial(char mine[ROWS][COLS], int rows, int cols, char re);

void install(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);
//��ӡ���̵ĺ���
void printchess(char show[ROWS][COLS], int rows, int cols,int win);
//���׺���
void arrangemine(char mine[ROW][COLS], int row, int col);
//���׺���
void finemine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);