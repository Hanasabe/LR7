#include <iostream>
#include <string>
#include <cmath>
#include "../hat.h"

std::string reverse(std::string reverse)
{
    long long n = reverse.length() - 1;
    for (; n >= 0; n--) //O(n)
    {

        if (reverse.at(n) == '1')
        {
            reverse.at(n) = '0';
            break;
        }
        else
            reverse.at(n) = '1';
    }
    return reverse;
}

std::string reverse2(std::string reverse2)
{
    for (long long i = 0; i < reverse2.length(); i++) // O(n)
    {
        if (reverse2.at(i) == '1')
            reverse2.at(i) = '0';
        else
            reverse2.at(i) = '1';
    }
    return reverse2;
}

long long solution(std::string solution)
{
    long long n = solution.length() - 1;
    long long num = 0;
    for (long long i = 0; i < solution.length(); i++, n--) // O(n)
    {
        if (solution.at(i) == '1')
        {
            num += pow(2, n); // O(log(n))
        }
    }
    return num;
}
long long task(std::string binary)
{
    long long num;
    long long n = binary.length();
    // отрицательное число
    if (binary == "10000000")
        return -128;
    if (binary.at(0) == '1')
    {
        binary = reverse2(reverse(binary.substr(1))); // O(n)
        num = -(solution(binary)); //O(n * log(n))
    }
    // положительное число
    else
    {
        num = (solution(binary.substr(1))); //O(n * log(n))
    }
    return num;
}

void hat()
{
    printf("\x1b[1;31m");
    std::cout << "   Задание №1, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';
    printf("\x1b[0m");
    printf("\x1b[31m");
    std::cout << "   Суть задания: Перевести число с дополнительного кода в естественную форму\n\n";
    printf("\x1b[0m");
}

int main()
{
    hat();
    while (true)
    {
        std::string binary;
        std::cout << "Введите число: ";
        std::cin >> binary;
        /*while (true)
        {
            std::cin >> binary;
            for (long long i = 0; i < binary.size(); i++)
            {
                if (binary.at(i) != '0' && binary.at(i) != '1')
                {
                    std::cout << "Число должно состоять из 0 и 1: ";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                i2 = i;
            }
            if (i2 == binary.size() - 1)
            break;
        }*/
        std::cout << "\nЧисло в естественной форме: ";
        std::cout << task(binary); //O(n * log(n))
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        menu();
    }
    return 0;
}