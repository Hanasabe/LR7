#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include "../hat.h"

char base[] = "0123456789ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghijklmhopqrstuvxyz";

std::string system(int a, int n, int k)
{
    std::string res = "";   
    int N = std::abs(a);   

    while (N > 0) // O(log(n))
    {
        res = base[N % n] + res;   
        N /= n;   
    }

    while (res.size() < k - 1) // O(n)
        res = "0" + res;   

    res = ((a >= 0) ? '0' : base[n - 1]) + res;   
    return res;
}

std::string to_inverse(std::string res, int n)
{
    for (size_t i = 1; i < res.size(); i++) // O(n)
    {
        if (isdigit(res[i]))   
            res[i] = base[(n - 1) - (res[i] - '0')];   
        else
            res[i] = base[(n - 1) - (res[i] - 'A' + 10)];   
    }
    return res;
}

std::string to_dop_code(int a, int n, int k)
{
    if (a >= 0)   
        return system(a, n, k); // O(log(n))
    else
    {
        std::string res = to_inverse(system(a, n, k), n); // O(log(n))
        for (int i = res.size() - 1; i >= 0; i--) // O(n)
        {
            if (res[i] == base[n - 1])   
                res[i] = '0';   
            else
            {
                if (isdigit(res[i]))   
                    res[i] = res[i] + 1;   
                else
                    res[i] = base[(res[i] - 'A' + 10) + 1];   
                break;   
            }
        }
        return res;   
    }
}

std::string pryuamoi(std::string res, int n)
{
    if (res[0] == '0')   
        return res;   
    else
    {
        for (size_t i = 1; i < res.size(); i++) // O(n)
        {
            if (isdigit(res[i]))   
            {
                res[i] = base[(n - 1) - (res[i] - '0')];   
            }
            else
            {
                res[i] = base[(n - 1) - (res[i] - 'A' + 10)];   
            }
        }
        int ostatok = 1;   
        for (int i = res.size() - 1; i >= 0; i--) // O(n)
        {
            int d;
            if (isdigit(res[i]))   
                d = res[i] - '0';   
            else
                d = res[i] - 'A' + 10;   
            int sum = d + ostatok;   
            ostatok = sum / n;   
            res[i] = base[sum % n];   
        }
        res[0] = base[n - 1];   
        return res;   
    }
}

std::string sum(long long a, long long b, std::string res1, std::string res2, int n)
{
    int ostatok = 0;   
    std::string res = "";   
    for (int i = res1.size() - 1; i >= 0; i--) // O(n)
    {
        int d1 = isdigit(res1[i]) ? res1[i] - '0' : res1[i] - 'A' + 10;   
        int d2 = isdigit(res2[i]) ? res2[i] - '0' : res2[i] - 'A' + 10;   
        int sum = d1 + d2 + ostatok;   
        ostatok = sum / n;   
        res = base[sum % n] + res;   
    }

    if (a * b < 0)   
    {
        if (res[0] != '0')   
        {
            res = pryuamoi(res, n); // O(n)
            res[0] = '-';   
        }
    }
    else if (a > 0 && b > 0)   
    {
        if (ostatok != 0)   
            res = base[ostatok] + res;   
    }
    else
    {
        res = pryuamoi(res, n); // O(n)
        res[0] = '-';   
    }
    return res;   
}

std::string sum_minus(long long a, long long b, std::string res1, std::string res2, int n, int k)
{
    b = -b;   
    std::string res = sum(a, b, to_dop_code(a, n, k), to_dop_code(b, n, k), n); // O(log(n))
    return res;   
}

void hat()
{
    printf("\x1b[1;33m");   
    std::cout << "   Задание №3, выполнила Щербицкая Ника, 453501" << '\n';   
    printf("\x1b[0m");   
    printf("\x1b[33m");   
    std::cout << "   Суть задания: Пользователь вводит основание системы счисления. Осуществить"
                 "сложение и вычитание чисел в заданной системе счисления. В другую"
                 "систему счисления не переводить. В системах счисления больших"
                 "десятичной использовать буквы по аналогии с шестнадцатеричной системой."
                 "Разработать функции для выполнения операции сложения и функции для"
                 "выполнения операции вычитания. Предусмотреть ввод положительных и"
                 "отрицательных чисел.\n\n";   
    printf("\x1b[0m");   
}

int main()
{
    hat();   
    while (true)
    {
        long long n, a, b;   
        std::cout << "Введите систему исчисления: ";   
         while (true)
        {
            n = prov();   
            if (n < 2 || n > 62)   
                std::cout << "Введите число от 2 до 62: ";   
            else
                break;   
        }
        std::cout << "Введите первое число: ";   
        std::cin >> a;   
        std::cout << "Введите второе число: ";   
        std::cin >> b;   

        int max = std::max(std::abs(a), std::abs(b));   
        int k = (int)(std::log(max) / std::log(n)) + 2; // O(log(n))

        std::cout << "\n"
                  << "Сумма: "
                  << sum(a, b, to_dop_code(a, n, k), to_dop_code(b, n, k), n); // O(log(n))

        std::cout << "\n"
                  << "Разность: "
                  << sum_minus(a, b, to_dop_code(a, n, k), to_dop_code(b, n, k), n, k); // O(log(n))
        menu();   
    }

    return 0;   
}
