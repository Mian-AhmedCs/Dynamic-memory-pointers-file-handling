#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cin.ignore();
    char* arr = new char[n];
    cout<<"Enter the string"<<endl;
    cin.getline(arr,n);
    cout<<arr;
    ofstream file("newxx.xyz",ios::binary);
    file.write(arr,n);
    file.close();
ifstream file1("newxx.xyz",ios::binary);
char* arr1 = new char[n];
file1.read(arr1,n);
cout<<arr1;
file1.close();
    return 0;
}