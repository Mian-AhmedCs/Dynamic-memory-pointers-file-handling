#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    int** matrix = new int*[n];
    int** rotated = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        rotated[i] = new int[n];
    }

    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    // Rotate 90° clockwise
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nRotated (90° Clockwise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << rotated[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
        delete[] rotated[i];
    }
    delete[] matrix;
    delete[] rotated;

    return 0;
}
