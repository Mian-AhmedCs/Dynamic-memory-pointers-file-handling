#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n = "", int a = 0) {
        name = n;
        age = a;
    }

    // Overload assignment operator
    Student &operator=(const Student&other)
    {
        if(this != &other)
        {
        name = other.name;
        age = other.age;
        }
        return*this;
    }
    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1("Mian", 20);
    Student s2;
    s2 = s1; // operator=() is called
    s2.show();
    return 0;
}
