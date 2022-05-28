#include "Manager.h"

Manager::Manager(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Manager::showInfo(){
    cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t岗位：" << this->getDeptName() << "\t岗位职责:接收老板下发的任务，并派给相应的员工" << endl;
}

string Manager::getDeptName(){
    return string("经理");
}

Manager::~Manager(){
    //dtor
}
