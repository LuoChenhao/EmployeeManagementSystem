#ifndef WORKERMANAGER_H
#define WORKERMANAGER_H

#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager{
public:
    WorkerManager();
    //1.显示菜单
    void showMenu();
    //2.退出系统
    void ExitSystem();
    //3.添加职工
    void AddEmp();
    //4.保存文件
    void save();
    //5.统计文件中的人数
    int getEmpNum();
    //6.初始化职工
    void initEmp();
    //7.显示职工
    void showEmp();
    //8.删除职工
    void deleteEmp();
    //9.判断职工是否存在
    int isExist(int id);
    //10.修改职工
    void updateEmp();
    //11.查找职工
    void findEmp();
    //12.按照编号排序
    void sortEmp();
    //13.清空文件
    void clearFile();
    int empNum;
    bool fileIsEmpty;
    Worker **empArray;
    ~WorkerManager();
};

#endif // WORKERMANAGER_H
