#include <iostream>
using namespace std;

// Function to find GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
    int num, den; // numerator and denominator

    // Simplify fraction
    void normalize() {
        if (den < 0) {  // make denominator positive
            num = -num;
            den = -den;
        }
        int g = gcd(abs(num), abs(den));
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    // Constructor
    Rational(int n = 0, int d = 1) {
        num = n;
        den = d;
        normalize();
    }

    void show() const {
        cout << num << "/" << den << endl;
    }

    // r1 + r2 → returns new Rational object
    Rational operator+(const Rational& r) const {
        int commonDen = den * r.den / gcd(den, r.den);
        int newNum = num * (commonDen / den) + r.num * (commonDen / r.den);
        Rational res(newNum, commonDen);
        res.normalize();
        return res;
    }

    // r1 -= r2 → subtract r2 from r1 and return current object
    Rational& operator-=(const Rational& r) {
        int commonDen = den * r.den / gcd(den, r.den);
        num = num * (commonDen / den) - r.num * (commonDen / r.den);
        den = commonDen;
        normalize();
        return *this;
    }

    // r1 * r2 → new Rational object
    Rational operator*(const Rational& r) const {
        Rational res(num * r.num, den * r.den);
        res.normalize();
        return res;
    }

    // Equality check
    bool operator==(const Rational& r) const {
        Rational a = *this, b = r;
        a.normalize();
        b.normalize();
        return (a.num == b.num && a.den == b.den);
    }

    // Pre-increment: ++r1
    Rational& operator++() {
        num += den;
        normalize();
        return *this;
    }

    // Post-increment: r1++
    Rational operator++(int) {
        Rational temp = *this;
        num += den;
        normalize();
        return temp;
    }

    // Divide by another Rational: r1 /= r2
    Rational& operator/=(const Rational& r) {
        num *= r.den;
        den *= r.num;
        normalize();
        return *this;
    }

    // Multiply by integer: r1 * 2
    Rational operator*(int val) const {
        Rational res = *this;
        res.num *= val;
        res.normalize();
        return res;
    }

    // Divide by integer: r1 /= 3
    Rational& operator/=(int val) {
        den *= val;
        normalize();
        return *this;
    }
};

int main() {
    Rational r1(2, 3);   // r1 = 2/3
    Rational r2(4, 5);   // r2 = 4/5

    cout << "Initial values:\n";
    r1.show();   // 2/3
    r2.show();   // 4/5

    cout << "\nAddition (r1 + r2): ";
    (r1 + r2).show(); 
    // Dry run:
    // Common denominator: 3*5/gcd(3,5)=15
    // r1: 2*(15/3)=10, r2:4*(15/5)=12
    // Sum = 10+12=22/15 → normalized → 22/15

    cout << "\nSubtraction (r1 -= r2): ";
    (r1 -= r2).show();
    // Dry run:
    // r1 = 2/3, r2 = 4/5
    // Common denominator = 15
    // r1: 2*(15/3)=10, r2:4*(15/5)=12
    // Subtract: 10-12=-2/15 → normalized → -2/15
    // r1 updated to -2/15

    cout << "\nMultiplication (r1 * r2): ";
    (r1 * r2).show();
    // Dry run:
    // r1 = -2/15, r2 = 4/5
    // Multiply numerators: -2*4=-8
    // Multiply denominators: 15*5=75
    // -8/75 → normalized → -8/75

    cout << "\nEquality check (r1 == r2): ";
    cout << ((r1 == r2) ? "Equal" : "Not Equal") << endl;
    // Dry run: -8/75 != 4/5 → Not Equal

    cout << "\nPre-increment (++r1): ";
    (++r1).show();
    // Dry run: r1 = -8/75
    // Pre-increment: r1 + 1 = -8/75 + 75/75 = 67/75
    // r1 updated to 67/75

    cout << "\nPost-increment (r1++): ";
    (r1++).show(); 
    // Dry run: r1 = 67/75
    // Show old value → 67/75
    // Then increment: 67/75 + 75/75 = 142/75
    cout << "After post-increment: ";
    r1.show(); // 142/75

    cout << "\nDivision by another Rational (r1 /= r2): ";
    (r1 /= r2).show();
    // Dry run: r1 = 142/75, r2 = 4/5
    // Divide: 142*5 / 75*4 = 710/300 → normalize → 71/30

    cout << "\nMultiplication by integer (r1 * 2): ";
    (r1 * 2).show();
    // Dry run: r1 = 71/30
    // Multiply numerator by 2 → 142/30 → normalize → 71/15
    // r1 remains 71/30

    cout << "\nDivision by integer (r1 /= 3): ";
    (r1 /= 3).show();
    // Dry run: r1 = 71/30
    // Multiply denominator by 3 → 71/90 → normalized → 71/90

    return 0;
}
