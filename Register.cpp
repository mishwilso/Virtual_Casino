/**
 * This is the Register Class. This class the methods needed for the
 * user to get registered into the database, as well as checks for user
 * information inorder to login or run other comparisons.
 */

#include "Register.h"

Register::User Register::login_user(string username, string password) {

    //Variables
    User user_information;

    string user_file = "../user.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    //Open file and read into vector
    fstream file (user_file, ios::in);
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
        user_information.valid = false;
        user_information.username = "";
        user_information.access_levels = 0;
        return user_information;
    }
    file.close();

    //Read through vector and check if user exists in database.
    for(int i=1;i<content.size();i++)
    {
        string comp_username = content[i][0];
        //Check for username in vector
        if (comp_username == username){
            //check for password in vector
            string comp_password = content[i][1];
            if (comp_password == password){
                cout<<"\n"<<endl;
                //Take found Information and put into User Struct
                user_information.valid = true;
                user_information.username = username;
                user_information.access_levels = stoi(content[i][2]);
                return user_information;
            }
            else {
                cout << "Incorrect Password!" << endl;
                cout << "\n";
            }
        }
    }
    cout << "User Not Found, please register your account." << endl;
    cout << "\n";

    user_information.valid = false;
    user_information.username = "";
    user_information.access_levels = 0;
    return user_information;
}

bool Register::is_username_available(string username) {

    //Variables
    string user_file = "../user.csv";

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file (user_file, ios::in);

    //Read file into vector
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
        return false;
    }
    file.close();

    //Check if username is inside vector
    for(int i=1;i<content.size();++i)
    {
        string comp_username = content[i][0];
        if (comp_username == username){
                return false;
            }
    }
    return true;

}

bool Register::register_user() {

    //Variables
    ofstream file_user;

    string username = get_username();
    string password = get_password();
    int access_level = 0;

    string user_file = "../users.csv";
    //Add user to User File
    file_user.open(user_file, ios::out | ios::app);
    if(file_user.is_open()) {
        file_user << username << "," << password << "," << access_level << "\n";
        cout << "===== User Successfully Registered =====" << endl;
    } else {
        cout << "Could not open the file\n";
        return false;
    }
    file_user.close();

    ofstream file_cashier;
    //Add user to Cashier File
    string cashier_file = "../cashier.csv";

    file_cashier.open(cashier_file, ios::out | ios::app);
    if(file_cashier.is_open()) {
        file_cashier << username << "," << BASE_CASH << "," << BASE_GAMES_PLAYED << "\n";
        cout << "===== User Successfully Added to Cashier =====" << endl;
    } else {
        cout << "Could not open the file\n";
        return false;
    }
    file_cashier.close();
    return true;

}

string Register::get_username() {
    string username = valid.get_word_from_user("Username");

    //Validate Use's username
    while (!Register::is_username_available(username)) {
        cout << "Invalid username, Username already in use." << endl;
        username = valid.get_word_from_user("Username");;
    }
    return username;
}

string Register::get_password() {
    cout << "Please enter a strong password. A strong password has each of the following: ";
    cout << "\n[ ] Between 8 and 25 characters"
            "\n[ ] At least one Uppercase Letter"
            "\n[ ] At least one Lowercase letter"
            "\n[ ] At least one digit"
            "\n[ ] At least one special character (! @ # $ % ^ & )" << endl;
    string password = valid.get_word_from_user("Password");

    //Validate User's password
    while (!Register::test_password(password)) {
        cout << "Password is too weak. Try again." << endl;
        password = valid.get_word_from_user("Password");;
    }
    return password;
}

bool Register::test_password(string password) {

    //Variable Flags
    bool special_char_check = false;
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    int digits = 0;
    int letters = 0;

    //All Numbers Check
    for (char const &ch : password) {
        if (isdigit(ch) == 1)
            ++digits;
    }
    if (digits == password.length())
        return false;

    //All Letters Check
    for (char const &ch : password) {
        if (isalpha(ch) == 1)
            ++letters;
    }
    if (letters == password.length())
        return false;

    //Length Check
    if (password.length() < PASSWORD_MIN_LENGTH)
        return false;

    if (password.length() > PASSWORD_MAX_LENGTH)
        return false;

    //Upper, Lower, Digit and Special Character Check
    for (char const &ch : password) {
        for (char const &spec_ch: SPECIAL_CHAR) {
            if (ch == spec_ch)
                special_char_check = true;
        }

        if (isupper(ch))
            has_upper = true;

        if (islower(ch))
            has_lower = true;

        if (isdigit(ch))
            has_digit = true;
    }
    if (!special_char_check || !has_digit || !has_lower || !has_upper)
        return false;
    else
        return true;
}




