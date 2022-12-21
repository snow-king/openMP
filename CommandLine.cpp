//
// Created by gaybadulov_rk on 21.12.2022.
//

#include "CommandLine.h"
#include "WorkTask.h"

/// <summary>Конструктор класса CommandLine.</summary>
CommandLine::CommandLine()
{
    setColorCmd(3);
    std::cout << "Option №5. Given a sequence of natural numbers  {a0…an–1}.\n"
              << "Create a multi-threaded application to find the maximum ai\n"
}


/// <summary>Метод для запуска работы с командной строкой.</summary>
void CommandLine::startWork()
{
    int choise;
    bool createFlag;
    // Пока программа не завершит работу, будет появляться меню выбора
    do {
        createFlag = false;
        setColorCmd(7);
        std::cout << "\nSelection menu:\n1. Start task;\n2. Exit the program.\nEnter paragraph: ";
        std::cin >> choise;
        switch (choise)
        {
            case 1:
                createFlag = true;
                break;
            case 2:
                exit(0);
                break;
            default:
                errorOutput("Invalid input");
        }

        if (createFlag) {
            // Создаем объект класса WorkTask для работы с задачей
            WorkTask wTsk;
        }

    } while (true);
}


/// <summary>Метод для вывода сообщения об ошибке.</summary>
/// <param name="content">Содержание сообщения</param>


/// <summary>Метод для смены цвета текста в командной строке.</summary>
/// <param name="numColor">Номер цвета</param>
void CommandLine::setColorCmd(int numColor)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, numColor);
}
/// <summary>Метод для вывода сообщения об ошибке.</summary>
/// <param name="content">Содержание сообщения</param>
void CommandLine::errorOutput(const std::string content ) {
    // Выводим красное сообщение об ошибке
    setColorCmd(4);
    std::cout << content << std::endl;
    setColorCmd(7);
    // Перезагружаем поток вывода
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

