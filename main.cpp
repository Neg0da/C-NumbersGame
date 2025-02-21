#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void logMessage(const string & message); // Декларація функції logMessage
void gamePrepare(); // Декларація функції gamePrepare

class PlayerScore { // Клас для рахунку гравця
    public:
        int gameScore; // Змінна рахунку гравця 
        PlayerScore() : gameScore(0) {} // Ініціалізація рахунку нулем

        void GainScore(int addScore) { // Функція для додавання 
            gameScore += addScore;
        }
};

int main() {
    gamePrepare(); // Виклик функції gamePrepare
    return 0;
}

void gamePrepare() { // Оголошення функції gamePrepare
    
    // SEED
    int seed = time(0); // Задаємо значенню seed значення часу.
    srand(seed); // Зерно для генерації випадкових чисел.
    logMessage("srand seed = " + to_string(seed)); // Виводимо випадкове зерно.

    // SCORE PREPARE
    PlayerScore score; // Створюємо об'єкт score класу PlayerScore, який містить рахунок гравця. 
    logMessage("game score initialized: " + to_string(score.gameScore));

    //FIRST NUMBER PREPARE
    int playerNumber = rand() % 100 + 1; // Створює число для гравця, яке спочатку від 0 до 99(включно), а потім додається 1, аби не було 0
    logMessage("player number created = " + to_string(playerNumber));
}

void logMessage(const string & message) { // Реалізація функції logMessage
    cout << "[LOG]: " << message << endl;
}
