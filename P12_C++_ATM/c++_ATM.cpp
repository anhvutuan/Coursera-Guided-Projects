#include <iostream>
using namespace std;

// Show main menu
void showMenu() {
    cout << "*******************" << endl;
    cout << "*******Menu********" << endl;
    cout << "1. Check balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "*******************" << endl;
}

// Show sub menu after choosing from main menu
void showSubMenu() {
    cout << "*******************" << endl;
    cout << "1. Get back to Main Menue" << endl;
    cout << "2. Exit" << endl;
    cout << "*******************" << endl;
}

int main()
{
// declare inputs variables
    int option;
    int option2;

    double balance=500;

    do {
        // clear the console when getting back to main menu
        system("cls");
        showMenu();
        cout << "Option: ";
        cin >> option;
        // clear the console after choosing from main menu
        system("cls");

        switch (option)
        {
        case 1:
            cout << "Balance is: " << balance << "$" << endl;
            showSubMenu();
            cout << "Option: ";
            cin >> option2;
            break;

        case 2:
            cout << "Deposit amount: ";
            double depositAmount;
            cin >> depositAmount;
            balance += depositAmount;
            showSubMenu();
            cout << "Option: ";
            cin >> option2;
            break;


        case 3:
            cout << "Withdraw amount: ";
            double withdrawtAmount;
            cin >> withdrawtAmount;
            // check if balance enough to withdraw from it
            if (withdrawtAmount <= balance)
                balance -= withdrawtAmount;
            else
                cout << "Not enough money" << endl;
            showSubMenu();
            cout << "Option: ";
            cin >> option2;
            break;

        }
    }
    while ((option!=4) && (option2!=2));

    return 0;
}
