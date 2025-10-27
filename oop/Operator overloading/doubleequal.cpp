#include <iostream>
using namespace std;

class Number {
private:
    int n;
    public:
    Number(int nu)
    {
         n = nu;
    }
    bool operator==(Number &obj)
    {
            return n == obj.n;
    }
};

int main() {
    Number n1(10), n2(20), n3(5);
if(n1==n2)
{
    cout<<"equal"<<endl;
}
else 
cout<<"not equal"<<endl;
    return 0;
}
