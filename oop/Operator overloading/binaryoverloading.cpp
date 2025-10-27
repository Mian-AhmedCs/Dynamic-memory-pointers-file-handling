#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Overload + operator
    
Complex operator+(const Complex&other)
{
    Complex temp;
    temp.real = real+other.real;
    temp.imag = imag + other.imag;
    return temp;
    
}

    void show() {
        cout <<real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5), c3;
    c3 = c1 + c2; // operator+() is called
    c3.show();
    return 0;
}
