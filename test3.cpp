#include <iostream>
#include <string>

namespace utils {
int addNums(int x, int y, int z) { return x + y + z; }
float addNums(float x, float y, float z) { return x + y + z; }
}  // namespace utils

namespace login {
int generateUserID() {
    int x, y, z;
    std::cout << "Enter your 3 favorite numbers: ";
    std::cin >> x >> y >> z;
    return utils::addNums(x, y, z);
}
}  // namespace login

class User {
  private:
    std::string loginID;
    std::string loginPassword;
    int userID;
    static int totalUsers;

  public:
    static int gameTime;
    std::string userName;
    float hp;
    float mp;
    int lv;
    bool is_in_game;

}

int main() {
    
}