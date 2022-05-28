#include "WorkerManager.h"

WorkerManager::WorkerManager(){
    //1.�ļ�������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if(!ifs.is_open()){
        //cout << "�ļ�������" << endl;
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    //2.�ļ����ڵ�������Ϊ��
    char c;
    ifs >> c;//����ȡһ���ַ��ж��Ƿ�Ϊend of file
    if(ifs.eof()){
        //cout << "�ļ�Ϊ��" << endl;
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }
    //3.�ļ������Ҳ�Ϊ�մ�������
    //(1)ͳ���ļ��е�����
    int num = this->getEmpNum();
    this->empNum = num;
    cout << "ְ��������Ϊ:" << num << endl;
    //(2)�����ڴ�ռ䣬���ļ��е����ݴ浽������
    this->empArray = new Worker*[this->empNum];
    this->initEmp();
}

void WorkerManager::showMenu(){
    cout << "*********************************************" << endl;
    cout << "***************��ӭʹ��ְ������ϵͳ**********" << endl;
    cout << "******************0.�˳��������*************" << endl;
    cout << "******************1.����ְ����Ϣ*************" << endl;
    cout << "******************2.��ʾְ����Ϣ*************" << endl;
    cout << "******************3.ɾ��ְ����Ϣ*************" << endl;
    cout << "******************4.�޸�ְ����Ϣ*************" << endl;
    cout << "******************5.����ְ����Ϣ*************" << endl;
    cout << "******************6.���ձ������*************" << endl;
    cout << "******************7.��������ĵ�*************" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void WorkerManager::ExitSystem(){
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::AddEmp(){
    cout << "��������ְ��������:" << endl;
    int addNum = 0;
    cin >> addNum;
    if(addNum > 0){
        //1.����ռ�Ĵ�С(ԭ�ռ�+�����ռ�)
        int newSize = this->empNum + addNum;
        Worker **newEmpArray = new Worker*[newSize];
        //2.����ԭ�ռ�����ݵ��¿ռ���
        if(this->empArray != NULL){
            for(int i = 0; i < this->empNum; ++i){
                newEmpArray[i] = this->empArray[i];
            }
        }
        //3.�������������
        for(int i = 0; i < addNum; ++i){
            int id;
            string name;
            int deptSelect;
            cout << "�������" << i + 1 << "����ְ�����" << endl;
            cin >> id;
            cout << "�������" << i + 1 << "����ְ������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ" << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
            cin >> deptSelect;

            Worker *worker = NULL;
            switch(deptSelect){
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            //������ְ����ָ�룬���浽������
            newEmpArray[this->empNum + i] = worker;
        }
        //4.�ͷ�ԭ�еĿռ�
        delete[] this->empArray;
        //5.�����¿ռ�ָ���ָ��
        this->empArray = newEmpArray;
        //6.����ְ������
        this->empNum = newSize;
        //7.���´洢�ļ��Ƿ��
        this->fileIsEmpty = false;
        //8.������&���µ����ݱ��浽�ļ���
        this->save();
        cout << "�ɹ��������" << endl;
    }else{
        cout << "������������" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::save(){
    ofstream ofs;
    //1.������ķ�ʽ���ļ�
    ofs.open(FILENAME, ios::out);
    //2.��ÿ���˵�����д�뵽�ļ���
    for(int i = 0; i < this->empNum; ++i){
        ofs << this->empArray[i]->id << " " << this->empArray[i]->name << " " << this->empArray[i]->deptId << endl;
    }
    //3.�ر��ļ�
    ofs.close();
}

int WorkerManager::getEmpNum(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int deptId;
    int num = 0;
    while(ifs >> id && ifs >> name && ifs >> deptId){
        num ++;
    }
    return num;
}

void WorkerManager::initEmp(){
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int deptId;

    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> deptId){
        Worker *worker = NULL;
        if(deptId == 1){
            worker = new Employee(id, name, deptId);
        }else if(deptId == 2){
            worker = new Manager(id, name, deptId);
        }else{
            worker = new Boss(id, name, deptId);
        }
        this->empArray[index] = worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::showEmp(){
    if(this->fileIsEmpty){
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }else{
        for(int i = 0; i < empNum; ++i){
            //�������಻ͬ�����ö�̬���ó���ӿ�
            this->empArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::deleteEmp(){
    if(this->fileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }else{
        cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if(index != -1){
            //1.����ɾ������(����ǰ��)
            for(int i = index; i < this->empNum - 1; ++i){
                this->empArray[i] = this->empArray[i + 1];
            }
            //2.���������м�¼��Ա�ĸ���
            this->empNum--;
            //3.���ڴ��и��º������ͬ�����ļ���
            this->save();
            cout << "ɾ���ɹ���" << endl;
        }else{
            cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::isExist(int id){
    int index = -1;
    for(int i = 0; i < this->empNum; ++i){
        if(this->empArray[i]->id == id){
            index = i;
            break;
        }
    }
    return index;
}

void WorkerManager::updateEmp(){
    if(this->fileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��!" << endl;
    }else{
        cout << "�������޸�ְ���ı��:" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if(index != -1){
            //1.ɾ��ԭ����
            delete this->empArray[index];
            //2.�������������ݴ�����Ӧ���������
            int newId = 0;
            string newName = "";
            int newDeptId = 0;
            cout << "���ҵ�" << id << "��ְ��" << endl;
            cout << "�������µ�ְ���ţ�";
            cin >> newId;
            cout << "�������µ�������";
            cin >> newName;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cout << "�������λ��";
            cin >> newDeptId;

            Worker *worker = NULL;
            switch(newDeptId){
            case 1:
                worker = new Employee(newId, newName, newDeptId);
                break;
            case 2:
                worker = new Manager(newId, newName, newDeptId);
                break;
            case 3:
                worker = new Boss(newId, newName, newDeptId);
                break;
            default:
                break;
            }
            //3.�������ݲ��뵽������
            this->empArray[index] = worker;
            //4.���ڴ����޸ĺ������ͬ�����ļ���
            this->save();
            cout << "�޸ĳɹ�!" << endl;
        }else{
            cout << "���޴���" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::findEmp(){
    if(this->fileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }else{
        cout << "1.��ְ����Ų���" << endl;
        cout << "2.��ְ����������" << endl;
        cout << "��������ҵķ�ʽ��";
        int select;
        cin >> select;
        if(select == 1){
            //(1)���ձ�Ž���ְ����ѯ
            int id;
            cout << "��������ҵ�ְ����ţ�";
            cin >> id;
            int index = isExist(id);
            if(index != -1){
                cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
                this->empArray[index]->showInfo();
            }else{
                cout << "���޴���" << endl;
            }
        }else if(select == 2){
            //(2)������������ְ����ѯ
            bool flag = false;
            string dname;
            cout << "��������ҵ�������";
            cin >> dname;
            for(int i = 0; i < empNum; ++i){
                if(this->empArray[i]->name == dname){
                    cout << "���ҳɹ�,ְ�����Ϊ" << this->empArray[i]->id << "��ְ����Ϣ���£�" << endl;
                    this->empArray[i]->showInfo();
                    flag = true;
                }
            }
            if(flag == false){
                cout << "����ʧ�ܣ����޴���" << endl;
            }
        }else{
            cout << "����ѡ������!" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::sortEmp(){
    if(this->fileIsEmpty){
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
        system("pause");
        system("cls");
    }else{
        int select = 0;
        cout << "1.����ְ���Ž�����������" << endl;
        cout << "2.����ְ���Ž��н�������" << endl;
        cout << "��ѡ������ķ�ʽ��";
        cin >> select;
        //1.ѡ������
        for(int i = 0; i < this->empNum; ++i){
            //(1)������Сֵor���ֵ�±�
            int minOrMax = i;
            //(2)�������鳢�Ը���minOrMax
            for(int j = i + 1; j < this->empNum; ++j){
                if(select == 1){
                    if(this->empArray[minOrMax]->id > this->empArray[j]->id) minOrMax = j;//��������
                }else if(select == 2){
                    if(this->empArray[minOrMax]->id < this->empArray[j]->id) minOrMax = j;//��������
                }else{
                    cout << "�������" << endl;
                }
            }
            //(3)�ж�����϶���minOrMax�ǲ��Ǽ�������ֵor��Сֵ(��minOrMax�Ƿ����)����������򽻻�i��minOrMax������
            if(i != minOrMax){
                Worker *temp = this->empArray[i];
                this->empArray[i] = this->empArray[minOrMax];
                this->empArray[minOrMax] = temp;
            }
        }
        //2.���ڴ��е�������ͬ�����ļ���
        this->save();
        //3.����������
        cout << "����ɹ��������Ľ��Ϊ��" << endl;
        this->showEmp();
    }
}

void WorkerManager::clearFile(){
    int select = 0;
    cout << "ȷ����գ�" << endl;
    cout << "1.���" << endl;
    cout << "2.����" << endl;
    cin >> select;

    if(select == 1){
        ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ��������´���
        ofs.close();
        if(this->empArray != NULL){
            //1.ɾ�������ڶ�����ÿ�����󣬲���ָ���ÿ�
            for(int i = 0; i < this->empNum; ++i){
                delete this->empArray[i];
                this->empArray[i] = NULL;
            }
            //2.ɾ������������ָ��
            delete[] this->empArray;
            this->empArray = NULL;
            //3.���ݳ�ʼ��
            this->empNum = 0;
            this->fileIsEmpty = true;
        }
        cout << "��ճɹ���" << endl;
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager(){
    if(this->empArray != NULL){
        //1.�������е�ÿһ��Ԫ���ÿ�
        for(int i = 0; i < this->empNum; ++i){
            if(this->empArray[i] != NULL) delete this->empArray[i];
        }
        //2.Ȼ���ٽ������ÿ�
        delete[] this->empArray;
        this->empArray = NULL;
    }
}
