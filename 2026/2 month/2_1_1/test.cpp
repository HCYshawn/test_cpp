#include <stdio.h>
#include <Stack.h>
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

// hoare版本
int part1(int *a, int left, int right)
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
    return begin;
}

// 前后指针版本
int part2(int *a, int left, int right)
{
    // 三数取中，降低耗时
    int midi = GetMidi(a, left, right);
    Swap(&a[left], &a[midi]);

    int keyi = left;
    int prev = left;
    int cur = prev + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[prev], &a[cur]);
        }
        ++cur;
    }
    Swap(&a[prev], &a[keyi]);
    return prev;
}

// 快速排序1
void quick1(int *a, int left, int right)
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
        int keyi = part1(a, left, right);
        quick1(a, left, keyi - 1);
        quick1(a, keyi + 1, right);
    }
}

// 快速排序2
void quick2(int *a, int left, int right)
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
        int keyi = part2(a, left, right);
        quick2(a, left, keyi - 1);
        quick2(a, keyi + 1, right);
    }
}

// 快速排序非递归
void quickNonR(int *a, int left, int right)
{
    ST st;
    STInit(&st);
    STPush(&st, right);
    STPush(&st, left);

    while (!STEmpty(&st))
    {
        int begin = STTop(&st);
        STPop(&st);
        int end = STTop(&st);
        STTop(&st);

        int keyi = part2(a, begin, end);
        if (keyi + 1 < end)
        {
            STPush(&st, end);
            STPush(&st, keyi + 1);
        }

        if (begin < keyi + 1)
        {
            STPush(&st, keyi - 1);
            STPush(&st, begin);
        }
    }
}

//
void _merge(int *a, int *tmp, int begin, int end)
{
    if (begin == end)
        return;

    int mid = (begin + end) / 2;

    // 若[begin,mid][mid+1,end]有序即可进行归并
    _merge(a, tmp, begin, mid);
    _merge(a, tmp, mid + 1, end);

    // 归并
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int i = 0;

    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
        {
            tmp[i++] = a[begin1++];
        }
        else
        {
            tmp[i++] = a[begin2++];
        }
    }

    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }

    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }

    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

// 归并排序
void merge(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }

    _merge(a, tmp, 0, n - 1);
    free(tmp);
}

// 归并排序非递归
void mergeNonR(int *a, int n)
{
    int *tmp = (int *)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail");
        return;
    }

    // gap每组归并数据的个数
    int gap = 1;
    while (gap < n)
    {
        for (int i = 0; i < n; i += 2 * gap)
        {
            //[begin1,end1][begin2,end2]
            int begin1 = i, end1 = i + gap - 1;
            int begin2 = i + gap, end2 = i + 2 * gap - 1;
            int j = 0;

            // 第二组越界，不需要归并
            if (begin2 >= n)
                break;

            // 第二组begin没越界，修正end2
            if (end2 >= n)
                end2 = n - 1;

            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] < a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }

            while (begin1 <= end1)
            {
                tmp[j++] = a[begin1++];
            }

            while (begin2 <= end2)
            {
                tmp[j++] = a[begin2++];
            }

            memcpy(a, tmp + i, sizeof(int) * (end2 - i + 1));
        }
        gap *= 2;
    }
}

// 计数排序，只适合整数/范围集中
void countsort(int *a, int n)
{
    int min = a[0], max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }
    int range = max - min + 1;
    int *count = (int *)calloc(range, sizeof(int));
    if (count == NULL)
    {
        perror("calloc fail");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i] - min]++;
    }
    int j = 0;
    for (int i = 0; i < range; i++)
    {
        while (count[i]--)
        {
            a[j++] = i + min;
        }
    }
}

int main()
{
    return 0;
}