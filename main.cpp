#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class PlayerScore { // Клас для рахунку гравця
    public:
        int gameScore; // Змінна рахунку гравця 

        void GainScore(int addScore) { // Функція для додавання 
            gameScore =+ addScore;
        }
        };

int main() {
    srand(time(0)); // Зерно (seed) для генерації випадкових чисел.  
    PlayerScore score;
    cout << score.gameScore << endl;

    return 0;
};