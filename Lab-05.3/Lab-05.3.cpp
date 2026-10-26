
// Lab-05.3.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 5.3
// Обчислення значення виразу за допомогою функцій
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Sum(const double x);
double Term(const double x, const int n, const double a);
double j(const double x);
double calculateResult(const double k);

int main()
{
    double kp, kk;
    int n;

    cout << "kp = "; cin >> kp;
    cout << "kk = "; cin >> kk;
    cout << "n = "; cin >> n;

    if (!cin || !isfinite(kp) || !isfinite(kk) ||
        kp > kk || n <= 0)
    {
        cerr << "Invalid input!" << endl;
        return 1;
    }

    const double dk = (kk - kp) / n;

    cout << fixed << setprecision(6);

    cout << "-------------------------------" << endl;
    cout << "|" << setw(12) << "k" << " |"
        << setw(14) << "F(k)" << " |" << endl;
    cout << "-------------------------------" << endl;

    for (int i = 0; i <= n; i++)
    {
        const double k = kp + i * dk;
        const double result = calculateResult(k);

        cout << "|" << setw(12) << k << " |"
            << setw(14) << result << " |" << endl;
    }

    cout << "-------------------------------" << endl;

    return 0;
}

double calculateResult(const double k)
{
    return j(k) + pow(j(k - 1.0), 2) + 2.0 * j(1.0);
}

double j(const double x)
{
    if (fabs(x) >= 1.0)
    {
        return (sin(x) + 1.0) / (pow(cos(x), 2) + exp(x));
    }
    else
    {
        return Sum(x) / cos(2.0 * x);
    }
}

double Sum(const double x)
{
    double a = 1.0;
    double s = a;

    for (int n = 1; n <= 7; n++)
    {
        a = Term(x, n, a);
        s += a;
    }

    return s;
}

double Term(const double x, const int n, const double a)
{
    return a * (4.0 * x * x) /
        ((2.0 * n - 1.0) * (2.0 * n));
}
