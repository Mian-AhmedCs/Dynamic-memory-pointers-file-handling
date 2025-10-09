#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("output.txt");

    file << "ABCDE";
    cout << "Current write position: " << file.tellp() << endl;

    file.seekp(2);   // move to 3rd position (0-based)
    file << "Z";     // overwrite 'C' with 'Z'

    file.close();

    cout << "Done writing!" << endl;
    return 0;
}
