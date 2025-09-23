#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0)); // seeding with current time means starting point
    // Generating a random number from 1 to 100
    int random_number = (rand() % 100) + 1;
    int no_of_guesses = 0;
    int guessed;

    do
    {
        cout << "Guess the number: "; // Input number for guessing
        cin >> guessed;

        if (guessed > random_number)
        {
            cout << "Lower number please!" << endl;
        }
        else if (guessed < random_number)
        {
            cout << "Higher number please!" << endl;
        }
        else
        {
            cout << "Congrats!" << endl;
        }
        no_of_guesses++;
    } while (guessed != random_number);

    cout << "You guessed the number in " << no_of_guesses << " guesses." << endl;

    return 0;
}