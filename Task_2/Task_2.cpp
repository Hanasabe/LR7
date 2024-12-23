#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "../hat.h"

#define ll long long

std::string code(ll num)
{
    num = abs(num);  
    std::string binary;
    ll bin = 0, j;
    for (j = 0; num > 0; j++) // O(log(n))
    {
        bin += (num % 2) * pow(10.0, j);  
        num /= 2;  
    }
    binary = std::to_string(bin); // O(log(n))
    return binary;
}

std::string to_obrat_and_dopoln(std::string reverse)
{
    for (ll i = 0; i < reverse.length(); i++) // O(n)
    {
        reverse.at(i) = reverse.at(i) == '1' ? '0' : '1';  
    }
    ll n = reverse.length() - 1;
    for (; n >= 0; n--) // O(n)
    {
        reverse.at(n) = reverse.at(n) == '0' ? '1' : '0';  
        if (reverse.at(n) == '1')  
            break;
    }
    return reverse;
}

std::string vmeste(ll num)
{
    std::string dop_code = "0";
    std::string dop_code2 = "0";
    if (num >= 0)
    {
        dop_code.at(0) = '0';  
        dop_code2 = dop_code.substr(1);  
        dop_code2.resize(code(num).length()); // O(n)
        dop_code2 = code(num); // O(log(n))
    }
    else
    {
        dop_code.at(0) = '1';  
        dop_code2 = dop_code.substr(1);  
        dop_code2.resize(code(num).length()); // O(n)
        dop_code2 = to_obrat_and_dopoln(code(num)); // O(log(n))
    }
    dop_code += dop_code2; // O(n)
    if (num < 0)
        dop_code.at(0) = '1';  
    return dop_code;
}

std::string solution(const std::string a, const std::string b)
{
    std::string result;
    ll carry = 0;

    ll len_a = a.size();  
    ll len_b = b.size();  
    ll max_len = std::max(len_a, len_b) + 1;  

    std::string a_aligned = std::string(max_len - len_a, a[0]) + a; // O(n)
    std::string b_aligned = std::string(max_len - len_b, b[0]) + b; // O(n)

    for (ll i = max_len - 1; i >= 0; --i) // O(n)
    {
        ll bit_a = a_aligned[i] - '0';  
        ll bit_b = b_aligned[i] - '0';  

        ll sum = bit_a + bit_b + carry;  
        result.push_back((sum % 2) + '0');  
        carry = sum / 2;  
    }

    std::reverse(result.begin(), result.end()); // O(n)

    std::string to_sign = result;  
    result = result.substr(result.find_first_not_of(result[0]) == std::string::npos ? result.size() - 1 : result.find_first_not_of(result[0])); // O(n)
    result.insert(result.begin(), to_sign.at(0) == '0' ? '0' : '1');  
    return result;
}

ll konetc(std::string num)
{
    std::string solve = num.substr(1); // O(n)
    if (num.at(0) == '1')
    {
        for (ll i = solve.size() - 1; i >= 0; i--) // O(n)
        {
            if (solve.at(i) == '1')  
            {
                solve.at(i) = '0';  
                break;
            }
            else
                solve.at(i) = '1';  
        }
        for (ll i = 0; i < solve.size(); i++) // O(n)
        {
            solve.at(i) = solve.at(i) == '1' ? '0' : '1';  
        }
    }

    ll sol = 0;

    for (ll i = solve.size() - 1, no = 0; i >= 0; i--, no++) // O(n)
    {
        if (solve.at(i) == '1')  
        {
            sol += pow(2, no);  
        }
    }
    return num.at(0) == '1' ? -sol : sol;  
}

void hat()
{
    printf("\x1b[1;32m");  
    std::cout << "   Задание №2, выполнила Щербицкая Ника, 453501, вариант 14" << '\n';  
    printf("\x1b[0m");  
    printf("\x1b[32m");  
    std::cout << "   Суть задания: Найти сумму двоичных чисел, заданных в естественной форме.\n"
                 "Сложение выполните в дополнительном коде. Ответ выразите в\n"
                 "естественной форме.\n\n";  
    printf("\x1b[0m");  
}

int main()
{
    hat();  
    while (true) {
        ll num1 = 0, num2 = 0;  
        std::cout << "Введите 1 число: ";  
        num1 = prov(); 
        std::cout << "\nВведите 2 число: ";  
        num2 = prov();  
        std::cout << "\nИх сумма(в естественном виде): ";  
        std::cout << konetc(solution(vmeste(num1), vmeste(num2))); // O(n)
        menu();  
    }
    return 0;  
}
