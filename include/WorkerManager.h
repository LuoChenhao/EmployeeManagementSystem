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
    //1.��ʾ�˵�
    void showMenu();
    //2.�˳�ϵͳ
    void ExitSystem();
    //3.���ְ��
    void AddEmp();
    //4.�����ļ�
    void save();
    //5.ͳ���ļ��е�����
    int getEmpNum();
    //6.��ʼ��ְ��
    void initEmp();
    //7.��ʾְ��
    void showEmp();
    //8.ɾ��ְ��
    void deleteEmp();
    //9.�ж�ְ���Ƿ����
    int isExist(int id);
    //10.�޸�ְ��
    void updateEmp();
    //11.����ְ��
    void findEmp();
    //12.���ձ������
    void sortEmp();
    //13.����ļ�
    void clearFile();
    int empNum;
    bool fileIsEmpty;
    Worker **empArray;
    ~WorkerManager();
};

#endif // WORKERMANAGER_H
