#include <chrono>
#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>

namespace utils {

constexpr int addNums(int x, int y, int z) { return x + y + z; }
constexpr float addNums(float x, float y, float z) { return x + y + z; }
constexpr double nth(double x, int n) {
    if (n < 0) return 0.0;

    double res = 1.0;
    for (int i = 0; i < n; ++i) {
        res *= x;
    }
    return res;
}
}  // namespace utils

namespace login {

int generateUserID() {
    int x, y, z;
    std::cout << "Enter 3 favorite numbers: ";
    std::cin >> x >> y >> z;
    const int userID = utils::addNums(x, y, z);
    return utils::nth(userID, x);
}
}  // namespace login

class User {
  private:
    std::string loginID;
    std::string loginPassword;
    int userID;
    static int totalUsers;
    bool isInGame = false;
    std::chrono::steady_clock::time_point startTime;

  public:
    static int gameTime;
    std::string userName;
    float hp = 0;
    std::optional<float> mp = 0;
    int lv = 0;

    User(const std::string& loginID, const std::string& loginPassword, const std::string& userName)
        : loginID(loginID),
          loginPassword(loginPassword),
          userName(userName),
          userID(login::generateUserID()) 
    {
        ++totalUsers;
    }

    int getTotalUsers() const { return totalUsers; }

    void printStats() const {
        std::cout << "🔹 Stats for " << userName << ": HP=" << hp;
        if (mp.has_value())
            std::cout << ", MP=" << mp.value();
        else
            std::cout << ", MP=N/A";
        std::cout << ", LV=" << lv << '\n';
    }

    void enterGame() {
        isInGame = true;
        startTime = std::chrono::steady_clock::now();  // Record current time
    }

    void endGame() {
        if (isInGame) {
            auto endTime = std::chrono::steady_clock::now();
            gameTime = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
            std::cout << "🕒 Total Game Time: " << gameTime << " seconds\n";
            isInGame = false;
            gameTime = 0;  // Reset for next game
        } else {
            std::cout << "⚠️ You're not in a game.\n";
        }
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

std::unordered_map<std::string, CharacterStats> characterMap = {{"Garen", {620.0f, std::nullopt, 1}},
                                                                {"Ahri", {570.0f, 418.0f, 1}},
                                                                {"Ezreal", {530.0f, 375.0f, 1}},
                                                                {"Lux", {490.0f, 480.0f, 1}},
                                                                {"LeeSin", {645.0f, 200.0f, 1}}};

void playGame(User& user, const std::string& characterName) {
    if (characterMap.count(characterName)) {
        CharacterStats stats = characterMap[characterName];
        user.hp = stats.hp;
        user.mp = stats.mp;  // copy optional to optional (OK)
        user.lv = stats.lv;
        user.enterGame();
        std::cout << "✅ " << characterName << " selected. Game started.\n";
    } else {
        std::cout << "❌ Character not found. Try again.\n";
    }
}

void printChampionStats(const std::string& name) {
    if (characterMap.count(name)) {
        CharacterStats stats = characterMap[name];
        std::cout << "Champion: " << name << "\n";
        std::cout << "HP: " << stats.hp << "\n";
        std::cout << "MP: ";
        if (stats.mp.has_value())
            std::cout << stats.mp.value();
        else
            std::cout << "N/A";
        std::cout << "\nLevel: " << stats.lv << "\n";
    } else {
        std::cout << "❌ Champion \"" << name << "\" not found.\n";
    }
}
}  // namespace game

int main() {
    std::string id, pw, name;

    std::cout << "Enter login ID: ";
    std::cin >> id;

    std::cout << "Enter password: ";
    std::cin >> pw;

    std::cout << "Enter username: ";
    std::cin >> name;

    User u(id, pw, name);

    std::string selectedChar;
    std::cout << "Choose your character (Garen, Ahri, Ezreal, Lux, LeeSin): ";
    std::cin >> selectedChar;

    game::playGame(u, selectedChar);
    u.printStats();

    return 0;
}