#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// 使用动态规划优化阶乘计算
double factorial(int n)
{
    static double dp[21] = {1}; // 缓存到20!
    if (n <= 20 && dp[n] != 0)
        return dp[n];
    for (int i = 1; i <= n && i <= 20; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n <= 20 ? n : 20]; // 超过20!返回0避免溢出
}

int main()
{
    const int terms = 18; // 取18项（精度达小数点后15位）
    double e = 1.0;
    double current_fact = 1.0;

    for (int i = 1; i <= terms; ++i)
    {
        current_fact *= i; // 递推计算阶乘
        double term = 1.0 / current_fact;
        e += term;

        // 调试输出
        cout << "Term " << setw(2) << i
             << ": 1/" << setw(20) << current_fact
             << " = " << fixed << setprecision(15) << term << endl;
    }

    cout << "\nCalculated e: " << fixed << setprecision(15) << e << endl;
    cout << "Standard e:   " << exp(1.0) << endl;
    return 0;
}