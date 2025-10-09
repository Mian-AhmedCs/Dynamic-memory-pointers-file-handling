#include <iostream>
using namespace std;

int main() {
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;
int** jagged =new int*[rows];
int* colSize = new int [rows];
for(int i =0 ; i < rows ; i++)
{
    cout<<"enter number of columns for row "<<i<<": ";
    cin>>colSize[i];
    jagged[i] = new int[colSize[i]];
}
for(int i =0 ; i < rows ; i++)
{
    for(int j =0 ; j < colSize[i] ; j++)
    {
        cout<<"enter element for row "<<i<<" column "<<j<<": ";
        cin>>jagged[i][j];
    }
}


    // Display jagged array
    cout << "\nJagged Array:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < colSize[i]; j++)
            cout << jagged[i][j] << " ";
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < rows; i++)
        delete[] jagged[i];
    delete[] jagged;
    delete[] colSize;

    return 0;
}
