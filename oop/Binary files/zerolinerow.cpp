#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
using namespace std;

int main() {
    int width, height;
    cout << "Enter width of image: ";
    cin >> width;
    cout << "Enter height of image: ";
    cin >> height;

    // Step 1: Dynamically allocate memory for pixel data
    unsigned char *pixels = new unsigned char[width * height];

    // Step 2: Fill the array with random pixel values (0–255)
    srand(time(0));
    for (int i = 0; i < width * height; i++) {
        pixels[i] = rand() % 256;
    }

    // Step 3: Display original matrix
    cout << "\nOriginal Pixel Matrix:\n";
    for (int i = 0; i < height; i++) {
        cout << "Row" << i << ": ";
        for (int j = 0; j < width; j++) {
            cout << (int)pixels[i * width + j] << " ";
        }
        cout << endl;
    }

    // Step 4: Modify every 5th row (make it completely white)
    for (int i = 4; i < height; i += 5) {
        for (int j = 0; j < width; j++) {
            pixels[i * width + j] = 255;  // white pixel
        }
    }

    // Step 5: Display modified matrix
    cout << "\nModified Pixel Matrix (Every 5th Row White):\n";
    for (int i = 0; i < height; i++) {
        cout << "Row" << i << ": ";
        for (int j = 0; j < width; j++) {
            cout << (int)pixels[i * width + j] << " ";
        }
        cout << endl;
    }

    // Step 6: Free memory
    delete[] pixels;

    return 0;
}
