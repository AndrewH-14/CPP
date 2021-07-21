#include <iostream>
#include "Die.h"

using namespace std;

// a struct for game variables
struct GameState 
{
    int turn = 1;
    int score = 0;
    int score_this_turn = 0;
    bool turn_over = false;
    bool game_over = false;
    Die die;
};

// declare functions
void display_rules();
void play_game(GameState&);
void take_turn(GameState&);
void roll_die(GameState&);
void hold_turn(GameState&);

int main() 
{
    display_rules();
    GameState game;
    play_game(game);
}

// define functions
void display_rules() {
    cout << "Let's Play PIG!\n"
        << "\n"
        << "* See how many turns it takes you to get to 20.\n"
        << "* Turn ends when you hold or roll a 1.\n"
        << "* If you roll a 1, you lose all points for the turn.\n"
        << "* If you hold, you save all points for the turn.\n\n";
}

void play_game(GameState& game) 
{
    while (!game.game_over) 
    {
        take_turn(game);
    }
    cout << "Game over!\n";
}

void take_turn(GameState& game) 
{
    cout << "TURN " << game.turn << endl;
    game.turn_over = false;
    while (!game.turn_over) 
    {
        char choice;
        cout << "Roll or hold? (r/h): ";
        cin >> choice;

        if (choice == 'r')
        {
            roll_die(game);
        }
        else if (choice == 'h')
        {
            hold_turn(game);
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void roll_die(GameState& game) 
{
    game.die.roll();

    cout << "Die: " << game.die.getValue() << endl;
    if (game.die.getValue() == 1) 
    {
        game.score_this_turn = 0;
        game.turn += 1;
        game.turn_over = true;
        cout << "Turn over. No score.\n\n";
    }
    else 
    {
        game.score_this_turn += game.die.getValue();
    }
}

void hold_turn(GameState& game) 
{
    game.score += game.score_this_turn;
    game.turn_over = true;
    cout << "Score for turn: " << game.score_this_turn << endl;
    cout << "Total score: " << game.score << "\n\n";
    game.score_this_turn = 0;

    if (game.score >= 20) 
    {
        game.game_over = true;
        cout << "You finished in " << game.turn << " turns!\n\n";
    }
    else 
    {
        game.turn += 1;
    }
}