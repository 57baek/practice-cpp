#include <iostream>
using namespace std;

int add3Num(int a, int b, int c);

float add(float a, float b, float c) { return a + b + c; }

void set3PinNumbers(int& a, int& b, int& c) {
    cout << "What is your 3 numbers for the Pin: ";
    cin >> a >> b >> c;
}

class User {
  private:
    int pin;

  public:
    string name;
    int age;

    User(const string& name, int age) {
        this->name = name;
        this->age = age;
    }

    int getPin() const { return pin; }

    void setPin(int newSum) { pin = newSum; }

    void whoami() const { cout << "Hello, this is " << name << ". I'm " << age << " years old." << endl; }

    void greet() const { cout << "Nice to meet you!" << endl; }
};

int main() {
    string userName;
    int userAge;
    int pin1;
    int pin2;
    int pin3;
    int sum;

    cout << "What is your name: ";
    cin >> userName;

    cout << "What is your age: ";
    cin >> userAge;

    set3PinNumbers(pin1, pin2, pin3);

    User u(userName, userAge);
    u.setPin(add3Num(pin1, pin2, pin3));
    u.whoami();
    u.greet();
    cout << "My Pin is " << u.getPin() << "." << endl;
}

int add3Num(int a, int b, int c) { return a + b + c; }