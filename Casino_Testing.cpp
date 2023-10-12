#include "Deck.h"
#include "Poker.h"
#include <iostream>
using namespace std;

enum Ranks {TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,
    NINE,TEN,JACK,QUEEN,KING,ACE};

enum Suits {SPADE,HEART,CLUBS,DIAMOND};

bool test_Card();
bool test_Hand();
bool test_Deck();
bool test_Poker();

int main() {
    srand(time(NULL));

    if(test_Card()) {
        cout << "Passed all Card test cases" << endl;
    }
    if(test_Hand()) {
        cout << "Passed all Hand test cases" << endl;
    }
    if(test_Deck()) {
        cout << "Passed all Deck test cases" << endl;
    }
    if(test_Poker()) {
        cout << "Passed all Poker test cases" << endl;
    }
    return 0;
}

bool test_Card(){
    bool passed = true;
    Card card;

    if (card.get_suit_val() != SPADE || card.get_rank_val() != TWO || card.get_value() != 0 ){
        passed = false;
        cout << "FAILED default constructor test case" << endl;
    }

    Card card2(HEART, THREE);
    if (card2.get_suit_val() != HEART || card2.get_rank_val() != THREE || card2.get_value() != 2 ){
        passed = false;
        cout << "FAILED non-default constructor value test case" << endl;
    }

    if (card2.get_suit() != "HEART" || card2.get_rank() != "3" || card2.get_value() != 2 ){
        passed = false;
        cout << "FAILED non-default constructor string test case" << endl;
    }

    card2.cover_card();
    if (card2.get_uncovered()){
        passed = false;
        cout << "FAILED coverCard test case" << endl;
    }

    card2.uncover_card();
    if (!card2.get_uncovered()){
        passed = false;
        cout << "FAILED uncoverCard test case" << endl;
    }

    Card card3(HEART, FIVE);
    if (card3 <= card2){
        passed = false;
        cout << "FAILED <= Card comparison test case" << endl;
    }

   Card card4(HEART, THREE);
    if (card4 != card2){
        passed = false;
        cout << "FAILED != card comparison test case" << endl;
    }

    if (card2 == card3){
        passed = false;
        cout << "FAILED == card comparison test case" << endl;
    }

    if (card4 >= card3){
        passed = false;
        cout << "FAILED >= card comparison test case" << endl;
    }
    return passed;
}

bool test_Hand(){
    bool passed = true;

    Card c1 (DIAMOND, JACK);
    Card c2 (SPADE, TWO);
    Card c3 (HEART, JACK);
    Card c4 (CLUBS, TEN);
    Card c5 (DIAMOND, TEN);
    Card c6 (CLUBS, TWO);
    Card c7 (SPADE, JACK);

    vector<Card> handVector = {c1, c2, c3, c4, c5, c6, c7};
    Hand h = Hand(handVector);

    if (h.get_hand_size() != 7){
        passed = false;
        cout << "FAILED constructor test case" << endl;
    }

    if (h.get_hand() != handVector){
        passed = false;
        cout << "FAILED get_hand did not retrieve vector test case" << endl;
    }

    h.hide_hand(1);
    if (h.get_hand()[1].get_uncovered()){
        passed = false;
        cout << "FAILED hide_hand at index 1 test case" << endl;
    }

    h.hide_hand();
    for (int i = 0; i < h.get_hand_size(); i++){
        if (h.get_hand()[i].get_uncovered()){
            passed = false;
            cout << "FAILED hide_hand at " <<  i << " during hide_hand test case" << endl;
        }
    }

     h.uncover_hand(1);
    if (!h.get_hand()[1].get_uncovered()){
        passed = false;
        cout << "FAILED uncover at index 1 test case" << endl;
    }

    h.uncover_hand();
    for (int i = 0; i < h.get_hand_size(); i++){
        if (!h.get_hand()[i].get_uncovered()){
            passed = false;
            cout << "FAILED uncover at " <<  i << " during uncover_hand test case" << endl;
        }
    }

    int oldHandSize = h.get_hand_size();
    h.get_card();
    if (h.get_hand_size() == oldHandSize){
        passed = false;
        cout << "FAILED get_card with no index test case" << endl;
    }

    oldHandSize = h.get_hand_size();
    h.get_card(8);
    if (h.get_hand_size() != oldHandSize){
        passed = false;
        cout << "FAILED get_card with index out of bounds test case" << endl;
    }

    oldHandSize = h.get_hand_size();
    h.get_card(2);
    if (h.get_hand_size() == oldHandSize){
        passed = false;
        cout << "FAILED get_card with valid index test case" << endl;
    }

    return passed;

}

bool test_Deck(){
    bool passed = true;
    Deck d;
    if (d.get_deck_size() != 52){
        passed = false;
        cout << "FAILED default constructor case" << endl;
    }

    int oldDeckSize = d.get_deck_size();
    d.give_hand(13);
    if(d.get_deck_size() == oldDeckSize){
        passed =false;
        cout << "FAILED give_hand size 13 test case" << endl;
    }

    oldDeckSize = d.get_deck_size();
    d.give_hand(0);
    if(d.get_deck_size() != oldDeckSize){
        passed =false;
        cout << "FAILED give_hand size 0 test case" << endl;
    }

    oldDeckSize = d.get_deck_size();
    d.give_hand(-10);
    if(d.get_deck_size() != oldDeckSize){
        passed =false;
        cout << "FAILED give_hand size -10 test case" << endl;
    }

    return passed;

}

