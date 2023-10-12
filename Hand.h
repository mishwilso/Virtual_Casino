#include <vector>
#include <iostream>
#include <string>
#include "Card.h"

#ifndef M2OEP_MWILSO33_HAND_H
#define M2OEP_MWILSO33_HAND_H

class Hand {
private:
    vector<Card> hand;
    int hand_size;

    enum Ranks {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,
        NINE,TEN,JACK,QUEEN,KING,ACE};

    enum Suits {SPADE,HEART,CLUBS,DIAMOND};

public:

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: nothing
     * Effects: nothing.
     */
    Hand();

    /*
     * Hand Constructor
     * Requires: vector<Card> HandVector
     * Modifies: Hand, Handsize
     * Effects: Constructs Hand using the HandVector given
     */
    Hand(vector<Card> hand_vector);

    /*
     * Gets handSize
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns handSiz.
     */
    int get_hand_size() const;

    /*
     * Gets hand vector
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns hand
     */
    vector<Card> get_hand();

    /*
     * Sets all cards in hand to hidden.
     * Essentially flipping the cards over.
     * Requires: nothing
     * Modifies: vector<Card> hand
     * Effects: Sets all cards in hand to hidden
     */
    void hide_hand();

    /*
     * Sets card at index in hand to hidden.
     * Essentially flipping the card over.
     * Requires: int index
     * Modifies: vector<Card> hand[index]
     * Effects: Sets card at index to hidden
     */
    void hide_hand(int index);

    /*
     * Sets all cards in hand to unhidden.
     * Essentially flipping the cards over.
     * Requires: nothing
     * Modifies: vector<Card> hand
     * Effects: Sets all cards in hand to unhidden.
     */
    void uncover_hand();

    /*
     * Sets card at index in hand to hidden.
     * Essentially flipping the card over
     * Requires: nothing
     * Modifies: vector<Card> hand[index]
     * Effects: Sets card at index to unhidden.
     */
    void uncover_hand(int index);

    /*
     * Gets a random card from the hand and returns it.
     * Requires: nothing
     * Modifies: vector<Card> hand
     * Effects: returns Card from hand
     */
    Card get_card();

    /*
     * Gets a card at index from the hand and returns it.
     * Requires: nothing
     * Modifies: vector<Card> hand
     * Effects: returns Card from hand at index.
     */
    Card get_card(int index);

    //Overridden Operator
    friend std::ostream& operator << (std::ostream& outs, const Hand& hObj);

};


#endif //M2OEP_MWILSO33_HAND_H
