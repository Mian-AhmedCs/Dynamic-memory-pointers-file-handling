#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Copy Constructor
  Student(const  Student &other)
  {
 name = other.name;
 age = other.age;
  }

    void show() {
        cout << name << " " << age << endl;
    }
};

int main() {
    Student s1("Ali", 21);
    Student s2 = s1; // Copy constructor called
    s2.show();
    return 0;
}
