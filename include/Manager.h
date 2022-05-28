#ifndef MANAGER_H
#define MANAGER_H

#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager:public Worker{
public:
    Manager(int t_id, string t_name, int t_deptId);
    virtual void showInfo();
    virtual string getDeptName();
    ~Manager();
};

#endif // MANAGER_H
