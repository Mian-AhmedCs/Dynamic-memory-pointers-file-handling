#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream file("newx.xyz",ios::binary);
      int a = 5;
      int b= 6;
      int c= 9;
      file.write((char*)&a,sizeof(a));
      file.write((char*)&b,sizeof(b));
      file.write((char*)&c,sizeof(c));
      file.close();
    ifstream file1("newx.xyz",ios::binary);
    int x , y , z;
    file1.read((char*)&x,sizeof(x));
    file1.read((char*)&y,sizeof(y));
    file1.read((char*)&z,sizeof(z));
    file1.close();
    cout<<x<<" "<<y<<" "<<z;
    return 0;
}