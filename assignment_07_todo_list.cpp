// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for clearing input buffer

using namespace std;

// Function Prototypes
void displayMenu();
void addTask(vector<string>& tasks);
void viewTasks(const vector<string>& tasks);
void deleteTask(vector<string>& tasks);

int main() {
    vector<string> tasks;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cout << "Enter your choice (1-4): ";
        
        // Handle non-integer or invalid input gracefully
        if (!(cin >> choice)) {
            cout << "\nError: Invalid input! Please enter a number between 1 and 4.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                cout << "\nGoodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please select an option from 1 to 4.\n";
                break;
        }
    }

    return 0;
}

// -----------------------------------------------------------------------------
// Displays the main interactive menu
// -----------------------------------------------------------------------------
void displayMenu() {
    cout << "\n============================\n";
    cout << "     TO-DO LIST MENU        \n";
    cout << "============================\n";
    cout << "1. Add task\n";
    cout << "2. View tasks\n";
    cout << "3. Delete task\n";
    cout << "4. Quit\n";
}

// -----------------------------------------------------------------------------
// FEATURE 1: Add a Task
// -----------------------------------------------------------------------------
void addTask(vector<string>& tasks) {
    // Clear newline character left in input buffer by cin >> choice
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string task;
    cout << "\nEnter task: ";
    getline(cin, task);

    if (task.empty()) {
        cout << "Task description cannot be empty!\n";
        return;
    }

    tasks.push_back(task);
    cout << "Task added: \"" << task << "\"\n";
}

// -----------------------------------------------------------------------------
// FEATURE 2: View All Tasks
// -----------------------------------------------------------------------------
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nYour to-do list is currently empty!\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

// -----------------------------------------------------------------------------
// FEATURE 3: Delete a Task
// -----------------------------------------------------------------------------
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks to delete! The list is empty.\n";
        return;
    }

    // Display tasks so user knows the corresponding numbers
    viewTasks(tasks);

    int taskNum;
    cout << "\nEnter task number to delete: ";
    
    if (!(cin >> taskNum)) {
        cout << "Error: Please enter a valid number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    // Convert 1-based user input to 0-based vector index
    if (taskNum < 1 || taskNum > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number! No task was removed.\n";
    } else {
        string removedTask = tasks[taskNum - 1];
        tasks.erase(tasks.begin() + (taskNum - 1));
        cout << "Task \"" << removedTask << "\" has been removed.\n";
    }
}

