#include <iostream>
using namespace std;

class Bag {
    int size, cSize;
    int *x;

    void resize() {
        int *t = new int[size + size];
        for (int i = 0; i < cSize; i++)
            t[i] = x[i];
        delete [] x;
        x = t;
        size += size;
    }

    void clear() {
        delete [] x;
        x = nullptr;
        size = cSize = 0;
    }

    Bag& copy(const Bag &b) {
        x = new int[b.size];
        for (int i = 0; i < b.cSize; i++)
            x[i] = b.x[i];
        size = b.size;
        cSize = b.cSize;
        return *this;
    }

public:
    Bag(int s = 10) {
        size = s;
        cSize = 0;
        x = new int[size];
    }

    Bag(const Bag &b) {
        copy(b);
    }

    Bag& operator = (const Bag &b) {
        clear();
        return copy(b);
    }

    void show() const {
        for (int i = 0; i < cSize; i++)
            cout << x[i] << ' ';
        cout << "\n";
    }

    // Add single integer
    Bag& operator += (int val) {
        if (cSize == size) resize();
        x[cSize++] = val;
        return *this;
    }

    // Add another Bag
    Bag& operator += (const Bag &b) {
        for (int i = 0; i < b.cSize; i++)
            *this += b.x[i];
        return *this;
    }

    // Pre-decrement: remove last element
    Bag& operator --() {
        if (cSize > 0) cSize--;
        return *this;
    }

    // Equality check (same elements, any order)
bool operator==(const Bag &b) {
    if (cSize != b.cSize) 
        return false;  // Different number of elements → not equal

    for (int i = 0; i < cSize; i++) {
        bool found = false;
        for (int j = 0; j < b.cSize; j++) {
            if (x[i] == b.x[j]) {
                found = true;
                break;
            }
        }
        if (!found) 
            return false; // If any element in current bag is not in b, not equal
    }

    return true; // All elements matched
}


    bool operator != (const Bag &b) {
        return !(*this == b);
    }

    // Duplicate elements n times
    Bag& operator *= (int n) {
        int oldCSize = cSize;
        for (int i = 0; i < oldCSize; i++) {
            int val = x[i];
            for (int j = 1; j < n; j++)  // add n-1 copies
                *this += val;
        }
        return *this;
    }

    // Increment all elements by 1
    Bag& operator ++() {
        for (int i = 0; i < cSize; i++)
            x[i]++;
        return *this;
    }

    // Remove specific element
    Bag& operator -= (int val) {
        for (int i = 0; i < cSize; i++) {
            if (x[i] == val) {
                for (int j = i; j < cSize - 1; j++)
                    x[j] = x[j + 1];
                cSize--;
                i--; // check current index again
            }
        }
        return *this;
    }

    ~Bag() {
        clear();
    }
};

int main() {
    Bag b1, b2;
    b1 += 23; b1 += 5; b1 += 3; b1 += 2;      // b1 = [23,5,3,2]
    b2 += 6; b2 += 5; b2 += 1; b2 += 2; b2 += 4; // b2 = [6,5,1,2,4]

    (b1 += b2).show();  // Expected: 23 5 3 2 6 5 1 2 4

    Bag b3 = b1;
    --b3; --b3;
    b3 += 2; b3 += 2;

    if (b1 == b2) cout << "B1 equal to B2\n";
    else cout << "B1 not equal to B2\n";

    if (b1 == b3) cout << "B1 equal to B3\n";
    else cout << "B1 not equal to B3\n";

    --b3; --b3;
    (b3 *= 3).show();  // Duplicate elements 3 times

    if (b1 != b3) cout << "B1 not equal to B3\n";
    else cout << "B1 equal to B3\n";

    (++b3).show();      // Increment all elements by 1
    (b1 -= 23).show();  // Remove 23 from b1

    return 0;
}
