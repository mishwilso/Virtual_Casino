/*
 * TODO: Make Overloaded Print operator and
 *  better stuff for organizing the cards, enums are a bit...much
 */

#ifndef M2OEP_MWILSO33_CARD_H
#define M2OEP_MWILSO33_CARD_H

#include <string>
#include <iostream>
using namespace std;

class Card {
private:
    int suit;
    int rank;
    bool uncovered;

    int value;

    enum Ranks {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,
    NINE,TEN,JACK,QUEEN,KING,ACE};

    enum Suits {SPADE,HEART,CLUBS,DIAMOND};

public:

    /*
    * Default Constructor
    * Requires: nothing
    * Modifies: nothing
    * Effects: nothing
    */
    Card();

    /*
    * Constructor
    * Requires: int suit, int rank
    * Modifies: suit, rank, uncovered, value
    * Effects: Constructs the card
    */
    Card(int suit, int rank);

    /*
    * Gets the suit of the card
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns suit
    */
    string get_suit() const;

    /*
    * Gets whether the card is uncovered
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns uncovered
    */
    bool get_uncovered() const;

    /*
    * Gets the rank of the card
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns rank
    */
    string get_rank() const;

    /*
    * Gets the rankVal of the card
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns rankVal
    */
    int get_rank_val() const;

    /*
    * Gets the suitVal of the card
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns suitVal
    */
    int get_suit_val() const;

    /*
    * Gets the value of the card
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns value
    */
    int get_value() const;

    /*
    * Sets the card to uncovered
    * Requires: nothing
    * Modifies: uncovered
    * Effects: Sets uncovered to false
    */
    void uncover_card();

    /*
    * Sets the card to covered
    * Requires: nothing
    * Modifies: uncovered
    * Effects: Sets uncovered to true
    */
    void cover_card();

    //Overloaded Operators
    friend std::ostream& operator << (std::ostream& outs, const Card& cObj);

    friend bool operator == (const Card& lhs, const Card& rhs);

    friend bool operator > (const Card& lhs, const Card& rhs);

    friend bool operator >= (const Card& lhs, const Card& rhs);

    friend bool operator < (const Card& lhs, const Card& rhs);

    friend bool operator <= (const Card& lhs, const Card& rhs);

    friend bool operator != (const Card& lhs, const Card& rhs);
};


#endif //M2OEP_MWILSO33_CARD_H
