#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction structure
struct Transaction {
    string type;
    double amount;
};

// Account class
class Account {
public:
    int accountNumber;
    string ownerName;
    double balance;
    vector<Transaction> history;

    Account(int accNo, string name) {
        accountNumber = accNo;
        ownerName = name;
        balance = 0.0;
    }

    void deposit(double amount) {
        balance += amount;
        history.push_back({"Deposit", amount});
        cout << "Deposit successful!\n";
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back({"Withdraw", amount});
            cout << "Withdrawal successful!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            history.push_back({"Transfer to " + receiver.ownerName, amount});
            receiver.history.push_back({"Received from " + ownerName, amount});
            cout << "Transfer successful!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    void showBalance() {
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Owner Name: " << ownerName << "\n";
        cout << "Current Balance: $" << balance << "\n";
    }

    void showTransactions() {
        cout << "\nTransaction History:\n";
        for (Transaction t : history) {
            cout << t.type << " - $" << t.amount << "\n";
        }
    }
};

int main() {
    // Create two accounts
    int accNo1, accNo2;
    string name1, name2;

    cout << "Enter Account 1 number: ";
    cin >> accNo1;
    cout << "Enter Account 1 owner name: ";
    cin >> ws;
    getline(cin, name1);

    cout << "Enter Account 2 number: ";
    cin >> accNo2;
    cout << "Enter Account 2 owner name: ";
    cin >> ws;
    getline(cin, name2);

    Account acc1(accNo1, name1);
    Account acc2(accNo2, name2);

    int choice;
    do {
        cout << "\n=== Banking Menu ===\n";
        cout << "1. Deposit (Account 1)\n";
        cout << "2. Withdraw (Account 1)\n";
        cout << "3. Transfer from Account 1 to Account 2\n";
        cout << "4. Show Account 1 Info\n";
        cout << "5. Show Account 2 Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc1.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;
            case 3:
                cout << "Enter amount to transfer: ";
                cin >> amount;
                acc1.transfer(acc2, amount);
                break;
            case 4:
                acc1.showBalance();
                acc1.showTransactions();
                break;
            case 5:
                acc2.showBalance();
                acc2.showTransactions();
                break;
            case 6:
                cout << "Thank you for using the banking system!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
