#include <iostream>
#include <fstream>
using namespace std;

int main() {
//    char name[50] = "Mian Ahmed";
//    ofstream file("char.xyz",ios::binary);
//    file.write((char*)name,sizeof(name));
//    file.close();
char arr2[50];
ifstream file("char.xyz",ios::binary);
file.read((char*)arr2,sizeof(arr2));
file.close();


    // ✅ Display result
    cout << "Numbers read from file: ";
        // for (int i = 0; i<50; i++) {
    cout << arr2;

    cout << endl;

    return 0;
}
