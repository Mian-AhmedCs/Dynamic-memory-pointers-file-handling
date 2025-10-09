#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string type, comment;
    int width, height, maxval;

    // Step 1: Open the binary PGM file for reading
    ifstream in("output_binary.pgm", ios::binary);
    if (!in) {
        cout << "File could not be opened!" << endl;
        return 1;
    }

    // Step 2: Read the PGM header (first few lines)
    getline(in, type);         // Example: "P5"
    getline(in, comment);      // Example: "# Created by xyz"
    in >> width >> height >> maxval;   // Example: "640 480 255"
    in.ignore(); // ignore the newline after header

    // Step 3: Dynamically allocate memory for image pixels
    unsigned char *pixels = new unsigned char[height * width];

    // Step 4: Read the binary pixel data into the array
    in.read((char*)pixels, width * height);

    // Step 5: Close the file
    in.close();

    // (Optional) Display basic info
    cout << "PGM Type: " << type << endl;
    cout << "Comment: " << comment << endl;
    cout << "Width: " << width << ", Height: " << height << endl;
    cout << "Max Value: " << maxval << endl;

    // Example: show first few pixel values
    cout << "First 10 pixel values: ";
    for (int i = 0; i < 10; i++)
        cout << (int)pixels[i] << " ";

    // Step 6: Free memory
    delete[] pixels;

    return 0;
}
