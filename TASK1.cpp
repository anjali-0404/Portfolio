#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

int main() {
    srand((unsigned int) time(0));
    int number = rand() % 100 + 1; /*0-99 %100+1->1-100*/
    int guess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Please guess the number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < number) {
                cout<<"Guess is too low"<<endl;
        } else if (guess > number) {
            cout << "Guess is too high" << endl;
        } else {
            cout << "Awesome! You've guessed the correct number in " << attempts << " attempts." << endl;
        }
    } while (guess !=number);

    return 0;
}