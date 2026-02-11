#include <iostream>
#include <stdio.h>
#include <math.h>

// // 1. 输入两个整数，输出它们的和
// int main()
// {
//     int a, b;
//     scanf("%d %d", &a, &b);
//     printf("sum = %d\n", a + b);
//     return 0;
// }

// // 2. 输入一个整数，判断其是否为偶数
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     if (n % 2 == 1)
//         printf("奇数\n");
//     else
//     {
//         printf("偶数\n");
//     }
//     return 0;
// }

// // 3. 给出一个百分制成绩，要求输出成绩等级ABCDE，90A，80B，70C，60D，E不及格
// int main()
// {
//     int n = 0;
//     scanf("%d", &n);
//     if (n > 100 || n < 0)
//     {
//         printf("成绩无效！\n");
//     }
//     else if (n >= 90)
//         printf("A\n");
//     else if (n >= 80)
//         printf("B\n");
//     else if (n >= 70)
//         printf("C\n");
//     else if (n >= 60)
//         printf("D\n");
//     else
//         printf("E\n");
//     return 0;
// }

// // 4. 编写一个程序，从键盘输入年份，判断是平年还是闰年
// int main()
// {
//     int year = 0;
//     scanf("%d", &year);
//     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//     {
//         printf("是闰年\n");
//     }
//     else
//     {
//         printf("是平年\n");
//     }
//     return 0;
// }

// // 从键盘输入某年某月某日，计算出这一天是这一年中的第几日
// int main()
// {
//     int year, month, day;
//     scanf("%d %d %d", &year, &month, &day);
//     int sum = 0;
//     int mid = 0;
//     if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//         mid += 1;

//     switch (month)
//     {
//     case 12:
//         sum += 30;
//     case 11:
//         sum += 31;
//     case 10:
//         sum += 30;
//     case 9:
//         sum += 31;
//     case 8:
//         sum += 31;
//     case 7:
//         sum += 30;
//     case 6:
//         sum += 31;
//     case 5:
//         sum += 30;
//     case 4:
//         sum += 31;
//     case 3:
//         sum += mid == 1 ? 29 : 28;
//     case 2:
//         sum += 31;
//     case 1:
//         sum += day;
//     }

//     printf("%d %d %d 是这年的第 %d 天\n", year, month, day, sum);
//     return 0;
// }

// // 6. 输入三角形边长，判断是否构成三角形并输出其面积
// int main()
// {
//     double a, b, c, p, s;
//     scanf("%lf %lf %lf", &a, &b, &c);
//     if (a + b > c && a + c > b && b + c > a)
//     {
//         p = (a + b + c) / 2;
//         s = sqrt(p * (p - a) * (p - b) * (p - c));
//         printf("s: \n", s);
//     }
//     else
//     {
//         printf("三边不构成三角形，无法确定面积\n");
//     }
//     return 0;
// }

// // 7. 输入一元二次方程ax^2+bx+c=0的系数a,b,c，计算方程的实数根
// int main()
// {
//     double a, b, c, x1, x2, p, q, t;
//     scanf("%lf %lf %lf", &a, &b, &c);
//     t = b * b - 4 * a * c;
//     if (a != 0 && t >= 0)
//     {
//         p = -b / (2 * a);
//         q = sqrt(t) / (2 * a);
//         x1 = p - q;
//         x2 = p + q;
//         printf("x1 = %lf,x2 = %lf", x1, x2);
//     }
//     else
//     {
//         printf("无实根\n");
//     }
//     return 0;
// }
