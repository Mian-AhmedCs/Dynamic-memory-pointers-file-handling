#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    //  ofstream file("firsts.xyz", ios::binary);
    // int x  = 2;
    // int y = 3;
    // file.write((char*)&x, sizeof(x));
    // file.write((char*)&y, sizeof(y));
    // file.close();
     ifstream file("firsts.xyz", ios::binary);
    int x;
    int y;
    file.read((char*)&x, sizeof(x));
    file.read((char*)&y, sizeof(y));
    file.close();
    cout<<x;
    cout<<y;
    return 0;
}