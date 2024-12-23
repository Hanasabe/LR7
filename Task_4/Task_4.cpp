#include <iostream>
#include "../hat.h"

bool del_na_chiclo(long long x, long long num)
{
    while (x > num) // log(n)
    {
        x = x & 1 ? num + x : x;
        x = x >> 1;
    }
    return (x == num);
}

void hat()
{
    printf("\x1b[1;32m");
    std::cout << "   Задание №4, выполнила Щербицкая Ника, 453501" << '\n';
    printf("\x1b[0m");
    printf("\x1b[32m");
    std::cout << "   Суть задания: Проверить делимость на 11, 43, 179";
    printf("\x1b[0m");
}

int main()
{
    hat();
    while (true) {
    long long n;
    std::cout << "\n\nВведите натуральное число: ";
    n = provll();
    std::cout << '\n' << n << " делится на: ";
    if (del_na_chiclo(n, 11)) // log(n)
    std::cout << 11 << " ";
    if (del_na_chiclo(n, 43)) // log(n)
    std::cout << 43 << " ";
    if (del_na_chiclo(n, 179)) // log(n)
    std::cout << 179 << " ";
    menu ();
    }
    return 0;
}