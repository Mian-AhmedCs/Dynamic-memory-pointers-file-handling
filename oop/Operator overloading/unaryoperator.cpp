#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
Counter()
{
     value = 0;
}
    Counter(int v) { value = v; }

    void show() {
        cout << "Value: " << value << endl;
    }

    // Overloading prefix ++ operator
 void operator++()
 {
    ++value;
 }
};

int main() {
    Counter c1(5);
    c1.show();
    ++c1;
    c1.show();
    return 0;
}

