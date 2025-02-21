#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void logArray(int array[], int arraySize); // Декларація функції logArray
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
    logMessage("random seed = " + to_string(seed)); // Виводимо випадкове зерно.

    // SCORE PREPARE
    PlayerScore score; // Створюємо об'єкт score класу PlayerScore, який містить рахунок гравця. 
    logMessage("game score initialized: " + to_string(score.gameScore));

    //FIRST NUMBER PREPARE
    int playerNumber = rand() % 100 + 1; // Створює число для гравця, яке спочатку від 0 до 99(включно), а потім додається 1, аби не було 0
    logMessage("player number created = " + to_string(playerNumber));

    // NUMBERS ARRAY
    int const arraySize = 100;
    int numbersArray[arraySize];

    for (int i = 0; i < arraySize; i++) {
        numbersArray[i] = rand() % 100;
        logMessage("number created in array at index " + to_string(i) + ": " + to_string(numbersArray[i]));
    };

    logArray(numbersArray, arraySize);
}

void logArray(int array[], int arraySize) {
    string log = "numbers array: ";
    for (int i = 0; i < arraySize; i++) {
        log += to_string(array[i]);
        if (i != arraySize - 1) {
            log += ", ";
        };
    };
    logMessage(log);
}

void logMessage(const string& message) { // Реалізація функції logMessage
    // Отримуємо поточний час за допомогою ctime
    time_t now = time(0);  // Отримуємо поточний час
    char* dt = ctime(&now); // Перетворюємо час на строку

    // Виводимо час та повідомлення
    cout << "[" << dt << "] " << message << endl;
}
