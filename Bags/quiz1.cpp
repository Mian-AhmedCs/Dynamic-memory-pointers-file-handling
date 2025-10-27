#include <iostream>
#include <cstdlib>  // for rand()
#include <ctime>    // for time()
using namespace std;

class Location {
private:
    int houseNo;   // 1 - 100
    int floorNo;   // 1 - 3
    char block;    // A - K

public:
    // 1️⃣ Non-parameterized constructor (random values)
    Location() {
        houseNo = rand() % 100 + 1;        // 1 to 100
        floorNo = rand() % 3 + 1;          // 1 to 3
        block = 'A' + rand() % 11;         // 'A' to 'K'
    }

    // 2️⃣ Parameterized constructor
    Location(int h, int f, char b) {
        if(h < 1) h = 1; if(h > 100) h = 100;
        if(f < 1) f = 1; if(f > 3) f = 3;
        if(b < 'A') b = 'A'; if(b > 'K') b = 'K';
        houseNo = h;
        floorNo = f;
        block = b;
    }

    // 3️⃣ Getter for block
    char getBlock() const {
        return block;
    }

    // 4️⃣ Setter for floor
    void setFloor(int f) {
        if(f >= 1 && f <= 3)
            floorNo = f;
    }

    // 5️⃣ Show function
    void show() const {
        cout << "House No: " << houseNo << ", Floor No: " << floorNo << endl;
        cout << "Block: " << block << endl;
    }

    // 6️⃣ Swap function (swap only if location is different)
    void swap(Location &other) {
        if(houseNo != other.houseNo || floorNo != other.floorNo || block != other.block) {
            int tempHouse = houseNo;
            int tempFloor = floorNo;
            char tempBlock = block;

            houseNo = other.houseNo;
            floorNo = other.floorNo;
            block = other.block;

            other.houseNo = tempHouse;
            other.floorNo = tempFloor;
            other.block = tempBlock;
        }
    }

    // 7️⃣ Improve / change location
    // If block is smaller alphabetically OR floor is lower
    void improve(Location &other) {
        if(block < other.block || floorNo < other.floorNo) {
            houseNo = other.houseNo;
            floorNo = other.floorNo;
            block = other.block;
        }
    }
};
int main() {
    srand(time(0));

    Location loc1;                // random location
    Location loc2(50, 2, 'F');    // parameterized location

    cout << "Before swap:" << endl;
    loc1.show();
    loc2.show();

    loc1.swap(loc2);

    cout << "\nAfter swap:" << endl;
    loc1.show();
    loc2.show();

    // Improve example
    loc1.improve(loc2);
    cout << "\nAfter improve:" << endl;
    loc1.show();

    // Setter and Getter example
    loc1.setFloor(3);
    cout << "\nBlock of loc1: " << loc1.getBlock() << endl;
    loc1.show();

    return 0;
}
