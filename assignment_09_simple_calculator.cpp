// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits> // Required for clearing input buffer

using namespace std;

// Function Prototypes
void displayMenu();
double addNumbers(double a, double b);
double subtractNumbers(double a, double b);
double multiplyNumbers(double a, double b);
double divideNumbers(double a, double b, bool& errorFlag);
int modulusNumbers(int a, int b, bool& errorFlag);
double powerNumbers(double base, double exponent);

int main() {
    int choice = 0;

    // Set output formatting to 2 decimal places
    cout << fixed << setprecision(2);

    while (choice != 7) {
        displayMenu();
        cout << "Select an operation (1-7): ";

        // Handle invalid/non-numeric input
        if (!(cin >> choice)) {
            cout << "\nError: Invalid input! Please enter a number between 1 and 7.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 7) {
            cout << "\nGoodbye!\n";
            break;
        }

        if (choice < 1 || choice > 7) {
            cout << "\nError: Invalid choice! Please select an option from 1 to 7.\n";
            continue;
        }

        // Modulus requires integer operands
        if (choice == 5) {
            int num1, num2;
            cout << "Enter first number : ";
            while (!(cin >> num1)) {
                cout << "Error: Modulus requires an integer. Re-enter first number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Error: Modulus requires an integer. Re-enter second number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            bool errorFlag = false;
            int result = modulusNumbers(num1, num2, errorFlag);
            if (!errorFlag) {
                cout << "Result: " << num1 << " % " << num2 << " = " << result << "\n";
            }
        } 
        // Operations 1, 2, 3, 4, 6 support floating-point numbers
        else {
            double num1, num2;
            cout << "Enter first number : ";
            while (!(cin >> num1)) {
                cout << "Error: Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "Enter second number: ";
            while (!(cin >> num2)) {
                cout << "Error: Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            switch (choice) {
                case 1:
                    cout << "Result: " << num1 << " + " << num2 << " = " 
                         << addNumbers(num1, num2) << "\n";
                    break;
                case 2:
                    cout << "Result: " << num1 << " - " << num2 << " = " 
                         << subtractNumbers(num1, num2) << "\n";
                    break;
                case 3:
                    cout << "Result: " << num1 << " * " << num2 << " = " 
                         << multiplyNumbers(num1, num2) << "\n";
                    break;
                case 4: {
                    bool errorFlag = false;
                    double result = divideNumbers(num1, num2, errorFlag);
                    if (!errorFlag) {
                        cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                    }
                    break;
                }
                case 6:
                    cout << "Result: " << num1 << " ^ " << num2 << " = " 
                         << powerNumbers(num1, num2) << "\n";
                    break;
            }
        }
    }

    return 0;
}

// -----------------------------------------------------------------------------
// Displays the main menu
// -----------------------------------------------------------------------------
void displayMenu() {
    cout << "\n============================\n";
    cout << "     SIMPLE CALCULATOR      \n";
    cout << "============================\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Exponentiation\n";
    cout << "7. Quit\n";
}

// -----------------------------------------------------------------------------
// ARITHMETIC FUNCTIONS
// -----------------------------------------------------------------------------

double addNumbers(double a, double b) {
    return a + b;
}

double subtractNumbers(double a, double b) {
    return a - b;
}

double multiplyNumbers(double a, double b) {
    return a * b;
}

// Division with divide-by-zero check
double divideNumbers(double a, double b, bool& errorFlag) {
    if (b == 0) {
        cout << "Error: Cannot divide by zero.\n";
        errorFlag = true;
        return 0.0;
    }
    return a / b;
}

// Modulus with modulo-by-zero check (works on integers)
int modulusNumbers(int a, int b, bool& errorFlag) {
    if (b == 0) {
        cout << "Error: Modulus by zero is undefined.\n";
        errorFlag = true;
        return 0;
    }
    return a % b;
}

// Exponentiation using cmath's pow()
double powerNumbers(double base, double exponent) {
    return pow(base, exponent);
}


