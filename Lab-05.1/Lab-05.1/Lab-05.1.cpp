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

double calculateP(double x)
{
    return 1.0 + pow(x, 2) / 2.0 - pow(x, 4) / 4.0;
}

optional<double> calculateResult(double s)
{
    const double pAtS = calculateP(s);
    const double radicand = pAtS + pow(pAtS, 4);
    if (radicand < 0.0)
    {
        cout << "The expression under the square root must be non-negative." << endl;
        return nullopt;
    }

    const double firstArgument = 1.0 + 2.0 * s + pow(s, 2);
    const double secondArgument = 1.0 + 3.0 * s + pow(s, 3);
    const double firstP = calculateP(firstArgument);
    const double secondP = calculateP(secondArgument);
    const double numerator = pow(firstP, 2) - pow(secondP, 3);
    const double result = numerator / (1.0 + sqrt(radicand));

    return result;
}

int main()
{
    double s;
    cout << "Enter s: ";
    cin >> s;

    const optional<double> result = calculateResult(s);
    if (result)
    {
        cout << setprecision(10) << "Result: " << *result << '\n';
    }

    return 0;
}
