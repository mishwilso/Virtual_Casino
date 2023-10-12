/**
 * This is the Hand Class. This class contains the Hand constructor
 * and Hand modifiers including covering and uncovering the hand.
 * TODO:
 *  - Make a getCard function.
 */
#include "Hand.h"

Hand::Hand(){
    ;
}

Hand::Hand(vector<Card> handVector){
    this->hand = handVector;
    hand_size = hand.size();
}

int Hand::get_hand_size() const{
    return hand_size;
}

vector<Card> Hand::get_hand(){
    return hand;
}

//Hide Hand
void Hand::hide_hand(){
    for (int i = 0; i < hand.size(); ++i){
        hand[i].cover_card();
    }
}

void Hand::hide_hand(int index){
    hand[index].cover_card();
}

//Uncover Hand
void Hand::uncover_hand(){
    for (int i = 0; i < hand.size(); ++i){
        hand[i].uncover_card();
    }
}

void Hand::uncover_hand(int index){
    hand[index].uncover_card();
}

Card Hand::get_card(){
    int min = 0;
    int max = get_hand_size() - 1;
    int index = min + ( std::rand() % ( max - min + 1 ));
    Card c = hand[index];
    hand.erase(hand.begin() + index);
    hand_size = hand.size();
    return c;
}

Card Hand::get_card(int index){
    if (index >= get_hand_size()){
        return Card(0, 0);
    }
    Card c = hand[index];
    hand.erase(hand.begin() + index);
    hand_size = hand.size();
    return c;
}

//Print hand
std::ostream& operator << (std::ostream& outs, const Hand& hObj) {
    for (int i; i < hObj.get_hand_size(); ++i){
        outs << hObj.hand[i] << "\n";
    }
    return outs;
}
