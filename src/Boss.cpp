#include "Boss.h"

Boss::Boss(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Boss::showInfo(){
    cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\t��λ��" << this->getDeptName() << "\t��λְ��:����˾��������" << endl;
}

string Boss::getDeptName(){
    return ("�ϰ�");
}

Boss::~Boss(){
    //dtor
}
