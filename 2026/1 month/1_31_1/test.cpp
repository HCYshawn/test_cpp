#include <stdio.h>
#include <iostream>

void Swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printa(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// 插入排序
void insert(int *a, int n)
{
    int i, j, key;

    for (i = 0; i < n; i++)
    {
        // 记录当前元素值
        key = a[i];
        j = i - 1;

        // 从后往前遍历，将数组元素向后移，直到找到最后一个比key大的数值
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        // 填入当前元素值
        a[j + 1] = key;
    }
}

// 希尔排序
void shell(int *a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        // 此法选gap更佳
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; i++)
        {
            // 有序序列最后一个位置，即从此位开始向前找
            int end = i;
            // 待插入的新元素
            int temp = a[end + gap];

            // 组内插入排序
            while (end >= 0 && a[end] > temp)
            {
                a[end + gap] = a[end];
                end -= gap;
            }

            // 填入
            a[end + gap] = temp;
        }
    }
}

// 选择排序
void select(int *a, int n)
{
    int begin = 0;
    int end = n - 1;
    while (begin < end)
    {
        int mini = begin;
        int maxi = begin;

        // 双向扫描
        for (int i = begin + 1; i <= end; i++)
        {
            if (a[i] > a[maxi])
                maxi = i;
            if (a[i] < a[mini])
                mini = i;
        }

        // 直接交换当前最小值
        Swap(&a[begin], &a[mini]);
        // 找回真下标
        if (maxi == begin)
        {
            maxi = mini;
        }

        Swap(&a[end], &a[maxi]);
        ++begin;
        --end;
    }
}

// 冒泡排序
void bubble(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        // 单趟
        int flag = 0;
        for (int j = 1; j < n - i; j++)
        {
            if (a[i - 1] > a[i])
            {
                Swap(&a[i - 1], &a[i]);
                flag = 1;
            }
        }
        if (flag == 0)
            break;
    }
}

// 三数取中
int GetMidi(int *a, int left, int right)
{
    int midi = (left + right) / 2;
    if (a[left] < a[midi])
    {
        if (a[midi] < a[right])
        {
            return midi;
        }
        else if (a[left] < a[right])
        {
            return right;
        }
        else
        {
            return left;
        }
    }
    else // a[left]>a[midi]
    {
        if (a[midi] > a[right])
        {
            return midi;
        }
        else if (a[left] < a[right])
        {
            return left;
        }
        else
        {
            return left;
        }
    }
}

// 快速排序
void quick(int *a, int left, int right)
{
    if (left >= right)
        return;

    // 小区间优化，不再递归分割排序，减少递归的次数
    if ((right - left + 1) < 10)
    {
        insert(a + left, right - left + 1);
    }
    else
    {
        // 三数取中，降低耗时
        int midi = GetMidi(a, left, right);
        Swap(&a[left], &a[midi]);

        int keyi = a[left];
        int begin = left, end = right;
        while (begin < end)
        {
            // 右边找小
            while (begin < end && a[end] >= a[keyi])
            {
                --end;
            }
            // 左边找大
            while (begin < end && a[begin] <= a[keyi])
            {
                ++begin;
            }
            Swap(&a[begin], &a[end]);
        }
        Swap(&a[keyi], &a[begin]);
        keyi = begin;
        quick(a, left, keyi - 1);
        quick(a, keyi + 1, right);
    }
}

int main()
{
    return 0;
}