bool test_Poker(){

    bool passed = true;
    Poker p = Poker("admin");
    Card c1 (DIAMOND, JACK);
    Card c2 (SPADE, JACK);
    Card c3 (CLUBS, QUEEN);
    Card c4 (HEART, QUEEN);
    Card c5 (DIAMOND, TEN);
    Card c6 (CLUBS, TWO);
    Card c7 (SPADE, THREE);

    vector<Card> handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    Hand h = (handVector);


     if (!p.is_pair(h)){
         passed = false;
         cout << "FAILED valid pair test case" << endl;
     }

     if (!p.is_two_pair(h)){
         passed = false;
         cout << "FAILED valid two pair test case" << endl;
     }

     c2 = Card(SPADE,KING);
     c3 = Card(SPADE, FOUR);
     handVector = {c1, c2, c3, c4, c5, c6, c7};
     handVector = mergeSort(handVector);
     reverse(handVector.begin(), handVector.end());
     h = (handVector);

     if(p.is_pair(h)){
         passed = false;
         cout << "FAILED invalid pair test case" << endl;
     }

     if(p.is_two_pair(h)){
         passed = false;
         cout << "FAILED invalid TWO pair test case" << endl;
     }

     if(p.is_royal_flush(h)){
         passed = false;
         cout << "FAILED invalid royal flush test case" << endl;
     }

     c1 = Card(DIAMOND, JACK);
     c2 = Card(DIAMOND, ACE);
     c3 = Card(DIAMOND, QUEEN);
     c4 = Card(DIAMOND, KING);
     c5 = Card(DIAMOND, TEN);
     c6 = Card(CLUBS, TWO);
     c7 = Card(SPADE, THREE);

    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(!p.is_royal_flush(h)){
        passed = false;
        cout << "FAILED valid royal flush test case" << endl;
    }

    c1 = Card(DIAMOND, JACK);
    c2 = Card(DIAMOND, TEN);
    c3 = Card(DIAMOND, NINE);
    c4 = Card(DIAMOND, EIGHT);
    c5 = Card(DIAMOND, SEVEN);
    c6 = Card(CLUBS, TWO);
    c7 = Card(SPADE, THREE);

    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(!p.is_straight_flush(h)){
        passed = false;
        cout << "FAILED valid straight flush test case" << endl;
    }

    if(!p.is_flush(h)){
        passed = false;
        cout << "FAILED valid flush test case" << endl;
    }

    c2 = Card(HEART, FOUR);
    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(p.is_straight_flush(h)){
        passed = false;
        cout << "FAILED invalid straight flush test case" << endl;
    }

    if(p.is_flush(h)){
        passed = false;
        cout << "FAILED invalid flush test case" << endl;
    }

    c1 = Card(DIAMOND, JACK);
    c2 = Card(SPADE, TEN);
    c3 = Card(HEART, NINE);
    c4 = Card(CLUBS, EIGHT);
    c5 = Card(DIAMOND, SEVEN);
    c6 = Card(CLUBS, TWO);
    c7 = Card(SPADE, THREE);

    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(!p.is_straight(h)){
        passed = false;
        cout << "FAILED valid straight test case" << endl;
    }

    c2 = Card(HEART, FOUR);
    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(p.is_straight(h)){
        passed = false;
        cout << "FAILED invalid straight test case" << endl;
    }

    if(p.is_four_kind(h)){
        passed = false;
        cout << "FAILED invalid four of a kind test case" << endl;
    }

    if(p.is_three_kind(h)){
        passed = false;
        cout << "FAILED invalid three of a kind test case" << endl;
    }

    c1 = Card(DIAMOND, NINE);
    c2 = Card(SPADE, NINE);
    c3 = Card(HEART, NINE);
    c4 = Card(CLUBS, NINE);
    c5 = Card(DIAMOND, SEVEN);
    c6 = Card(CLUBS, TWO);
    c7 = Card(SPADE, THREE);

    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

     if(!p.is_four_kind(h)){
        passed = false;
        cout << "FAILED valid four of a kind test case" << endl;
    }

    if(!p.is_three_kind(h)){
        passed = false;
        cout << "FAILED valid three of a kind test case" << endl;
    }

    c1 = Card(DIAMOND, NINE);
    c2 = Card(SPADE, NINE);
    c3 = Card(HEART, NINE);
    c4 = Card(CLUBS, THREE);
    c5 = Card(DIAMOND, SEVEN);
    c6 = Card(CLUBS, TWO);
    c7 = Card(SPADE, THREE);

    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(!p.is_full_house(h)){
        passed = false;
        cout << "FAILED valid full house test case" << endl;
    }

    c2 = Card(SPADE, EIGHT);
    handVector = {c1, c2, c3, c4, c5, c6, c7};
    handVector = mergeSort(handVector);
    reverse(handVector.begin(), handVector.end());
    h = (handVector);

    if(p.is_full_house(h)){
        passed = false;
        cout << "FAILED invalid full house test case" << endl;
    }
    return passed;
}
