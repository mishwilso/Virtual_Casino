/**
 * This is the Poker Class, which is a Game. This class contains the poker menu
 * and all the functions need to play poker. It has an extensive amount
 * of card checking logic.
 */

#include "Poker.h"

//Default constructor
Poker::Poker(){
    ;
}

//Constructors
Poker::Poker(string username){
    Game::username = username;
    this->d.shuffle_deck();
    this->user_hand = d.give_hand(2);
    this->cashier_hand = d.give_hand(2);
    this->community_hand = d.give_hand(5);

    cashier_hand.hide_hand();
    community_hand.hide_hand();

}

void Poker::display_board(){
    cout << "=================== Cashier's (Lisa) Hand =====================" << endl;
    print_hand(cashier_hand, cashier_hand.get_hand_size());
    cout << "=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====\n" << endl;
    print_hand(community_hand, community_hand.get_hand_size());
    cout << "\n=====+=====+=====+=====+=====+=====+=====+=====+=====+=====+=====" << endl;
    cout << "\n";
    cout << "=================== Your Hand =====================" << endl;
    print_hand(user_hand, user_hand.get_hand_size());
}

void Poker::print_hand(Hand h, int size){

    for (int i = 0; i < size; ++i){
        cout << " .------. ";
    }
    cout << "\n";
    for (int i = 0; i < size; ++i){
        cout << " |" << h.get_hand()[i].get_rank() << ".--. | ";
    }
    cout << "\n";
    for (int i = 0; i < size; ++i){
        cout << " | :" << h.get_hand()[i].get_suit()[0] << " : | ";
    }
    cout << "\n";

    for (int i = 0; i < size; ++i){
        cout << " | '--'" << h.get_hand()[i].get_rank() << "| ";
    }
    cout << "\n";

    for (int i = 0; i < size; ++i){
        cout << " `------' ";
    }
    cout << "\n";
}

void Poker::poker_menu(){
    int selection;
    cout << "=================== Poker Simulator (Mish Edition) =====================" << endl;
    cout << "Please choose one of the options to continue\n"
            "[1] Play Game\n"
            "[2] Instructions\n"
            "[3] Quit Game" << endl;
    selection = valid.get_int_from_user("Selection");
    cout << "\n";

    while (selection < 1 || selection > 3) {
        cout << "Invalid Selection, please select from the following options: " << endl;
        cout << "[1] Play Game\n"
                "[2] Instructions\n"
                "[3] Quit Game" << endl;
        selection = valid.get_int_from_user("Selection");
        cout << "\n";
    }

        if (selection == 1) {
            cout << "=================== Game Start =====================" << endl;
            update_games_played(username);
            update_game(username);
            play_poker();

        } else if (selection == 2) {
            cout << "=================== Instructions =====================" << endl;
            cout << "The game starts out with you making a initial bet. You are then dealt two cards and the game starts.\n"
                    "You then get to choose from the following options: \n"
                    "[Raise] (increase the amount of the current open bet or raise, which any subsequent players must at \n"
                    "least match to stay in).\n\n"
                    "[Fold] (pushing their cards into the middle and surrendering any chance to win the hand).\n\n"
                    "[Check] (pass the action to the next player without betting anything. Checking can only be \n"
                    "used when there's no open bet or raise in front of you).The game of poker has three options.\n\n";
            poker_menu();
        } else {

            cout << "Goodbye!" << endl;
            cout << "\n";
            //End program!
        }
}

