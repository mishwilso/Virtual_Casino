/**
 * This is the Game Class. This class contains the universal game functions
 * such as taking in the users bet, and changing the number of total games
 * the user has played.
 */
 #include "Game.h"

Game::Game() {
    ;
}

Game::Game(string username){
this->username = username;
}

int Game::get_games_played(std::string username) {

    int gamesPlayed;
    string cashier_file = "../cashier.csv";

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
            gamesPlayed = stoi(content[i][2]);
        }
    }
    return gamesPlayed;
}


void Game::user_bet(string username){
    Cashier cash;
    users_bet = valid.get_int_from_user("How much would you like to bet?");
    while(users_bet <= 0){
        users_bet = valid.get_int_from_user("Value must be greater than 0. How much would you like to bet?");
    }
    while(!cash.check_balance(users_bet, username)){
        cout << "Not Enough Cash Balance for Bet! Your current balance is: " << cash.get_balance(username) << endl;
        users_bet = valid.get_int_from_user("How much would you like to bet?");
        while(users_bet <= 0){
            users_bet = valid.get_int_from_user("Value must be greater than 0. How much would you like to bet?");
        }
    }
}

void Game::additional_bet(string username){
    Cashier cash;
    int value = valid.get_int_from_user("How much would you like to additionally bet?");
    while(value < 0){
        value = valid.get_int_from_user("Value must be greater than or equal to 0. How much would you like to bet?");
    }
    while(!cash.check_balance((users_bet + value), username)){
        cout << "Not Enough Cash Balance for Bet! Your current balance is: " << cash.get_balance(username) << endl;
        value = valid.get_int_from_user("How much would you like to additionally bet?");
        while(value < 0){
            value = valid.get_int_from_user("Value must be greater than or equal to 0. How much would you like to bet?");
        }
    }
    users_bet += value;
}

void Game::update_games_played(std::string user) {

    //Variables
    vector<vector<string>> content;
    vector<string> row;
    string line, word;


    //Variables
    fstream file_in, file_out;
    file_in.open("../cashier.csv", ios::in);
    file_out.open("../cashier_temp.csv", ios::out);

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
            string oldGameTotal = row[2];


            stringstream s(oldGameTotal);
            int oldGameTotalInt = 0;
            s >> oldGameTotalInt;

            int newGameTotal = oldGameTotalInt + 1;
            row[2] = to_string(newGameTotal);

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
    remove("../cashier.csv");
    rename("../cashier_temp.csv", "../cashier.csv");
}