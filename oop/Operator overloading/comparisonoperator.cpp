#include <iostream>
using namespace std;

class Box {
private:
    int volume;

public:
    Box(int v = 0) { volume = v; }
 
bool operator>(const Box&b)
{
       return volume > b.volume;
}
};

int main() {
    Box b1(50), b2(80);
    if (b1 > b2)
        cout << "Box 1 is larger" << endl;
    else
        cout << "Box 2 is larger" << endl;

    return 0;
}
