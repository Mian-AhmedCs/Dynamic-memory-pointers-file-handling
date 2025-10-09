#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}