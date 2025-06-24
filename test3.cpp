#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

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

namespace game {}

class User {
  private:
    std::string loginID;
    std::string loginPassword;
    int userID;
    static int totalUsers;
    bool is_in_game;

  public:
    static int gameTime;
    std::string userName;
    float hp;
    float mp;
    int lv;

    User(const std::string& loginID, const std::string& loginPassword, const std::string& userName,
         bool is_in_game = false)
        : loginID(loginID), loginPassword(loginPassword), userName(userName), is_in_game(is_in_game) {
        ++totalUsers;
    }

    void setUserID(int id) { userID = id; }

    void enterGame() { is_in_game = true; }

    int getTotalUsers() const { return totalUsers; }

    int getGameTime() const { return gameTime; }

    void getStats() const {
        std::cout << "🔹 Stats for " << userName << ": HP=" << hp << ", MP=" << mp << ", LV=" << lv << std::endl;
    }
};

int User::totalUsers = 0;
int User::gameTime = 0;

namespace game {
struct CharacterStats {
    float hp;
    std::optional<float> mp;
    int lv;
};



}  // namespace game