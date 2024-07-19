#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class atm {
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a) {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    long int getAccountNo() { return account_No; }
    string getName() { return name; }
    int getPIN() { return PIN; }
    double getBalance() { return balance; }
    string getMobileNo() { return mobile_No; }

    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {
            mobile_No = mob_new;
            cout << endl << "Successfully Updated Mobile no.";
            _getch();
        } else {
            cout << endl << "Incorrect !!! Old Mobile no";
            _getch();
        }
    }

    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a < balance) {
            balance -= amount_a;
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Available Balance :" << balance;
            _getch();
        } else {
            cout << endl << "Invalid Input or Insufficient Balance";
            _getch();
        }
    }
};

int main() {
    int choice = 0, enterPIN;
    long int enterAccountNo;
    bool isAuthenticated = false;
    atm* authenticatedUser = nullptr;

    vector<atm> users;

    // Creating multiple users
    atm user1, user2, user3;
    user1.setData(987654321, "Hardik", 1234, 50000, "9370054900");
    user2.setData(123456789, "Ankit", 5678, 30000, "9876543210");
    user3.setData(192837465, "Raj", 9012, 15000, "1234567890");

    users.push_back(user1);
    users.push_back(user2);
    users.push_back(user3);

    do {
        system("cls");
        cout << endl << "****Welcome to ATM*****" << endl;
        cout << endl << "Enter Your 9 digit Account No ";
        cin >> enterAccountNo;
        cout << endl << "Enter PIN ";
        cin >> enterPIN;

        for (auto& user : users) {
            if (enterAccountNo == user.getAccountNo() && enterPIN == user.getPIN()) {
                isAuthenticated = true;
                authenticatedUser = &user;
                break;
            }
        }

        if (isAuthenticated && authenticatedUser) {
            do {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                cout << endl << "**** Welcome to ATM *****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash withdraw";
                cout << endl << "3. Show User Details";
                cout << endl << "4. Update Mobile no.";
                cout << endl << "5. Exit" << endl;
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << endl << "Your Bank balance is :" << authenticatedUser->getBalance();
                    _getch();
                    break;

                case 2:
                    cout << endl << "Enter the amount :";
                    cin >> amount;
                    authenticatedUser->cashWithDraw(amount);
                    break;

                case 3:
                    cout << endl << "*** User Details are :- ";
                    cout << endl << "-> Account no :" << authenticatedUser->getAccountNo();
                    cout << endl << "-> Name      :" << authenticatedUser->getName();
                    cout << endl << "-> Balance   :" << authenticatedUser->getBalance();
                    cout << endl << "-> Mobile No. :" << authenticatedUser->getMobileNo();
                    _getch();
                    break;

                case 4:
                    cout << endl << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;
                    cout << endl << "Enter New Mobile No. ";
                    cin >> newMobileNo;
                    authenticatedUser->setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << endl << "Enter Valid Data !!!";
                }
            } while (1);
        } else {
            cout << endl << "User Details are Invalid !!! ";
            _getch();
        }
    } while (1);

    return 0;
}
