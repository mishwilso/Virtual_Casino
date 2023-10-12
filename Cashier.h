#ifndef M1OEP_MWILSO33_CASHIER_H
#define M1OEP_MWILSO33_CASHIER_H

#include <cctype>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdio>

#include "Validate.h"
#include "Poker.h"

using namespace std;

class Cashier {
private:
    Validate valid;

public:

    /*
     * Prints Players game stats including current balance
     * Number of games played and number of times they played
     * a specific game.
     * Requires: string username
     * Modifies: nothing
     * Effects: Print Player Statistics
     */
    void user_stats(string username);

    /*
     * Allows player to fill out cash request form
     * Requires: string username
     * Modifies: nothing
     * Effects: Takes in users requests, appends it to 'request.csv' file
     */
    void cash_request(string username);

    /*
     * Allows Cashier accept and reject cash request forms
     * Requires: nothing
     * Modifies: nothing
     * Effects: Takes in cashiers decision, applies changes
     * to 'request.csv' (Approved or Denied) and 'cashier.csv' (Updates Balance)
     */
    void request_approval();

    /*
     * Checks if user has enough for bet
     * Requires: balance, username
     * Effects: Returns true if user has enough balance to make their bet
     */
    bool check_balance(int request, std::string username);

    int get_balance(std::string username);

    void updateBalance(std::string user, int amount_requested);

};


#endif //M1OEP_MWILSO33_CASHIER_H
