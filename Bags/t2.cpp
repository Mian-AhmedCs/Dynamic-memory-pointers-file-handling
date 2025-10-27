 #include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Constructor with default arguments
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // Display function
    void show() {
        cout << "(" << x << ", " << y << ")\n";
    }

    // Overload + operator to add two Points
    void operator + (const Point &p) {
        x += p.x;
        y += p.y;
    }

    // Overload + operator to add an integer to both coordi
    void operator + (int val) {
        x += val;
        y += val;
    }

    // Overload == operator to compare two Points
    bool operator == (const Point &p) {
        return (x == p.x && y == p.y);
    }

    // Overload /= operator to divide coordinates by another Point's coordinates
    void operator /= (const Point &p) {
        if (p.x != 0) x /= p.x;
        if (p.y != 0) y /= p.y;
    }
};

int main() {
    Point p1(3, 4), p2(5, 1);

    cout << "Original Points:\n";
    p1.show(); // (3, 4)
    p2.show(); // (5, 1)

    p1 + p2; // add p2 to p1
    cout << "After p1 + p2:\n";
    p1.show(); // (8, 5)

    p1 + 3; // add 3 to both x and y
    cout << "After p1 + 3:\n";
    p1.show(); // (11, 8)

    if (p1 == p2)
        cout << "p1 is equal to p2\n";
    else
        cout << "p1 is NOT equal to p2\n";

    p1 /= p2; // divide p1 by p2 element-wise
    cout << "After p1 /= p2:\n";
    p1.show(); // (2, 8) because 11/5 = 2, 8/1 = 8

    return 0;
}