void Poker::play_poker(){
    Cashier cash;
    bool gameOver = false;
    int rounds = 1;
    int selection;
    user_bet(username);

    while(!gameOver){
        display_board();
        cout << "\n";
        cout << "Current Bet: " << users_bet << endl;
        cout << "Select one of the following options: " << endl;
        cout << "[1] Fold\n"
                "[2] Call\n"
                "[3] Raise" << endl;
        selection = valid.get_int_from_user("Selection");
        cout << "\n";

        while (selection < 1 || selection > 3) {
            cout << "Invalid Selection, please select from the following options: " << endl;
            cout << "[1] Fold\n"
                    "[2] Call\n"
                    "[3] Raise" << endl;
            selection = valid.get_int_from_user("Selection");
            cout << "\n";
        }

        srand(time(NULL));
        //Check if Lisa Folded
        if (rand() % 10 != 4) {
            if (selection == 1) {
                cout << "=================== Folded =====================" << endl;
                //User Folded
                cout << "You lost " << (users_bet/2) << " Mish Coins" << endl;
                cash.updateBalance(username, (-1 * (users_bet / 2)));
                cout << "\n";
                gameOver = true;

                //Steps - User loses half the money they initially Bet


            } else if (selection == 2) {
                cout << "==================== Call ======================" << endl;

                //Uncover Community Hands
                if (rounds == 1) {
                    community_hand.uncover_hand(0);
                    community_hand.uncover_hand(1);
                    community_hand.uncover_hand(2);
                    rounds += 1;

                } else if (rounds == 2) {
                    community_hand.uncover_hand(3);
                    rounds += 1;
                } else if (rounds == 3) {
                    community_hand.uncover_hand(4);
                    rounds += 1;
                } else {
                    gameOver = true;
                    cashier_hand.uncover_hand();
                    // Game over Sequence
                    display_board();
                    if (check_win()){
                        cout << "You won " << users_bet << " Mish Coins" << endl;
                        cout << "\n";
                        cash.updateBalance(username, users_bet);
                    } else {
                        cout << "You lost " << users_bet << " Mish Coins" << endl;
                        cout << "\n";
                        cash.updateBalance(username, (-1 * users_bet));
                        cash.updateBalance("ldion", users_bet);
                    }
                }

            } else {
                cout << "==================== Raise ======================" << endl;
                additional_bet(username);
                cout << "\n";
            }
        } else {
            cout << "============= Lisa Folded ================" << endl;
            cout << " You won " << users_bet << " Mish Coins" << endl;
            cout << "\n";
            cash.updateBalance(username, users_bet);
            // Make an add balance function

            gameOver = true;
        }
    }

    reset_board();
    poker_menu();
    //Check results
}

bool Poker::check_win(){

    //Get High Card
    vector<Card> usersVector = user_hand.get_hand();
    vector<Card> cashierVector = cashier_hand.get_hand();

    usersVector = mergeSort(usersVector);
    cashierVector = mergeSort(cashierVector);

    reverse(usersVector.begin(), usersVector.end());
    reverse(cashierVector.begin(), cashierVector.end());

    string usersHighCard = usersVector[0].get_rank();
    string cashiersHighCard = cashierVector[0].get_rank();

    int usersHighVal = usersVector[0].get_rank_val();
    int cashiersHighVal = cashierVector[0].get_rank_val();


    for (int i = 0; i < community_hand.get_hand_size(); ++i){
        usersVector.push_back(community_hand.get_hand()[i]);
    }
    for (int i = 0; i < community_hand.get_hand_size(); ++i){
        cashierVector.push_back(community_hand.get_hand()[i]);
    }

    //Sort user hand and cashier hand
    usersVector = mergeSort(usersVector);
    cashierVector = mergeSort(cashierVector);

    //Reverse order of vector, so highest value is first
    reverse(usersVector.begin(), usersVector.end());
    reverse(cashierVector.begin(), cashierVector.end());

    //reassign Hand to user and cashier
    user_hand = Hand(usersVector);
    cashier_hand = Hand(cashierVector);

    //Royal Flush
    if(is_royal_flush(user_hand)){
        cout << "You won with a Royal Flush!" << endl;
        return true;
    } else if ( is_royal_flush(cashier_hand)){
        cout << "Lisa won with a Royal Flush!" << endl;
    }

    //Straight Flush
    if(is_straight_flush(user_hand)){
        cout << "You won with a Straight Flush!" << endl;
        return true;
    } else if ( is_straight_flush(cashier_hand)){
        cout << "Lisa won with a Straight Flush!" << endl;
        return false;
    }

    //Royal Flush
    if(is_royal_flush(user_hand)){
        cout << "You won with a Royal Flush!" << endl;
        return true;
    } else if ( is_royal_flush(cashier_hand)){
        cout << "Lisa won with a Royal Flush!" << endl;
        return false;
    }

    //Four Kind
    if(is_four_kind(user_hand)){
        cout << "You won with a Four Kind!" << endl;
        return true;
    } else if ( is_four_kind(cashier_hand)){
        cout << "Lisa won with a Four Kind!" << endl;
        return false;
    }

    //Full House
    if(is_full_house(user_hand)){
        cout << "You won with a Full House!" << endl;
        return true;
    } else if ( is_full_house(cashier_hand)){
        cout << "Lisa won with a Full House!" << endl;
        return false;
    }

    //Flush
    if(is_flush(user_hand)){
        cout << "You won with a Flush!" << endl;
        return true;
    } else if ( is_flush(cashier_hand)){
        cout << "Lisa won with a Flush!" << endl;
        return false;
    }

    //Straight
    if(is_straight(user_hand)){
        cout << "You won with a Straight!" << endl;
        return true;
    } else if ( is_straight(cashier_hand)){
        cout << "Lisa won with a Straight!" << endl;
        return false;
    }

    //Three of a Kind
    if(is_three_kind(user_hand)){
        cout << "You won with a Three of a Kind!" << endl;
        return true;
    } else if ( is_three_kind(cashier_hand)){
        cout << "Lisa won with a Three of a Kind!" << endl;
        return false;
    }

    //Two Pair
    if(is_two_pair(user_hand)){
        cout << "You won with a Two Pair!" << endl;
        return true;
    } else if ( is_two_pair(cashier_hand)){
        cout << "Lisa won with a Two Pair!" << endl;
        return false;
    }

    //Pair
    if(is_pair(user_hand)){
        cout << "You won with a Pair!" << endl;
        return true;
    } else if ( is_pair(cashier_hand)){
        cout << "Lisa won with a Pair!" << endl;
        return false;
    }

    //High Card
    if(usersHighVal >= cashiersHighVal){
        cout << "You won with a High Card " << usersHighCard << " !" << endl;
        return true;
    } else {
        cout << "Lisa won with a High Card " << cashiersHighCard << " !" << endl;
        return false;
    }
}

