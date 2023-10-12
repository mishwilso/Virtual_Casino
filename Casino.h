#include <ctype.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Register.h"
#include "Validate.h"
#include "Cashier.h"
#include "Game.h"
#include "Poker.h"

#ifndef M1OEP_MWILSO33_CASINO_H
#define M1OEP_MWILSO33_CASINO_H

using namespace std;

class Casino {
private:
    Validate valid;
    Register r;

    enum access_levels {
        PLAYER,
        CASHIER,
        ADMIN
    };
    Cashier cash;
    Poker p;

public:

    /*
     * Prints Welcome menu and allows user to select different options.
     * (Login, Register, Exit)
     * Requires: nothing
     * Modifies: nothing
     * Effects: Prints Welcome menu
     */
    void welcome_menu();

    /*
     * Prints User menu and allows user to select different options.
     * Options vary depending on user access level
     * Requires: nothing
     * Modifies: nothing
     * Effects: Prints User menu
     */
    void user_menu(string username, int access_level);

    /*
     * Prints Game menu and allows user to select different opens.
     * Will display various game options.
     * Requires: nothing
     * Modifies: nothing
     * Effects: Prints Game menu
     */
    void game_menu(string username, int access_level);

};


#endif //M1OEP_MWILSO33_CASINO_H
