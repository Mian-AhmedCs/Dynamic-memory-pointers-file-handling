#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Step 1: Open text file and read n
    ifstream in("numbers.txt");   // file must exist
    int n;
    in >> n;   // first number = size of array

    // Step 2: Allocate array dynamically
    int* arr = new int[n];

    // Step 3: Read n values into array
    for (int i = 0; i < n; i++) {
        in >> arr[i];
    }
    in.close();

    // Step 4: Calculate sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Step 5: Print result
    cout << "Sum of elements = " << sum << endl;

    // Free memory
    delete[] arr;

    return 0;
}
