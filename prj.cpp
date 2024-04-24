#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent an expense
struct Expense {
    string category;
    double amount;
    string date;
};

// Structure to represent an income
struct Income {
    string source;
    double amount;
    string date;
};

class PersonalFinanceTracker {
private:
    vector<Expense> expenses;
    vector<Income> incomes;

public:
    void addExpense() {
        Expense expense;
        cout << "Enter expense category: ";
        getline(cin, expense.category);
        cout << "Enter expense amount: ";
        cin >> expense.amount;
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Enter expense date (YYYY-MM-DD): ";
        getline(cin, expense.date);
        expenses.push_back(expense);
        cout << "Expense added successfully." << endl;
    }

    void addIncome() {
        Income income;
        cout << "Enter income source: ";
        getline(cin, income.source);
        cout << "Enter income amount: ";
        cin >> income.amount;
        cin.ignore(); // Ignore the newline character in the input buffer
        cout << "Enter income date (YYYY-MM-DD): ";
        getline(cin, income.date);
        incomes.push_back(income);
        cout << "Income added successfully." << endl;
    }

    void displayExpenses() {
        cout << "Expense History:" << endl;
        cout << "-------------------------" << endl;
        cout << setw(15) << "Category" << setw(15) << "Amount" << setw(15) << "Date" << endl;
        cout << "-------------------------" << endl;
        for (const auto& expense : expenses) {
            cout << setw(15) << expense.category << setw(15) << expense.amount << setw(15) << expense.date << endl;
        }
        cout << "-------------------------" << endl;
    }

    void displayIncomes() {
        cout << "Income History:" << endl;
        cout << "-------------------------" << endl;
        cout << setw(15) << "Source" << setw(15) << "Amount" << setw(15) << "Date" << endl;
        cout << "-------------------------" << endl;
        for (const auto& income : incomes) {
            cout << setw(15) << income.source << setw(15) << income.amount << setw(15) << income.date << endl;
        }
        cout << "-------------------------" << endl;
    }
};

int main() {
    PersonalFinanceTracker tracker;
    int choice;

    do {
        cout << "\nPersonal Finance Tracker Menu:" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. Add Income" << endl;
        cout << "3. Display Expenses" << endl;
        cout << "4. Display Incomes" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character in the input buffer

        switch (choice) {
            case 1:
                tracker.addExpense();
                break;
            case 2:
                tracker.addIncome();
                break;
            case 3:
                tracker.displayExpenses();
                break;
            case 4:
                tracker.displayIncomes();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
