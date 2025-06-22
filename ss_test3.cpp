#include <iostream>
#include <string>

namespace utils {
int addNum(int a, int b, int c) { return a + b + c; }
float addNum(float a, float b, float c) { return a + b + c; }
void setNum(int& a, int& b, int& c) {
    std::cout << "Enter 3 Numbers for Your Pin: ";
    std::cin >> a >> b >> c;
}
using str = std::string;
}  // namespace utils

class User {
  private:
    int pin;
    static int userCount;  

  public:
    utils::str name;
    int age;

    // Constructor with initializer list (modern, efficient)
    User(const utils::str& name, int age) : name(name), age(age), pin(0) { ++userCount; }

    // Getter
    int getPin() const { return pin; }

    // Setter with optional validation
    void setPin(int newPin = 0) {
        if (newPin >= 0)
            pin = newPin;
        else
            std::cout << "❌ Invalid pin: must be non-negative." << std::endl;
    }

    // Inline method
    void whoami() const { std::cout << "👤 Hello, I'm " << name << ". I'm " << age << " years old." << std::endl; }

    void greet() const { std::cout << "👋 Nice to meet you!" << std::endl; }

    static int getUserCount() { return userCount; }
};

int User::userCount = 0;

int main() {
    utils::str userName;
    int userAge;
    int pin1, pin2, pin3;

    std::cout << "What is your name: ";
    std::cin >> userName;

    std::cout << "What is your age: ";
    std::cin >> userAge;

    utils::set3PinNumbers(pin1, pin2, pin3);

    User u(userName, userAge);
    u.setPin(utils::add3Num(pin1, pin2, pin3));

    u.whoami();
    u.greet();
    std::cout << "🔐 Your PIN is: " << u.getPin() << std::endl;
    std::cout << "👥 Users created so far: " << User::getUserCount() << std::endl;

    return 0;
}

