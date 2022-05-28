#include "Boss.h"

Boss::Boss(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Boss::showInfo(){
    cout << "职工编号：" << this->id << "\t职工姓名：" << this->name << "\t岗位：" << this->getDeptName() << "\t岗位职责:管理公司所有事务" << endl;
}

string Boss::getDeptName(){
    return ("老板");
}

Boss::~Boss(){
    //dtor
}
