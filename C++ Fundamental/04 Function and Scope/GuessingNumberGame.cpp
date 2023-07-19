# include <iostream>
# include <vector>
# include <cmath>
using namespace std;

int takeGuess() {
    cout << "Please take a guess:" << endl;
    int g;
    cin >> g;
    return g;
}

void playOneGuessingNumberGame(int range = 100) {
    cout << "Welcome to guessing game!" << endl;
    int result = rand() % range + 1;

    while (true) {
        int guess = takeGuess();

        if (guess > result) {
            cout << "Too Large!" << endl;
        } else if (guess < result) {
            cout << "Too Small!" << endl;
        } else {
            cout << "Correct!" << endl;
            break;
        }
    }
}

int main() {

    while (true) {
        playOneGuessingNumberGame();
    }

    return 0;
}
