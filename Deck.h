#ifndef M2OEP_MWILSO33_DECK_H
#define M2OEP_MWILSO33_DECK_H

#include <vector>
#include <iostream>

#include <string>
#include <random>
#include <algorithm>
#include "Card.h"
#include "Hand.h"

class Deck {
private:
    enum Ranks {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,
    NINE,TEN,JACK,QUEEN,KING,ACE};

    enum Suits {SPADE,HEART,CLUBS,DIAMOND};

    vector<Suits> suit_values {SPADE, HEART, CLUBS, DIAMOND};
    vector<Ranks> rank_values {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

    vector<Card> deck;
    int deck_size;

public:

    /*
    * Default Constructor
    * Requires: nothing
    * Modifies: deck, deckSize
    * Effects: constructs a shuffled deck.
    */
    Deck();

    /*
    * Shuffles Deck
    * Requires: nothing
    * Modifies: nothing
    * Effects: Shuffles the cards that are currently in the deck
    */
    void shuffle_deck();

    /*
    * Takes out a hand from the deck based on the given size
    * Requires: int handSize
    * Modifies: Deck d
    * Effects: returns vector<Card> hand
    */
    vector<Card> give_hand(int handSize);

    /*
    * Takes a single card from the deck.
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns card from deck
    */
    Card draw_card();

    /*
    * Returns the size of the deck
    * Requires: nothing
    * Modifies: nothing
    * Effects: returns deckSize
    */
    int get_deck_size();
};

#endif //M2OEP_MWILSO33_DECK_H
