#include <iostream>
#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

using namespace std;

int main(){
    WorkerManager wm;
    int choice = 0;

    while(true){
        wm.showMenu();
        cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º";
        cin >> choice;
        switch(choice){
        case 0:
             wm.ExitSystem();
            break;
        case 1:
            wm.AddEmp();
            break;
        case 2:
            wm.showEmp();
            break;
        case 3:
            wm.deleteEmp();
            break;
        case 4:
            wm.updateEmp();
            break;
        case 5:
            wm.findEmp();
            break;
        case 6:
            wm.sortEmp();
            break;
        case 7:
            wm.clearFile();
            break;
        default:
            system("cls");
            break;
        }
    }

    system("pause");
    return 0;
}
