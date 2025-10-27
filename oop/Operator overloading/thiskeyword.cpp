#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    Complex(int r = 0, int i = 0) {
        this->real = r;   // using this to remove ambiguity
        this->imag = i;
    }

    Complex operator+(const Complex &other) {
        Complex temp;
        temp.real = real + other.real;
        temp.imag = imag + other.imag;
        return temp;
    }

    Complex operator=(const Complex &other) {
        if (this != &other) {     // prevent self-assignment
            real = other.real;
            imag = other.imag;
        }
        return *this;             // return current object by reference
    }

    void show() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5), c3;
    c3 = c1 + c2;
    c1 = c2;
    c3.show();
    c1.show();
    return 0;
}
