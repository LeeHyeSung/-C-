#include <iostream>
// manage bank accounts program.


struct BackAccountDataStructure {
    int id;
    char name[55];
    int balance;
} gDatabase[100];

int gDatabaseCount = 0;

void printProgramMenu(void) {
    std::cout << std::endl;
    std::cout << "-----Menu------" << std::endl;
    std::cout << "1. ���°���" << std::endl;
    std::cout << "2. �� ��" << std::endl;
    std::cout << "3. �� ��" << std::endl;
    std::cout << "4. �������� ��ü ���" << std::endl;
    std::cout << "5. ���α׷� ����" << std::endl;
    std::cout << "����: ";
}

bool processCreatingBankAccount(void) {
    BackAccountDataStructure& newbie = gDatabase[gDatabaseCount];
    std::cout << "[���°���]" << std::endl;
    std::cout << "����ID: ";
    std::cin >> newbie.id;
    std::cout << "�� ��: ";
    std::cin >> newbie.name;
    std::cout << "�Աݾ�: ";
    std::cin >> newbie.balance;
    gDatabaseCount++;
    return true;
}

int findAccount(const int& id) {
    int ret = -1;
    for (int i = 0; i < gDatabaseCount; i++) {
        if (gDatabase[i].id == id) {
            ret = i;
            break;
        }
    }
    return ret;
}

bool processDeposit(void) {
    int id, deposit;
    std::cout << "[�� ��]" << std::endl;
    std::cout << "����ID: ";
    std::cin >> id;
    int index = findAccount(id);
    if (index < 0) {
        std::cout << "���� �����Դϴ�." << std::endl;
        return false;
    }
    std::cout << "�Աݾ�: ";
    std::cin >> deposit;
    gDatabase[index].balance += deposit;
    std::cout << "�ԱݿϷ�" << std::endl;
    return true;
}

void processPrintingAllBackAccount(void) {
    for (int i = 0; i < gDatabaseCount; i++) {
        std::cout << std::endl;
        std::cout << "����ID: " << gDatabase[i].id << std::endl;
        std::cout << "�� ��: " << gDatabase[i].name << std::endl;
        std::cout << "�� ��: " << gDatabase[i].balance << std::endl;
    }
}

int main(void) {
    int in;
    while (true) {
        printProgramMenu();
        std::cin >> in;
        std::cout << std::endl;

        switch (in) {
        case 1: 
            processCreatingBankAccount();
            break;
        case 2:
            processDeposit();
            break;
        case 3:
            break;
        case 4:
            processPrintingAllBackAccount();
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
    return 0;
}