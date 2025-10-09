#include <iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream file("first.com", ios::binary);
    char ch  = 'A';
    file.write((char*)&ch, sizeof(ch));
    file.close();
    //  ifstream file("first.com", ios::binary);
    // char x;
    // file.read((char*)&x, sizeof(x));
    // file.close();
    // cout<<x;


    return 0;
}