#include "Employee.h"

Employee::Employee(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Employee::showInfo(){
    cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\t��λ��" << this->getDeptName() << "\t��λְ��:��ɾ����·�������" << endl;
}

string Employee::getDeptName(){
    return string("Ա��");
}

Employee::~Employee(){
    //dtor
}


