// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Helper function to input a matrix
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Helper function to display a matrix in a neat grid
void printMatrix(const int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// =============================================================================
// PART A — Transpose
// =============================================================================
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}

// =============================================================================
// PART B — Addition
// =============================================================================
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// =============================================================================
// PART C — Multiplication
// =============================================================================
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0; // Initialize cell sum
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;

    cout << "=========================================\n";
    cout << " MATRIX OPERATIONS MENU\n";
    cout << "=========================================\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(A, rows, cols, "A");

        transposeMatrix(A, result, rows, cols);

        cout << "\nOriginal Matrix:\n";
        printMatrix(A, rows, cols);

        cout << "\nTransposed Matrix:\n";
        printMatrix(result, cols, rows); // Dimensions swap for transpose

    } else if (choice == 2) {
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(A, rows, cols, "A");
        readMatrix(B, rows, cols, "B");

        addMatrices(A, B, result, rows, cols);

        cout << "\nResulting Sum Matrix:\n";
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        int m, n, p_rows, p;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "\n--- Matrix A ---\n";
        cout << "Enter number of rows (M): ";
        cin >> m;
        cout << "Enter number of columns (N): ";
        cin >> n;

        cout << "\n--- Matrix B ---\n";
        cout << "Enter number of rows (must be " << n << "): ";
        cin >> p_rows;

        if (p_rows != n) {
            cout << "\nError: Matrix multiplication invalid! Columns in A must equal rows in B.\n";
            return 1;
        }

        cout << "Enter number of columns (P): ";
        cin >> p;

        readMatrix(A, m, n, "A");
        readMatrix(B, n, p, "B");

        multiplyMatrices(A, B, result, m, n, p);

        cout << "\nResulting Product Matrix (A x B):\n";
        printMatrix(result, m, p);

    } else {
        cout << "Invalid choice! Please run the program again.\n";
    }

    return 0;
}


