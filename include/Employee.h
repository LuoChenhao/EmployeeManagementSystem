#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once
#include "Worker.h"
#include <iostream>
using namespace std;

class Employee:public Worker{
public:
    Employee(int t_id, string t_name, int t_deptId);
    void showInfo();
    string getDeptName();
    ~Employee();
};

#endif // EMPLOYEE_H
