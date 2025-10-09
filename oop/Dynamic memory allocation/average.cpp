#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int[n];      // allocate dynamic array
    int sum = 0;

    cout << "Enter " << n << " numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    float avg = (float)sum / n;
    cout << "Average = " << avg << endl;

    delete[] arr;               // free memory
    return 0;
}
