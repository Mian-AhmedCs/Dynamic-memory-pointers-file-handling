#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("data.txt");

    if (!file) {
        cout << "File not found!";
        return 0;
    }

    cout << "Initial position: " << file.tellg() << endl;

    char ch;
    file >> ch;
    cout << "Character read: " << ch << endl;

    cout << "Position after reading 1 character: " << file.tellg() << endl;

    file.seekg(0);  // move back to start
    cout << "Position after seekg(0): " << file.tellg() << endl;

    file.close();
    return 0;
}
