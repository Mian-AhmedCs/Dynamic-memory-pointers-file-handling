#include <iostream>
using namespace std;
class name
{
    private:
    string nam;
    public:
    name()
    {
        nam = "unknown";

    }
    name(string n)
    {
        nam = n;
    }
    void getname(string n)
    {
        nam = n;
    }
    name operator+(const name&other)
    {
        name temp;
          temp.nam = nam + other.nam;
      return temp;
    }
    void show()
    {
        cout<<nam<<endl;
    }
};
int main()
{
    name n1;
    name n2;
    n1.getname("Mian ");
    n2.getname("Ahmed");
    name n3 = n1+n2;
    n3.show();

    return 0;
}