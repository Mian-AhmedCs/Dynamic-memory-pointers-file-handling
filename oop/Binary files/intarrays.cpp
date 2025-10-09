#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    // ✅ Writing array into binary file
    ofstream out("intArray.bin", ios::binary);
    out.write((char*)arr, sizeof(arr));  // write entire array at once
    out.close();

    // ✅ Reading array back
    int arr2[5];  // empty array
    ifstream in("intArray.bin", ios::binary);
    in.read((char*)arr2, sizeof(arr2));
    in.close();

    // ✅ Display result
    cout << "Numbers read from file: ";
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}
