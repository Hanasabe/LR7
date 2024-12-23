#include <iostream>
#include <limits>
int prov();
int provl();
void menu();
int provll();
int prov()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << "\nНеверный ввод, попробуйте еще раз: ";
    }
    return a;
}

int provl()
{
    double a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << "\nНеверный ввод, попробуйте еще раз: ";
    }
    return a;
}
void menu() {
std::cout << '\n';
        std::cout << '\n'
                  << "▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭" << '\n'
                  << std::endl;

        std::cout << "Введите, чтобы: \n"
                  << "Вновь выполнить задание: 1\n"
                  << "Выйти из программы: 2" << '\n'
                  << std::endl;

        while (true)
        {
            int a;

            a = prov();
            std::cout << '\n';
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (a == 1)
            {
                std::cout << "▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭▬▭" << '\n'
                          << std::endl;
                break;
            }
            if (a == 2)
                exit(0);
            else
                std::cout << "Необходимо ввести число 1 или 2, другие числа или буквы не допускаются!: ";
        }
}

int provll()
{
    long long a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n')
            ;
        std::cout << "\nНеверный ввод, попробуйте еще раз: ";
    }
    return a;
}
