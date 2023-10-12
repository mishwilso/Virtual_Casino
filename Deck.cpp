/**
 * This is the Deck Class. This class contains the Deck constructor
 * and Deck modifiers including shuffling the deck, drawing a card
 * and taking out a hand.
 */

#include "Deck.h"

Deck::Deck() {
    int count = 0;
    for (int i = 0; count < 52; i++) {
        int suit = suit_values[rand() % suit_values.size()];
        int rank = rank_values[rand() % rank_values.size()];
        Card c = Card(suit, rank);

        if (!(std::find(deck.begin(), deck.end(), c) != deck.end())) {
            deck.push_back(c);
            count++;
        }
        deck_size = deck.size();
    }
}

void Deck::shuffle_deck() {
    srand(time(NULL));
    std::shuffle(std::begin(deck), std::end(deck), std::default_random_engine());
}

vector<Card> Deck::give_hand(int handSize) {

    vector<int> chosen;
    vector<Card> hand;
    if (handSize <= get_deck_size() && handSize > 0){
        for (int i = 0; chosen.size() < handSize; ++i){
            int cardNum = rand() % deck.size();
            if (!(std::find(chosen.begin(), chosen.end(), cardNum) != chosen.end())) {
                chosen.push_back(cardNum);
            }
        }

        sort(chosen.begin(), chosen.end(), greater<int>());

        for (int i = 0; i < chosen.size(); ++i){
            hand.push_back(deck[chosen[i]]);
            deck.erase(deck.begin() + chosen[i]);
        }
        deck_size = deck.size();
    }
    return hand;
}

Card Deck::draw_card(){
    Card c;

    if (deck.size() > 0){
        int cardNum = rand() % deck.size();
        c = deck[cardNum];
        deck.erase(deck.begin() + cardNum);
    }
    deck_size = deck.size();
    return c;
}

int Deck::get_deck_size(){
    return deck_size;
}