#ifndef BOSS_H
#define BOSS_H

#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Boss:public Worker{
public:
    Boss(int t_id, string t_name, int t_deptId);
    virtual void showInfo();
    virtual string getDeptName();
    ~Boss();
};

#endif // BOSS_H
