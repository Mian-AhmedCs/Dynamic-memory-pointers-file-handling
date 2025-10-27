#include <iostream>
using namespace std;

class Distance {
private:
    int meter;

public:
    Distance(int m = 0) { meter = m; }

   Distance operator-(const Distance &other){
    Distance temp;
    temp = meter - other.meter;
    return temp;

   }

    void show() {
        cout << "Meters: " << meter << endl;
    }
};

int main() {
    Distance d1(10), d2(4), d3;
    d3 = d1 - d2;
    d3.show();
    return 0;
}
