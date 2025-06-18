#include <iostream>
#include <string>
using namespace std;


// ---------- Section 1: Namespace + Utilities ----------
namespace utils {
int add3Num(int a, int b, int c) { return a + b + c; }

float add(float a, float b, float c) { return a + b + c; }

void set3PinNumbers(int& a, int& b, int& c) {
  cout << "Enter 3 numbers for your pin: ";
  cin >> a >> b >> c;
}

using str = string;  // type alias
}  // namespace utils

// ---------- Section 2: Class with Advanced Features ----------
class User {
 private:
  int pin;
  static int userCount;  // static = shared across all objects

 public:
  utils::str name;
  int age;

  // Constructor with initializer list (modern, efficient)
  User(const utils::str& name, int age) : name(name), age(age), pin(0) {
    ++userCount;
  }

  // Getter
  int getPin() const { return pin; }

  // Setter with optional validation
  void setPin(int newPin = 0) {
    if (newPin >= 0)
      pin = newPin;
    else
      cout << "❌ Invalid pin: must be non-negative." << endl;
  }

  // Inline method
  void whoami() const {
    cout << "👤 Hello, I'm " << name << ". I'm " << age << " years old."
         << endl;
  }

  void greet() const { cout << "👋 Nice to meet you!" << endl; }

  static int getUserCount() { return userCount; }
};

// ---------- Static Initialization ----------
int User::userCount = 0;

// ---------- Section 3: Main ----------
int main() {
  utils::str userName;
  int userAge;
  int pin1, pin2, pin3;

  cout << "What is your name: ";
  cin >> userName;

  cout << "What is your age: ";
  cin >> userAge;

  utils::set3PinNumbers(pin1, pin2, pin3);

  User u(userName, userAge);
  u.setPin(utils::add3Num(pin1, pin2, pin3));

  u.whoami();
  u.greet();
  cout << "🔐 Your PIN is: " << u.getPin() << endl;
  cout << "👥 Users created so far: " << User::getUserCount() << endl;

  return 0;
}