
// Lab-05.4.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 5.4
// Обчислення сум та добутків за допомогою рекурсії
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double F(const int i)
{
    return (pow(sin(i), 2) + pow(cos(1.0 / i), 2)) / (i * i);
}

// Ітераційний спосіб
double S0(const int K, const int N)
{
    double s = 1;
    for (int i = K; i <= N; i++)
        s *= F(i);
    return s;
}

// Рекурсивний підйом, параметр зростає
double S1(const int K, const int N, const int i)
{
    if (i > N)
        return 1;
    else
        return F(i) * S1(K, N, i + 1);
}

// Рекурсивний підйом, параметр спадає
double S2(const int K, const int N, const int i)
{
    if (i < K)
        return 1;
    else
        return F(i) * S2(K, N, i - 1);
}

// Рекурсивний спуск, параметр зростає
double S3(const int K, const int N, const int i, double t)
{
    t = t * F(i);
    if (i >= N)
        return t;
    else
        return S3(K, N, i + 1, t);
}

// Рекурсивний спуск, параметр спадає
double S4(const int K, const int N, const int i, double t)
{
    t = t * F(i);
    if (i <= K)
        return t;
    else
        return S4(K, N, i - 1, t);
}

int main()
{
    const int K = 1;
    const int N = 15;

    cout << scientific << setprecision(12);

    cout << "(iter) S0 = " << S0(K, N) << endl;
    cout << "(rec up ++) S1 = " << S1(K, N, K) << endl;
    cout << "(rec up --) S2 = " << S2(K, N, N) << endl;
    cout << "(rec down ++) S3 = " << S3(K, N, K, 1) << endl;
    cout << "(rec down --) S4 = " << S4(K, N, N, 1) << endl;

    return 0;
}