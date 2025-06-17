#include <iostream>
using namespace std;

int add(const int& a, const int& b) { return a + b; }

class Person {
 public:
  string name;
  int sum;
  int age;

  void whoareyou() {
    cout << "Hi, I'm " << name << sum << " and I'm " << age << " years old!"
         << endl;
  }
};

int main() {
  string name;
  int age;
  int x, y;

  cout << "What is her name: ";
  cin >> name;

  cout << "What is her age: ";
  cin >> age;

  cout << "What is her two numbers: ";
  cin >> x >> y;

  int sum = add(x, y);

  Person p;
  p.name = name;
  p.age = age;
  p.sum = sum;

  p.whoareyou();

  return 0;
}