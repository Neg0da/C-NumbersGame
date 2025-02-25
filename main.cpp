#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <limits>

using namespace std;

bool loggingEnabled = false;
bool continueGame = true;

void logArray(int array[], int arraySize); // Декларація функції logArray
void logMessage(const string & message); // Декларація функції logMessage
void clearConsole(); // Декларація очищення консолі

class PlayerScore { // Клас для рахунку гравця
    public:
        int gameScore; // Змінна рахунку гравця 
        PlayerScore() : gameScore(0) {} // Ініціалізація рахунку нулем

        void GainScore(int addScore) { // Функція для додавання 
            gameScore += addScore;
        }
};

int main() {
    while (continueGame) {
        char choice;
        cout << "Почати грати? (d - з логами, будь-яка інша клавіша - без логів): ";
        cin >> choice;

        loggingEnabled = (tolower(choice) == 'd');

        // SEED
        int seed = time(0); // Задаємо значенню seed значення часу.
        srand(seed); // Зерно для генерації випадкових чисел.
        logMessage("random seed = " + to_string(seed)); // Виводимо випадкове зерно.

        // SCORE PREPARE
        PlayerScore score; // Створюємо об'єкт score класу PlayerScore, який містить рахунок гравця. 
        logMessage("game score initialized: " + to_string(score.gameScore));

        // FIRST NUMBER PREPARE
        int playerNumber = rand() % 100 + 1; // Створює число для гравця, яке спочатку від 0 до 99(включно), а потім додається 1, аби не було 0
        logMessage("player number created = " + to_string(playerNumber));

        cout << "Запам'ятайте це число: " + to_string(playerNumber)<< endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        
        // GAME LOOP
        bool gameInProgress = true;
            while(gameInProgress) {
                int playerTask; // Змінна для завдання гравцю (ВИПАДКОВЕ ЧИСЛО)
                char actionsList[] = {'+', '-', '*', '/'}; // Масив з діями
                int randomAction = rand() % 4; // Випадкова дія (з масиву)
                if (randomAction == 0 || randomAction == 1){
                    playerTask = rand() % 20 + 1;
                } else if (randomAction == 2){
                    playerTask = rand() % 3 + 1;
                } else if (randomAction == 3){
                    playerTask = rand() % 3 + 2;
                    while (playerTask == 0 || playerNumber % playerTask != 0) {
                        playerTask = rand() % 5 + 2;
                    }
                }
                
                clearConsole();
                cout << actionsList[randomAction] << playerTask << endl; // Випадкова дія з масиву
                cout << "Введіть відповідь: \n";
                int suggestAnswer; // Відповідь гравця
                int correctAnswer; // Правильна відповідь
                switch (randomAction) {
                    case 0: // Додавання
                        correctAnswer = playerNumber + playerTask;
                        break;
                    case 1: // Віднімання
                        correctAnswer = playerNumber - playerTask;
                        break;
                    case 2: // Множення
                        correctAnswer = playerNumber * playerTask;
                        break;
                    case 3: // Ділення
                        correctAnswer = playerNumber / playerTask;
                        break;
                }
                logMessage("correct answer: " + to_string(correctAnswer));
                cin >> suggestAnswer;
                if (suggestAnswer == correctAnswer) {
                    cout << "Відповідь вірна!" << endl;
                    int scoreScale = correctAnswer % 10 + randomAction;
                    score.GainScore(scoreScale);
                    logMessage("new score: " + to_string(score.gameScore));
                    playerNumber = correctAnswer;
                } else {
                    cout << "Відповідь невірна!" << endl;
                    gameInProgress = false;
                }
            };

        cout << "Кінець. Рахунок гравця: " << score.gameScore << endl;
        cout << "Продовжити грати? (q - закінчити, будь-яка інша клавіша - продовжити): ";
        cin >> choice;

        if (tolower(choice) == 'q') {
            continueGame = false;
        }
    }

    return 0;
}

void clearConsole() {
    cout << "\033[2J\033[H";  // Очищення екрану та переміщення курсора у верхній лівий кут
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

void logMessage(const string& message) {
    if (!loggingEnabled) return;

    time_t now = time(0);
    tm* localTime = localtime(&now);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%a %b %d %H:%M:%S %Y", localTime);

    cout << "[" << buffer << "] " << message << endl;
}