//
// Created by gaybadulov_rk on 21.12.2022.
//

#include <omp.h>

#include <utility>
#include "CalculateTask.h"
#include "WorkTask.h"

CalculateTask::CalculateTask(std::vector <int> arr, int countTh): arrElem(std::move(arr)), countThreads(countTh)
{
    // Запускаем режимы вычислений
    executionWithoutThread();
    executionWithThreadCS();
    executionWithThreadRV();
}


/// <summary>Метод для однопоточного вычисления.</summary>
void CalculateTask::executionWithoutThread()
{
    long result =  arrElem[1];

    double time = omp_get_wtime(); // старт таймера
    for (int i = 0; i < arrElem.size(); i++) {
        if (result < arrElem[i])  result = arrElem[i];
    }
    time = omp_get_wtime() - time; // Получаем время
    // Выводим результ и время выполнения
    WorkTask::writeOutputData("Execution in single-threaded mode.", result, time);
}


/// <summary>Метод для многопоточного вычисления с использованием критической секции.</summary>
void CalculateTask::executionWithThreadCS()
{
    long result =  arrElem[1];
    long pResult;

    long time = omp_get_wtime();
    omp_set_dynamic(false);
    omp_set_num_threads(countThreads);
#pragma omp parallel firstprivate(pResult) shared(result)
    {
        pResult = arrElem[1];
#pragma omp for
        for (int i = 0; i < arrElem.size(); i++) {
            if (result< arrElem[i]) result = arrElem[i]  ;
        }
#pragma omp critical
        {
            if (result< pResult)  result = pResult;
        }
    }
    time = omp_get_wtime() - time;

    WorkTask::writeOutputData("Execution in multithreaded mode (critical section).", result, time);
}


/// <summary>Метод для многопоточного вычисления с использованием редуктивной переменной.</summary>
void CalculateTask::executionWithThreadRV()
{
    long result =  arrElem[1];

    long time = omp_get_wtime();
#pragma omp parallel
    for (int i = 0; i < arrElem.size(); i++) {
        if (result< arrElem[i]) result = arrElem[i];
    }
    time = omp_get_wtime() - time;

    WorkTask::writeOutputData("Execution in multithreaded mode (reductive variable).", result, time);
}