#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";
    unsigned int i1 = 4294967295;
    int i2 = 2147483647;
    char c = 'H';
    std::cout << sizeof(s) << '\n';
    std::cout << sizeof(i1) << '\n';
    std::cout << sizeof(c) << '\n';

    std::cout << &i2 << std::endl;
}