bool Poker::is_pair(Hand h){
    vector<Card> handVector = h.get_hand();

    int numSets = 6;
    int sequence = 2;

    for(int k = 0; k < numSets; k++) {
        bool pair = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank() != handVector[j + 1 + k].get_rank()) {
                pair = false;
            }
        }
        if (pair){
            return true;
        }
    }
    return false;
}

bool Poker::is_royal_flush(Hand h){
    vector<Card> handVector = h.get_hand();
    //Number of sequences of 5 in a sorted hand
    int numSets = 3;
    int sequence = 5;


    //check if
    for(int k = 0; k < numSets; k++) {
        bool suitFlag = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_suit() != handVector[j + 1 + k].get_suit()) {
                suitFlag = false;
            }
        }
        if (suitFlag){
            //Test is cards make royal flush
            vector<Ranks> royalFlush = {ACE, KING, QUEEN, JACK, TEN};
            for (int i = 0; i < royalFlush.size(); ++i){
                if (handVector[i].get_rank_val() != royalFlush[i]){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

bool Poker::is_straight_flush(Hand h){
    vector<Card> handVector = h.get_hand();
    //Number of sequences of 5 in a sorted hand
    int numSets = 3;
    int sequence = 5;


    //check if
    for(int k = 0; k < numSets; k++) {
        bool suitFlag = true;
        bool rankFlag = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_suit() != handVector[j + 1 + k].get_suit()) {
                suitFlag = false;
            }
        }
        if (suitFlag){
            for (int j = 0; j < sequence - 1; ++j) {
                if (handVector[j + k].get_rank_val() - handVector[j + 1 + k].get_rank_val() != 1) {
                    rankFlag = false;
                }
                if (!rankFlag){
                    break;
                }
            }
            if (rankFlag){
                return true;
            }
        }
    }
    return false;
}

bool Poker::is_four_kind(Hand h){
    vector<Card> handVector = h.get_hand();

    int numSets = 4;
    int sequence = 4;



    for(int k = 0; k < numSets; k++) {
        bool fourKind = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank() != handVector[j + 1 + k].get_rank()) {
                fourKind = false;
            }
        }
        if (fourKind){
            return true;
        }
    }
    return false;
}

bool Poker::is_full_house(Hand h){
    vector<Card> handVector = h.get_hand();

    int numSets = 5;
    int sequence = 3;



    for(int k = 0; k < numSets; k++) {
        bool threeKind = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank() != handVector[j + 1 + k].get_rank()) {
                threeKind = false;
            }
        }
        if (threeKind){
            handVector = {handVector.begin() + sequence + k, handVector.end()};
            if (is_pair(handVector)){
                return true;
            }
        }
    }
    return false;

}

