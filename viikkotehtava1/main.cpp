#include <iostream>
#include <cstdlib>
#include <ctime>

int game(int max_num)
{
    // Get a different random number each time the program runs
    srand(time(0));

    // Generate a random number
    int random_num = 1 + (rand() % (max_num));
    int num_guesses = 0;
    int guess = 0;

    // Ask user input
    while(guess != random_num)
    {
        ++num_guesses;

        std::cout << "enter your guess (" << 1 << "-" << max_num << ")> ";
        std::cin.clear();
        std::cin >> guess;

        if(guess < random_num)
            std::cout << "your guess was too low!" << std::endl;
        else if(guess > random_num)
            std::cout << "your guess was too high!" << std::endl;
        else
            std::cout << "you guessed correct!" << std::endl;
    }

    return num_guesses;
}

int main()
{
    int result = game(5);
    std::cout << "you made " << result << " number of guesses." << std::endl;

    return 0;
}
