#include <iostream>
#include <string>

int main() {
    std::string s = "Hello";
    int i = 3;
    char c = 'H';
    std::cout << sizeof(s) << '\n';
    std::cout << sizeof(i) << '\n';
    std::cout << sizeof(c) << '\n';
}