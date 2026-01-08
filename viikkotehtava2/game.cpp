#include "game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int max_num) :
    max_number(max_num),
    player_guess(0),
    random_number(0),
    num_of_guesses(0)
{
    std::cout << "[Game]: Game::Game(" << max_num << ") called" << std::endl;
}

Game::~Game()
{
    std::cout << "[Game]: Game::~Game() called" << std::endl;
}

void Game::play()
{
    // Get a different random number each time the program runs
    srand(time(0));

    // Generate a random number
    random_number = 1 + (rand() % (max_number));
    num_of_guesses = 0;
    player_guess = 0;

    // Ask user input
    while(player_guess != random_number)
    {
        ++num_of_guesses;

        std::cout << "enter your guess (" << 1 << "-" << max_number << ")> ";
        std::cin.clear();
        std::cin >> player_guess;

        if(player_guess < random_number)
            std::cout << "your guess was too low!" << std::endl;
        else if(player_guess > random_number)
            std::cout << "your guess was too high!" << std::endl;
    }

    print_game_result();
}

void Game::print_game_result()
{
    std::cout
        << "your answer was correct (" << player_guess << ")\n"
        << "you made " << num_of_guesses << " guesses" << std::endl;
}
