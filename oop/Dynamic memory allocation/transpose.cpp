#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    // Step 1: Allocate memory for original matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];

    // Step 2: Take input
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // Step 3: Allocate memory for transpose matrix
    int**transpose = new int*[cols];
    for(int i =0; i < cols;i++)
    {
        transpose[i] = new int [rows];
    }

    // Step 4: Transpose logic (swap rows and columns)
 for(int i = 0; i < rows; i++)
 {
    for(int j = 0; j < cols; j++)
    {
        transpose[jn][i] = matrix[i][j];
    }
 }

    // Step 5: Display original matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Step 6: Display transposed matrix
    cout << "\nTransposed Matrix:\n";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    // Step 7: Free dynamically allocated memory
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    for (int i = 0; i < cols; i++)
        delete[] transpose[i];
    delete[] transpose;

    return 0;
}
