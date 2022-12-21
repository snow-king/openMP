//
// Created by gaybadulov_rk on 21.12.2022.
//

#include <sstream>
#include "WorkTask.h"
#include "CommandLine.h"
#include "CalculateTask.h"

/// <summary>Конструктор класса WorkTask.</summary>
WorkTask::WorkTask()
{
    readInputData(); // Читаем входные данные
    initArrayRandomData(); // Инициализируем последовательность чисел
    // Создаем объект класса CalculateTask для вычислений
    CalculateTask cTsk(arrElem, countThreads);
}


/// <summary>Метод для чтения входных данных.</summary>
void WorkTask::readInputData()
{
    CommandLine::setColorCmd(10);
    std::cout << "\nReading input parameters." << std::endl;
    countElements = readElementsFromConsole(); // Вводим количество элементов
    countThreads = readThreadsFromConsole(); // Вводим количество потоков
}


/// <summary>Метод для ввода с консоли количества элементов в последовательности.</summary>
/// <returns>Число элементов в последовательности.</returns>
int WorkTask::readElementsFromConsole()
{
    int readResult;
    bool errorFlag = true;
    // Пока не будет не обнаружено ошибки
    do {
        CommandLine::setColorCmd(14);
        std::cout << "Enter the number of items [" << MIN_COUNT_ELEMENTS << "; " << MAX_COUNT_ELEMENTS << "]:\n";
        CommandLine::setColorCmd(7);
        // Если ввод корректный и число положительное
        if (std::cin >> readResult && readResult >= 0) {
            // Если число соответствует заданному диапазону
            if (readResult >= MIN_COUNT_ELEMENTS && readResult <= MAX_COUNT_ELEMENTS) {
                errorFlag = false;
            } // Иначе сообщение об ошибке диапазона
            else {
                std::stringstream errorContent;
                errorContent << "The input value must be between ["
                             << MIN_COUNT_ELEMENTS << "; "<< MAX_COUNT_ELEMENTS << "]";
                CommandLine::errorOutput(errorContent.str());
            }

        } // Иначе сообщение о некорректном вводе
        else {
            CommandLine::errorOutput("Invalid input");
        }

    } while (errorFlag);

    return readResult;
}


/// <summary>Метод для ввода с консоли количества потоков для вычислений.</summary>
/// <returns>Число потоков.</returns>
int WorkTask::readThreadsFromConsole()
{
    int readResult;
    bool errorFlag = true;
    // Пока не будет не обнаружено ошибки
    do {
        CommandLine::setColorCmd(14);
        std::cout << "Enter the number of threads:\n";
        CommandLine::setColorCmd(7);
        // Если ввод корректный и число положительное
        if (std::cin >> readResult && readResult > 0) {
            errorFlag = false;
        } // Иначе сообщение о некорректном вводе
        else {
            CommandLine::errorOutput("Invalid input");
        }

    } while (errorFlag);

    return readResult;
}


/// <summary>Метод для инициализации последовательности псевдослучайными числами.</summary>
void WorkTask::initArrayRandomData()
{
    srand(time(0));
    for (int i = 0; i < countElements; i++) {
        arrElem.push_back(rand() % ((10000000 + 1) - 100) + 100);
    }
}


/// <summary>Метод для вывода результатов вычислений и времени выполнения.</summary>
/// <param name="name">Наименование режима вычисления</param>
/// <param name="result">Результат</param>
/// <param name="time">Время выполнения</param>
void WorkTask::writeOutputData(std::string name, int result, double time)
{
    CommandLine::setColorCmd(10);
    std::cout << name;
    CommandLine::setColorCmd(14);

    std::cout << "\nResult: " << result << "\nLead time: " << time << " sec.\n";
}
