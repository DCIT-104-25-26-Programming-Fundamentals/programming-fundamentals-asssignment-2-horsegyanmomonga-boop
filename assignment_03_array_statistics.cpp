// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

// Function to calculate the sum of array elements
int findSum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Function to calculate the average of array elements
double findAverage(int arr[], int size) {
    // Cast sum to double for decimal division
    return static_cast<double>(findSum(arr, size)) / size;
}

// Function to find the maximum element in the array
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to find the minimum element in the array
int findMin(int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int main() {
    int count;
    cout << "How many numbers? ";
    cin >> count;

    // Validate size input
    if (count <= 0) {
        cout << "Error: Number of elements must be positive." << endl;
        return 1;
    }

    // Dynamic array allocation based on user input size
    int* numbers = new int[count];

    // Read input elements
    for (int i = 0; i < count; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    // Compute and display results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << findSum(numbers, count) << endl;
    cout << "Average: " << findAverage(numbers, count) << endl;
    cout << "Maximum: " << findMax(numbers, count) << endl;
    cout << "Minimum: " << findMin(numbers, count) << endl;

    // Free memory
    delete[] numbers;

    return 0;
}


