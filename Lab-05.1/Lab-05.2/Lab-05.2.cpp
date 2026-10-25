// Lr5.2.cpp
// Шийка Сергій 
// Лабораторна робота № 5.2
// Обчислення суми ряду Тейлора за допомогою функцій
// Варіант 31

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void Sum(const double x, const double eps, int& n, double& s);
void Term(const double x, const int n, double& a);

int main()
{
    double xp, xk, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    if (!cin || !isfinite(xp) || !isfinite(xk) ||
        !isfinite(dx) || !isfinite(eps) ||
        dx <= 0 || eps <= 0 || xp > xk)
    {
        cerr << "Invalid input!" << endl;
        return 1;
    }

    cout << fixed;
    cout << "------------------------------------------------------" << endl;
    cout << "|" << setw(8) << "x" << " |"
        << setw(12) << "Arcth(x)" << " |"
        << setw(12) << "S" << " |"
        << setw(6) << "n" << " |" << endl;
    cout << "------------------------------------------------------" << endl;

    for (double x = xp; x <= xk; x += dx)
    {
        if (fabs(x) <= 1.0)
        {
            cout << "x = " << x << ": |x| must be > 1" << endl;
            continue;
        }

        Sum(x, eps, n, s);

        cout << "|" << setw(8) << setprecision(2) << x << " |"
            << setw(12) << setprecision(6)
            << 0.5 * log((x + 1) / (x - 1)) << " |"
            << setw(12) << setprecision(6) << s << " |"
            << setw(6) << n << " |" << endl;
    }

    cout << "------------------------------------------------------" << endl;

    return 0;
}

void Sum(const double x, const double eps, int& n, double& s)
{
    n = 0;
    s = 0.0;
    double a = 1.0 / x;

    while (fabs(a) >= eps)
    {
        s += a;
        n++;

        Term(x, n, a);
    }
}

void Term(const double x, const int n, double& a)
{
    double R = (2.0 * n - 1.0) /
        ((2.0 * n + 1.0) * x * x);

    a *= R;
}