#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr;  // points to first element (arr[0])

    cout << "Pointer starts at arr[0]: " << *p << endl;

    // Move forward
    p++;  // now points to arr[1]
    cout << "After p++ : " << *p << endl;

    p += 2;  // now points to arr[3]
    cout << "After p += 2 : " << *p << endl;

    // Move backward
    p--;  // now points to arr[2]
    cout << "After p-- : " << *p << endl;

    p -= 2;  // now points to arr[0]
    cout << "After p -= 2 : " << *p << endl;

    return 0;
}
