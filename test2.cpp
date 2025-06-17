#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }

float add(float a, float b) { return a + b; }

class Person {
 public:
  string name;
  int age;
  int sum;

  // Constructor (initializes fields when object is created)
  Person(const string& name, int age, int sum) {
    this->name = name;
    this->age = age;
    this->sum = sum;
  }

  // Const method: promises not to modify the object
  void whoareyou() const {
    cout << "Hi, I'm " << name << " and I'm " << age << " years old. My sum is "
         << sum << "." << endl;
  }

  // Inline method inside the class
  void greet() const { cout << "Nice to meet you!" << endl; }
};

// Function that takes input by reference (avoids copying)
void getTwoNumbers(int& a, int& b) {
  cout << "Enter two numbers: ";
  cin >> a >> b;
}

int main() {
  string name;
  int age;
  int x, y;

  cout << "What is her name: ";
  cin >> name;

  cout << "What is her age: ";
  cin >> age;

  getTwoNumbers(x, y);  // pass by reference

  int sum = add(x, y);  // uses int version

  Person p(name, age, sum);  // uses constructor
  p.whoareyou();
  p.greet();

  // Optional: show overloaded float version
  float fx = 2.5f, fy = 3.7f;
  cout << "Float sum: " << add(fx, fy) << endl;

  return 0;
}