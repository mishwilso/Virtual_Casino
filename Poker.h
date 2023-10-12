#ifndef M2OEP_MWILSO33_POKER_H
#define M2OEP_MWILSO33_POKER_H

#include "Game.h"
#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "mergeSort.h"

#include <algorithm>
#include <random>
#include <iostream>

class Poker : public Game {
private:
    Deck d;
    Hand user_hand;
    Hand cashier_hand;
    Hand community_hand;

public:
    /*
    * Default Constructor
    * Requires: nothing
    * Modifies: nothing
    * Effects: Allows you to declare an empty poker
    */
    Poker();

    /*
    * Constructor
    * Requires: string username
    * Modifies: user_hand, cashierHand, communityHand, Deck d
    * Effects: Constructs the poker game and board.
    */
    explicit Poker(string username);

    /*
    * Displays Poker board
    * Requires: nothing
    * Modifies: nothing
    * Effects: Prints out Poker board.
    */
    void display_board();

    /*
    * Prints out hand in a horizontal format
    * Requires: Hand h, int size
    * Modifies: nothing
    * Effects: Prints hand.
    */
    void print_hand(Hand h, int size);

    /*
    * Prints out poker menu and takes in user input
    * for starting the game, reading instructions or quitting
    * Requires: nothing
    * Modifies: nothing
    * Effects: Prints poker menu.
    */
    void poker_menu();

    /*
    * Starts the poker game and takes in user input
    * for the game functions
    * Requires: nothing
    * Modifies: user_hand, cashierHand, communityHand, Deck d
    * Effects: Starts the poker game.
    */
    void play_poker();

    /*
    * Resets Poker Game and board
    * Requires: string username
    * Modifies: user_hand, cashierHand, communityHand, Deck d
    * Effects: Constructs the poker game and board.
    */
    void reset_board();

    /*
     * Updates poker game csv file
     * Requires: string username
     * Modifies: poker.csv
     * Effects: Updates the times played by one for user.
     */
    void update_game(std::string user);

    /*
     * Gets total poker games played
     * Requires: string username
     * Modifies: nothing
     * Effects: Returns users total poker games played
     */
    int get_games_played(std::string username);

    /*
     * Checks if user or cashier won
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns true if winner is user, false if winner is cashier
     */
    bool check_win();

    /*
     * Checks if hand has a Pair
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if pair exists, and false otherwise
     */
    bool is_pair(Hand h);

    /*
     * Checks if hand has a Royal Flush
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Royal Flush exists, and false otherwise
     */
    bool is_royal_flush(Hand h);

    /*
     * Checks if hand has a Straight Flush
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Straight Flush exists, and false otherwise
     */
    bool is_straight_flush(Hand h);

    /*
     * Checks if hand has a Four Kind
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Four Kind exists, and false otherwise
     */
    bool is_four_kind(Hand h);

    /*
     * Checks if hand has a Full House
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Full House exists, and false otherwise
     */
    bool is_full_house(Hand h);

    /*
     * Checks if hand has a Two Pair
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if two pair exists, and false otherwise
     */
    bool is_two_pair(Hand h);

    /*
     * Checks if hand has a Flush
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Flush exists, and false otherwise
     */
    bool is_flush(Hand h);

    /*
     * Checks if hand has a Straight
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Straight exists, and false otherwise
     */
    bool is_straight(Hand h);

    /*
     * Checks if hand has a Three Kind
     * Requires: Hand h
     * Modifies: nothing
     * Effects: Returns true if Three Kind exists, and false otherwise
     */
    bool is_three_kind(Hand h);

};


#endif //M2OEP_MWILSO33_POKER_H
