/**
 * This is the Cashier Class. This class contains all the manipulation
 * methods for the "cash" in "Mish Casino" This allows for the Cashier to Deny
 * and Allow cash requests, and for Players to submit their own cash requests.
 * TODO:
 *  - Fix cashier.csv removal problem
 *  - Add Method to display user cash list
 */

#include "Cashier.h"


void Cashier::user_stats(string username){
    Poker p = Poker(username);

    //Variables
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

    //Print out user Statistics from vector
    for(int i=1;i<content.size();++i)
    {
        string comp_username = content[i][0];
        if (comp_username == username){
            cout << setw(25) << "Cash Balance" << setw(20) << "Games Played" << endl;
            string cash_balance = content[i][1];
            string games_played = content[i][2];
            cout << setw(20) << cash_balance << setw(20) << games_played << endl;

            cout << "===================Game Statistics=====================" << endl;
            cout << "Poker Played: " << p.get_games_played(username) << endl;
            cout << "Game 2 Played: N/A" << endl;
            cout << "\n";
        }
    }
}

void Cashier::cash_request(std::string username) {
    //Take in user input
   int request = valid.get_int_from_user("Enter requested amount (as an integer)");
   string comment = valid.get_sentence_from_user("Leave a funny comment, and increase your chances of your request being accepted");

   ofstream file;
    string request_file = "../request.csv";

   //Add user to User File
   file.open(request_file, ios::out | ios::app);
   if(file.is_open()) {
       file << username << "," << request << "," << comment << "\n";
       cout << "===== Request Successfully Inputted =====" << endl;
       cout << "\n";
   } else {
       cout << "Could not open the file\n";
   }
   file.close();

}

void Cashier::request_approval() {

    //Variables
    vector<vector<string>> content;
    vector<string> row;
    string line, word;
    string amount_requested;

    string request_file = "../request.csv";

    //Read into file to vector
    fstream file (request_file, ios::in);
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

    //Print out vector as table
    vector<vector<string>> request_forms = content;
    cout << left << setw(20) << "Username" << setw(20) << "Cash Request" << setw(20) << "Comment " <<  endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;


    for(int i = 0;i < request_forms.size(); i++)
    {
        string username = request_forms[i][0];
        string request = "$" + request_forms[i][1];
        string comment = request_forms[i][2];

        cout << left << setw(20) << username << setw(20)<< request << setw(20) << comment << endl;
        cout << "\n------------------------------------------------------------------------------------------------" << endl;

    }

    //Approval Station
    cout << "===================Approval Station=====================" << endl;

    //Get Cashiers input
    string approved_user = valid.get_word_from_user("Username");
    char approved = valid.get_char_from_user("Enter Y to Approve, N to Deny");
    approved = (char)tolower(approved);

    //Validate input
    while (!(approved ==  'y'  || approved ==  'n')) {
        cout << "Invalid Input, please ";
        approved = valid.get_char_from_user("enter Y to Approve, N to Deny");
    }

    //Mark Request as Approved or Denied
    fstream fin, fout;
    fin.open("../request.csv", ios::in);
    fout.open("../request_temp.csv", ios::out);

    //Loop until the end of the file
    while (!fin.eof()) {

        //Read in line of File
        row.clear();

        getline(fin, line);
        stringstream ss(line);

        while (getline(ss, word, ',')){
            row.push_back(word);
        }

        int row_size = row.size();
        string username = row[0];

        //Check if username is approved user
        if (approved_user == username) {

            amount_requested = row[1];

            //Change user status
            if (tolower(approved) ==  'y'){
                row[2] = "APPROVED";
                row[0] = row[0]+"-A";
            } else if (tolower(approved) ==  'n') {
                row[2] = "DENIED";
                row[0] = row[0]+"-D";
            }

            //Add edited row to file
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; ++i){
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";

            }
        }
        else{

            //Read through vector without modifying
            if (!fin.eof()) {
                for (int i = 0; i < row_size - 1; i++){
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
            break;
    }

    //Close and remove old file, then rename new file
    fin.close();
    fout.close();

    remove("../request.csv");
    rename("../request_temp.csv", "../request.csv");

    //Update user cash amount
    if (approved ==  'y'){

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
            if (approved_user == username) {

                //Read in and modify old balance with the new balance (old_balance + requested balance)
                string old_balance = row[1];

                stringstream ss(amount_requested);
                int amount_requested_int = 0;
                ss >> amount_requested_int;

                stringstream s(old_balance);
                int old_balance_int = 0;
                s >> old_balance_int;

                int new_balance = old_balance_int + amount_requested_int;
                row[1] = to_string(new_balance);

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

}


bool Cashier::check_balance(int request, std::string username){

    int cash_balance;
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
        string comp_username = content[i][0];
        if (comp_username == username){
            cash_balance = stoi(content[i][1]);
        }
    }

    if (cash_balance >= request){
        return true;
    }
    return false;
}

int Cashier::get_balance(std::string username) {

    int cash_balance;
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
        string comp_username = content[i][0];
        if (comp_username == username){
            cash_balance = stoi(content[i][1]);
        }
    }
    return cash_balance;
}

void Cashier::updateBalance(std::string user, int amount_requested) {

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
            string old_balance = row[1];


            stringstream s(old_balance);
            int old_balance_int = 0;
            s >> old_balance_int;

            int new_balance = old_balance_int + amount_requested;
            row[1] = to_string(new_balance);

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