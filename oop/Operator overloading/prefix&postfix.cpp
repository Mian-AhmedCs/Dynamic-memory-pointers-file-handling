#include <iostream>
using namespace std;

class Counter {
private:
    int value;
// when both functions on which we are overloading are the object of same class then we use class data type 
// when operators result is not an object but a value then we use built data types like void 
// when operators result is an object then we use user define data type 
public:
    Counter(int v = 0) { value = v; }
    void operator++()
    {
       ++value;
    }
    void operator++(int)
    {
        value++;
    }
    void show() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c1(5);
    ++c1;   // prefix
    c1++;   // postfix
    c1.show();
    return 0;
}
