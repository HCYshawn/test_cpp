#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define GAMEMINE 10

#define ROW 9
#define COL 9


#define ROWS ROW+2
#define COLS COL+2


//��ʼ����������
void gameinitial(char mine[ROWS][COLS], int rows, int cols, char re);
//��ʼ����ӡ����
void mineinitial(char show[ROWS][COLS], int rows, int cols, char we);

//��ӡ���̵ĺ���
void printchess(char show[ROWS][COLS], int rows, int cols);
//���׺���
void arrangemine(char mine[ROW][COLS], int row,int col);
//���׺���
void finemine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);