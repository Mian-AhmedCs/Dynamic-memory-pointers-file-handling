#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];     // array of pointers
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];     // each row allocated

    cout << "Enter elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    int maxVal = matrix[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];

    cout << "Maximum = " << maxVal << endl;

    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    return 0;
}
