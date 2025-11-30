#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {
    // Seed random number generator with current time
    srand(static_cast<unsigned int>(time(nullptr)));
    
    // Generate random number between 1 and 100
    int secretNumber = rand() % 100 + 1;5
    int userGuess = 0;
    int attempts = 0;
    
    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I've picked a number between 1 and 100.\n";
    cout << "Try to guess it!\n\n";
    
    // Loop until correct guess
    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;
        
        if (userGuess > secretNumber) {
            cout << "Too high! Try again.\n\n";
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n\n";
        } else {
            cout << "Congratulations! You guessed it in " << attempts << " attempts!\n";
        }
    } while (userGuess != secretNumber);
    
    return 0;
}
