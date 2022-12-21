//
// Created by gaybadulov_rk on 21.12.2022.
//

#ifndef OPENMP_COMMANDLINE_H
#define OPENMP_COMMANDLINE_H


#pragma once
#include <iostream>
#include <windows.h>

class CommandLine
{
public:
    CommandLine();
    void startWork();
    static void setColorCmd(int i);
    static void errorOutput(std::string content);
};


#endif //OPENMP_COMMANDLINE_H
