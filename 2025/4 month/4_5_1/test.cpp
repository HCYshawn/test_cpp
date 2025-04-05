#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// ʹ�ö�̬�滮�Ż��׳˼���
double factorial(int n)
{
    static double dp[21] = {1}; // ���浽20!
    if (n <= 20 && dp[n] != 0)
        return dp[n];
    for (int i = 1; i <= n && i <= 20; i++)
    {
        dp[i] = dp[i - 1] * i;
    }
    return dp[n <= 20 ? n : 20]; // ����20!����0�������
}

int main()
{
    const int terms = 18; // ȡ18����ȴ�С�����15λ��
    double e = 1.0;
    double current_fact = 1.0;

    for (int i = 1; i <= terms; ++i)
    {
        current_fact *= i; // ���Ƽ���׳�
        double term = 1.0 / current_fact;
        e += term;

        // �������
        cout << "Term " << setw(2) << i
             << ": 1/" << setw(20) << current_fact
             << " = " << fixed << setprecision(15) << term << endl;
    }

    cout << "\nCalculated e: " << fixed << setprecision(15) << e << endl;
    cout << "Standard e:   " << exp(1.0) << endl;
    return 0;
}