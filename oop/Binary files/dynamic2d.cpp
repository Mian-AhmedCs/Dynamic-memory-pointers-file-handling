#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and cols: ";
    cin >> rows >> cols;
    int** arr = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    // Step 3: Input values
    cout << "Enter elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Step 4: Print values
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Step 5: Free memory
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];   // free each row
    }
    delete[] arr;          // free row pointers

    return 0;
}