bool Poker::is_two_pair(Hand h){
    vector<Card> handVector = h.get_hand();

    int numSets = 6;
    int sequence = 2;

    for(int k = 0; k < numSets; k++) {
        bool pair = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank() != handVector[j + 1 + k].get_rank()) {
                pair = false;
            }
        }
        if (pair){
            handVector = {handVector.begin() + sequence + k, handVector.end()};
            Hand h2(handVector);
            if (is_pair(h2)){
                return true;
            }
        }
    }
    return false;
}

bool Poker::is_flush(Hand h){
    vector<Card> handVector = h.get_hand();
    //Number of sequences of 5 in a sorted hand
    int numSets = 3;
    int sequence = 5;

    //check if
    for(int k = 0; k < numSets; k++) {
        bool suitFlag = true;
        bool rankFlag = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_suit() != handVector[j + 1 + k].get_suit()) {
                suitFlag = false;
            }
        }
        if (suitFlag){
            return true;
        }
    }
    return false;
}

bool Poker::is_straight(Hand h){
    vector<Card> handVector = h.get_hand();
    //Number of sequences of 5 in a sorted hand
    int numSets = 3;
    int sequence = 5;

    //check if
    for(int k = 0; k < numSets; k++) {
        bool rankFlag = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank_val() - handVector[j + 1 + k].get_rank_val() != 1) {
                rankFlag = false;
            }
            if (!rankFlag){
                break;
            }
        }
        if (rankFlag){
            return true;
        }
    }
    return false;
}

bool Poker::is_three_kind(Hand h){
    vector<Card> handVector = h.get_hand();

    int numSets = 5;
    int sequence = 3;

    bool threeKind = true;

    for(int k = 0; k < numSets; k++) {
        threeKind = true;
        for (int j = 0; j < sequence - 1; ++j) {
            if (handVector[j + k].get_rank() != handVector[j + 1 + k].get_rank()) {
                threeKind = false;
            }
        }
        if (threeKind){
            return true;
        }
    }
    return false;
}

void Poker::reset_board(){
    this->d = Deck();
    this->d.shuffle_deck();
    this->user_hand = d.give_hand(2);
    this->cashier_hand = d.give_hand(2);
    this->community_hand = d.give_hand(5);

    cashier_hand.hide_hand();
    community_hand.hide_hand();
}

void Poker::update_game(std::string user) {

    //Variables
    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    //Variables
    fstream file_in, file_out;
    file_in.open("../poker.csv", ios::in);
    file_out.open("../poker_temp.csv", ios::out);

    //Loop until end of file
    while (!file_in.eof()) {

        //Read in lines from file
        row.clear();

        getline(file_in, line);
        stringstream ss(line);

        while (getline(ss, word, ',')){
            row.push_back(word);
        }

        int row_size = row.size();
        string username = row[0];

        //Check if username is approved users
        if (user == username) {

            //Read in and modify old balance with the new balance (old_balance + requested balance)
            string oldGameTotal = row[1];


            stringstream s(oldGameTotal);
            int oldGameTotalInt = 0;
            s >> oldGameTotalInt;

            int newGameTotal = oldGameTotalInt + 1;
            row[1] = to_string(newGameTotal);

            //Added editing line to file
            if (!file_in.eof()) {
                for (int i = 0; i < row_size - 1; ++i){
                    file_out << row[i] << ",";
                }

                file_out << row[row_size - 1] << "\n";

            }
        }
        else{
            //Read in lines to file without modification
            if (!file_in.eof()) {
                for (int i = 0; i < row_size - 1; i++){
                    file_out << row[i] << ",";
                }

                file_out << row[row_size - 1] << "\n";
            }
        }
        if (file_in.eof())
            break;
    }

    file_in.close();
    file_out.close();

    //Remove old file, and Rename Temp file
    //Currently experiencing an error with file deletion
    remove("../poker.csv");
    rename("../poker_temp.csv", "../poker.csv");
}

int Poker::get_games_played(std::string username) {

    int gamesPlayed;
    string cashier_file = "../poker.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (cashier_file, ios::in);

    //Read File into Vector
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else {
        cout << "Could not open the file\n";
    }

    file.close();

    //get balance for username
    for(int i=1;i<content.size();++i)
    {
        string compUsername = content[i][0];
        if (compUsername == username){
            gamesPlayed = stoi(content[i][1]);
        }
    }
    return gamesPlayed;
}


