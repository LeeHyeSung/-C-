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
    std::cout << "1. 계좌개설" << std::endl;
    std::cout << "2. 입 금" << std::endl;
    std::cout << "3. 출 금" << std::endl;
    std::cout << "4. 계좌정보 전체 출력" << std::endl;
    std::cout << "5. 프로그램 종료" << std::endl;
    std::cout << "선택: ";
}

bool processCreatingBankAccount(void) {
    BackAccountDataStructure& newbie = gDatabase[gDatabaseCount];
    std::cout << "[계좌개설]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> newbie.id;
    std::cout << "이 름: ";
    std::cin >> newbie.name;
    std::cout << "입금액: ";
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
    std::cout << "[입 금]" << std::endl;
    std::cout << "계좌ID: ";
    std::cin >> id;
    int index = findAccount(id);
    if (index < 0) {
        std::cout << "없는 계좌입니다." << std::endl;
        return false;
    }
    std::cout << "입금액: ";
    std::cin >> deposit;
    gDatabase[index].balance += deposit;
    std::cout << "입금완료" << std::endl;
    return true;
}

void processPrintingAllBackAccount(void) {
    for (int i = 0; i < gDatabaseCount; i++) {
        std::cout << std::endl;
        std::cout << "계좌ID: " << gDatabase[i].id << std::endl;
        std::cout << "이 름: " << gDatabase[i].name << std::endl;
        std::cout << "잔 액: " << gDatabase[i].balance << std::endl;
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