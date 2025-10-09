#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
int* p1 = &arr[0];
int* p2 = &arr[3];

cout << "Distance = " <<(p2 - p1) << endl;  // 3

    return 0;
}