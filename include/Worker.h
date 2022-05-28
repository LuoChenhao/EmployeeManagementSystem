#ifndef WORKER_H
#define WORKER_H

#pragma once
#include<iostream>
using namespace std;

class Worker{
    public:
        virtual void showInfo() = 0;
        virtual string getDeptName() = 0;
        int id;
        string name;
        int deptId;
};

#endif // WORKER_H
