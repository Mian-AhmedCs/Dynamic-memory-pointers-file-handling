#include <iostream>
using namespace std;

class Multiply {
private:
    int num;

public:
    Multiply(int n = 0) { num = n; }

    // Corrected version
    // only return this when we want the first class object as an output 
    Multiply operator*(const Multiply &other)
    {
        Multiply temp;
        temp.num = num * other.num;  // Multiply the two numbers
        return temp;                 // Return new object (by value)
    }

    void show() {
        cout << "Result: " << num << endl;
    }
};

int main() {
    Multiply m1(4), m2(3), m3;
    m3 = m1 * m2;  // Calls operator*()
    m3.show();     // Output: Result: 12
    return 0;
}

