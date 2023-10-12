#include <string>
#include "Validate.h"
#include "Cashier.h"
#include <cstdio>

#ifndef M2OEP_MWILSO33_GAME_H
#define M2OEP_MWILSO33_GAME_H

using namespace std;

class Game {

protected:
    string username;
    int users_bet;
    Validate valid;
    //Cashier cash;

    enum Ranks {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,
            NINE,TEN,JACK,QUEEN,KING,ACE};

    enum Suits {SPADE,HEART,CLUBS,DIAMOND};

    virtual void user_bet(string username);

    virtual void additional_bet(string username);

    void update_games_played(std::string user);

public:

    Game();

    Game(string username);

    int get_games_played(std::string username);
};


#endif //M2OEP_MWILSO33_GAME_H
