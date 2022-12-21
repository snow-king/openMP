//
// Created by gaybadulov_rk on 21.12.2022.
//

#ifndef OPENMP_WORKTASK_H
#define OPENMP_WORKTASK_H
#include <iostream>
#include <vector>

class WorkTask {
public:
    WorkTask();

    static void writeOutputData(std::string name, int result, double time);

private:
    const int MIN_COUNT_ELEMENTS = 100000;
    const int MAX_COUNT_ELEMENTS = 1000000;
    int countElements;
    int countThreads;
    std::vector <int> arrElem;
    void readInputData();
    int readElementsFromConsole();
    int readThreadsFromConsole();
    void initArrayRandomData();
};


#endif //OPENMP_WORKTASK_H
