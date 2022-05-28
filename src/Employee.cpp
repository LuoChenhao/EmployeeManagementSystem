#include "Employee.h"

Employee::Employee(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Employee::showInfo(){
    cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t岗位：" << this->getDeptName() << "\t岗位职责:完成经理下发的任务" << endl;
}

string Employee::getDeptName(){
    return string("员工");
}

Employee::~Employee(){
    //dtor
}


