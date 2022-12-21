//
// Created by gaybadulov_rk on 21.12.2022.
//

#ifndef OPENMP_CALCULATETASK_H
#define OPENMP_CALCULATETASK_H


#include <vector>

class CalculateTask {
public:
    CalculateTask(std::vector <int> arr, int countTh);
private:
    int countThreads; // Количество потоков
    std::vector <int> arrElem; //Посдеовательность чисел
    void executionWithoutThread();
    void executionWithThreadCS();
    void executionWithThreadRV();
};


#endif //OPENMP_CALCULATETASK_H
