// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> // Required for clearing the input buffer

using namespace std;

// -----------------------------------------------------------------------------
// STRUCT DEFINITION
// -----------------------------------------------------------------------------
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Function Prototypes
void displayMenu();
void addStudent(vector<Student>& students);
void displayAllStudents(const vector<Student>& students);
void calculateStudentAverage(const vector<Student>& students);
double getAverage(const vector<double>& scores);

int main() {
    vector<Student> students;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        cout << "Enter your choice (1-4): ";

        // Handle invalid, non-integer menu inputs
        if (!(cin >> choice)) {
            cout << "\nError: Invalid input! Please enter a number between 1 and 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateStudentAverage(students);
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
// Helper Function: Calculates the average of a vector of scores
// -----------------------------------------------------------------------------
double getAverage(const vector<double>& scores) {
    if (scores.empty()) return 0.0;
    
    double sum = 0.0;
    for (double score : scores) {
        sum += score;
    }
    return sum / scores.size();
}

// -----------------------------------------------------------------------------
// Displays the main interactive menu
// -----------------------------------------------------------------------------
void displayMenu() {
    cout << "\n================================\n";
    cout << "   STUDENT RECORD SYSTEM MENU   \n";
    cout << "================================\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Calculate average score\n";
    cout << "4. Quit\n";
}

// -----------------------------------------------------------------------------
// FEATURE 1: Add a Student
// -----------------------------------------------------------------------------
void addStudent(vector<Student>& students) {
    Student tempStudent;

    // Clear newline character left in input buffer by preceding cin >> choice
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nStudent name: ";
    getline(cin, tempStudent.name);

    cout << "Student ID: ";
    while (!(cin >> tempStudent.id)) {
        cout << "Error: Please enter a valid numerical ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int numScores = 0;
    cout << "How many scores? ";
    while (!(cin >> numScores) || numScores < 0) {
        cout << "Error: Please enter a valid non-negative integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < numScores; ++i) {
        double score;
        cout << "Enter score " << i + 1 << ": ";
        while (!(cin >> score) || score < 0) {
            cout << "Error: Please enter a valid non-negative score: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        tempStudent.scores.push_back(score);
    }

    students.push_back(tempStudent);
    cout << "Student \"" << tempStudent.name << "\" added successfully.\n";
}

// -----------------------------------------------------------------------------
// FEATURE 2: Display All Students
// -----------------------------------------------------------------------------
void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available.\n";
        return;
    }

    cout << "\n" << fixed << setprecision(2);
    cout << "========================================================================\n";
    cout << left << setw(20) << "Name" 
         << setw(12) << "ID" 
         << setw(25) << "Scores" 
         << setw(10) << "Average" << "\n";
    cout << "------------------------------------------------------------------------\n";

    for (const auto& student : students) {
        cout << left << setw(20) << student.name 
             << setw(12) << student.id;

        // Print list of scores inline
        string scoreList = "";
        for (size_t j = 0; j < student.scores.size(); ++j) {
            // Using a stringstream-like approach or direct precision display
            scoreList += to_string(static_cast<int>(student.scores[j])); 
            if (j < student.scores.size() - 1) scoreList += ", ";
        }
        if (scoreList.empty()) scoreList = "None";

        cout << setw(25) << scoreList;
        cout << setw(10) << getAverage(student.scores) << "\n";
    }
    cout << "========================================================================\n";
}

// -----------------------------------------------------------------------------
// FEATURE 3: Calculate Average Score for a Specific Student
// -----------------------------------------------------------------------------
void calculateStudentAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records available to search.\n";
        return;
    }

    int searchID;
    cout << "\nEnter student ID: ";
    if (!(cin >> searchID)) {
        cout << "Error: Invalid ID entered.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    bool found = false;
    for (const auto& student : students) {
        if (student.id == searchID) {
            double avg = getAverage(student.scores);
            cout << fixed << setprecision(2);
            cout << student.name << "'s average score: " << avg << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Error: Student with ID " << searchID << " not found.\n";
    }
}

