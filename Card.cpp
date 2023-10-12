/**
 * This is the Card Class. This class contains the Card constructor.
 * With this class you can create a card that contains a certain value.
 */
#include "Card.h"

Card::Card(){
    suit = SPADE;
    rank = TWO;
    value = rank + suit;
    uncovered = true;
}

Card::Card(int suit, int rank){
    //Construct card
    this->suit = suit;
    this->rank = rank;
    this->value = rank + suit;
    this->uncovered = true;
}

string Card::get_suit() const {
    string stringSuit;
    //Case switch for different suit values
    if (uncovered){
        switch(suit){
            case SPADE:
                stringSuit = "SPADE";
                break;
            case HEART:
                stringSuit = "HEART";
                break;
            case CLUBS:
                stringSuit = "CLUBS";
                break;
            case DIAMOND:
                stringSuit = "DIAMOND";
                break;
        }
    } else {
        stringSuit = " ";
    }
    return stringSuit;
}

bool Card::get_uncovered() const{
    return uncovered;
}

string Card::get_rank() const{
    string stringRank;
    if (uncovered) {
        switch (rank) {
            case TWO:
                stringRank = "2";
                break;
            case THREE:
                stringRank = "3";
                break;
            case FOUR:
                stringRank = "4";
                break;
            case FIVE:
                stringRank = "5";
                break;
            case SIX:
                stringRank = "6";
                break;
            case SEVEN:
                stringRank = "7";
                break;
            case EIGHT:
                stringRank = "8";
                break;
            case NINE:
                stringRank = "9";
                break;
            case TEN:
                stringRank = "10";
                break;
            case JACK:
                stringRank = "J";
                break;
            case QUEEN:
                stringRank = "Q";
                break;
            case KING:
                stringRank = "K";
                break;
            case ACE:
                stringRank = "A";
                break;
        }
    } else {
        stringRank = " ";
    }
    return stringRank;
}

int Card::get_rank_val() const{
    return rank;
}

int Card::get_suit_val() const {
    return suit;
}

int Card::get_value() const {
    return value;
}

void Card::uncover_card(){
    uncovered = true;
}

void Card::cover_card(){
    uncovered = false;
}

//Overloaded Operators :D
std::ostream& operator << (std::ostream& outs, const Card& cObj) {
    if (cObj.get_uncovered()) {
        outs << ".------.\n"
                "|"
                << cObj.get_rank() <<
                ".--. |\n"
                "| :"
                << cObj.get_suit()[0] <<
                " : |\n"
                "| '--'"
                << cObj.get_rank() <<
                "|\n"
                "`------'";
    } else {
        outs << ".------.\n"
                "| .--. |\n"
                "| :  : |\n"
                "| '--' |\n"
                "`------'";
    }
    return outs;
}

bool operator == (const Card& lhs, const Card& rhs) {
    return ((lhs.get_suit_val() == rhs.get_suit_val()) && (lhs.get_rank_val() == rhs.get_rank_val()));
}

bool operator > (const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank_val() == rhs.get_rank_val())){
        return (lhs.get_suit_val() > rhs.get_suit_val());
    } else {
        return ((lhs.get_rank_val() > rhs.get_rank_val()));
    }
}

bool operator >= (const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank_val() == rhs.get_rank_val())){
        return (lhs.get_suit_val() >= rhs.get_suit_val());
    } else {
        return ((lhs.get_rank_val() > rhs.get_rank_val()));
    }
}

bool operator < (const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank_val() == rhs.get_rank_val())){
        return (lhs.get_suit_val() < rhs.get_suit_val());
    } else {
        return ((lhs.get_rank_val() < rhs.get_rank_val()));
    }
}

bool operator <= (const Card& lhs, const Card& rhs) {
    if ((lhs.get_rank_val() == rhs.get_rank_val())){
        return (lhs.get_suit_val() <= rhs.get_suit_val());
    } else {
        return ((lhs.get_rank_val() < rhs.get_rank_val()));
    }
}

bool operator != (const Card& lhs, const Card& rhs) {
    return ((lhs.get_suit_val() != rhs.get_suit_val()) && (lhs.get_rank_val() != rhs.get_rank_val()));
}

