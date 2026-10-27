// Lab-05.5.cpp
// Шийка Сергій Іванович
// Лабораторна робота № 5.5
// Рекурсивні функції
// Варіант 31

#include <iostream>
#include <string>

using namespace std;

string Convert(const unsigned int number, const int base)
{
    const string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (number < base)
        return string(1, digits[number]);

    return Convert(number / base, base) + digits[number % base];
}

int main()
{
    unsigned int number;
    int N;

    cout << "Enter number: ";
    cin >> number;

    cout << "Enter N: ";
    cin >> N;

    if (!cin || N < 2 || N > 36 || number == 0)
    {
        cerr << "Invalid input!" << endl;
        return 1;
    }

    cout << "Binary: " << Convert(number, 2) << endl;
    cout << "Octal: " << Convert(number, 8) << endl;
    cout << "Base " << N << ": " << Convert(number, N) << endl;

    return 0;
}
