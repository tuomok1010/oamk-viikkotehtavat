#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game(int max_num);
    ~Game();

    void play();

private:
    void print_game_result();

    int max_number;
    int player_guess;
    int random_number;
    int num_of_guesses;
};
#endif // GAME_H
