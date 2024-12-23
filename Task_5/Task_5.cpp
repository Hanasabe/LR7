#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "../hat.h"

std::string system_3(long long a)
{
    std::string s;
    while (a != 0) // O(log(n))
    {
        s = (char)('0' + a % 3) + s;
        a /= 3;
    }
    while (s.size() < 5)
        s = "0" + s;
    return s;
}

int solution(int n)
{
    std::string barrels[240];
    short int live_or_dead[5] = {2, 2, 2, 2, 2};
    for (int i = 1; i <= 240; i++)
        barrels[i - 1] = system_3(i); // O(log(n))

    std::cout << "\nПервый день:\n\n";

    for (int j = 0; j < 5; j++)
    {
        std::cout << "\x1b[1m" << j + 1 << " раб: \x1b[0m";
        for (int i = 0; i < 240; i++) // O(n)
        {
            if (barrels[i][j] == '0')
            {
                if (i + 1 != n)
                    std::cout << i + 1 << " ";
                if (i + 1 == n)
                {
                    std::cout << "\x1b[31m" << i + 1 << "\x1b[0m" << " ";
                    live_or_dead[j] = 0;
                }
            }
        }
        std::cout << '\n'
                  << '\n';
    }
    for (int i = 0; i < 5; i++) // O(n)
    {
        std::cout << "\x1b[1m" << i + 1 << " раб: " << "\x1b[0m";
        (live_or_dead[i] == 0) ? std::cout << "\x1b[31mмертв\n\x1b[0m" : std::cout << "\x1b[32mжив\n\x1b[0m";
    }
    int h_live = 0;
    for (int i = 0; i < 5; i++) // O(n)
    {
        if (live_or_dead[i] != 0)
            h_live++;
    }
    std::cout << "\nОсталось рабов: " << h_live;
    std::cout << "\n\nВторой день:\n\n";

    for (int j = 0; j < 5; j++) // O(n)
    {
        if (live_or_dead[j] != 0)
            std::cout << "\x1b[1m" << j + 1 << " раб: \x1b[0m";
        else
        {
            std::cout << "\x1b[9m" << j + 1 << " раб\x1b[0m\n\n";
            continue;
        }
        for (int i = 0; i < 240; i++) // O(n)
        {
            if (barrels[i][j] == '1')
            {
                if (i + 1 != n)
                    std::cout << i + 1 << " ";
                if (i + 1 == n)
                {
                    std::cout << "\x1b[31m" << i + 1 << "\x1b[0m" << " ";
                    live_or_dead[j] = 1;
                }
            }
        }
        std::cout << '\n'
                  << '\n';
    }

    int result = 0, live_count = 0;

    for (int i = 4; i >= 0; --i) // O(n)
    {
        if (live_or_dead[i] == 2)
            live_count++;
        result += live_or_dead[i] * pow(3, 4 - i);
    }
    std::cout << "Выживших рабов: " << live_count;
    return result;
}

void hat();

int main()
{
    hat();
    while (true)
    {
        std::cout << "Введите номер отравленной бочки: ";
        int n;
        while (true)
        {
            n = prov();
            if (n < 1 || n > 240)
                std::cout << "Введите число от 1 до 240: ";
            else
                break;
        }
        int result = solution(n);
        std::cout << "\n\nОтравленная бочка: " << result;

        menu();
    }
    return 0;
}













































void hat()
{
    printf("\x1b[1;35m");
    std::cout << "   Задание №5, выполнила Щербицкая Ника" << '\n';
    printf("\x1b[0m");
    printf("\x1b[35m");
    std::cout << "   Суть задания: Патриций решил устроить праздник и для этого приготовил 240 бочек"
                 "вина. Однако к нему пробрался недоброжелатель по имени Пользователь,"
                 "который подсыпал яд в одну из бочек. Недоброжелателя тут же поймали,"
                 "дальнейшая его судьба неизвестна, но ходят слухи, что он проверяет"
                 "консольный ввод в аду в качестве наказания, однако сейчас не об этом. Про яд"
                 "известно, что человек, который его выпил, умирает в течение 24 часов. До"
                 "праздника осталось два дня, то есть 48 часов. У патриция есть пять рабов,"
                 "которыми он готов пожертвовать, чтобы узнать, в какой именно бочке яд. Вы"
                 "близкий друг Патриция и совершенно не хотите стать одним из тех рабов, что"
                 "будут проверять вино на наличие яда. Подойдите к заданию творчески и"
                 "найдите способ определения отравленной бочки с ядом.\n\n";
    printf("\x1b[0m");
}
