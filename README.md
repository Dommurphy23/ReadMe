# CPP

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int guess;
    int tries = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?" << std::endl;

    // Keep looping until the user guesses the correct number
    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        tries++;

        // Check if the guess is too high, too low, or correct
        if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << tries << " tries." << std::endl;
            break;
        }
    }

    return 0;
}