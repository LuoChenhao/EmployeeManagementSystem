#include "Manager.h"

Manager::Manager(int t_id, string t_name, int t_deptId){
    this->id = t_id;
    this->name = t_name;
    this->deptId = t_deptId;
}

void Manager::showInfo(){
    cout << "ְ����ţ�" << this->id << "\tְ��������" << this->name << "\t��λ��" << this->getDeptName() << "\t��λְ��:�����ϰ��·������񣬲��ɸ���Ӧ��Ա��" << endl;
}

string Manager::getDeptName(){
    return string("����");
}

Manager::~Manager(){
    //dtor
}
