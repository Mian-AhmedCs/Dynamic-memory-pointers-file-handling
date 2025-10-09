#include <iostream>
using namespace std;

int main() {
    int* p = new int;   // allocate memory for one integer
    *p = 42;            // store value
    cout << "Value: " << *p << endl;

    delete p;           // free memory
    return 0;
}
