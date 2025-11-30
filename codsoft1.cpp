#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    int choice;

    cout << "=== Basic Calculator ===\n";
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "\nChoose operation:\n";
    cout << "1. Addition (+)\n";10
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << fixed << setprecision(2);
            cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
            break;
        case 2:
            cout << fixed << setprecision(2);
            cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
            break;
        case 3:
            cout << fixed << setprecision(2);
            cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << fixed << setprecision(2);
                cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
            } else {
                cout << "Error: Division by zero is not allowed!\n";
            }
            break;
        default:
            cout << "Invalid choice! Please enter 1, 2, 3, or 4.\n";
    }

    return 0;
}
