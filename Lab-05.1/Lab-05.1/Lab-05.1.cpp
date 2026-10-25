// Lab-05.1.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 5.1
// Обчислення значення виразу для заданого дійсного числа s.
// Варіант 31

#include <cmath>
#include <iomanip>
#include <iostream>
#include <optional>

using namespace std;

double calculateP(double x);
optional<double> calculateResult(double s);

int main()
{
    double s;
    cout << "Enter s: ";
    cin >> s;

    optional<double> result = calculateResult(s);
    cout << setprecision(10) << "Result: " << *result << '\n';

    return 0;
}

optional<double> calculateResult(double s)
{
    double radicand = calculateP(s) + pow(calculateP(s), 4);
    if (radicand < 0.0)
    {
        cout << "The expression under the square root must be non-negative." << endl;
        return nullopt;
    }

    double result = (pow(calculateP(1.0 + 2.0 * s + pow(s, 2)), 2) - pow(calculateP(1.0 + 3.0 * s + pow(s, 3)), 3)) / (1.0 + sqrt(radicand));

    return result;
}

double calculateP(double x)
{
    return 1.0 + pow(x, 2) / 2.0 - pow(x, 4) / 4.0;
}