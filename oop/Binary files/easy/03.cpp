#include <iostream>
using namespace std;

int main() {
    // Step 1: Declare pointer to float
    float* p ;
    p = new float;

    // Step 3: Assign value
   
*p =3.14;
    // Step 4: Print value
    cout << "Value = " << *p << endl;

    // Step 5: Free memory
    delete p;

    return 0;
}
