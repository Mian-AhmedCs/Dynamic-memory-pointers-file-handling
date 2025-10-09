#include <iostream>
using namespace std;
int main()
{ 
    int arr[3] = {10, 20, 30};
    int *p = arr;
    for(int i = 0; i < 3; i++) {
        cout << *(p + i) << " "; // prints values 10, 20, 30
    }

    char name[6] = "Hello";
    char* a= name;   // pointer to first character

    cout << "Characters in name:" << endl;
    for (int i = 0; i < 5; i++) {   // 5 letters
        cout << *(a + i);
    }



    return 0;
}