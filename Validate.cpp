/**
 * This is the Validation Class. This class contains all the validation
 * methods used to check user input. This was taken from Module 1 Applied
 * Projects, however was slightly modified to take in prompts, inorder to customize
 * the different instructions.
 * TODO:
 *  - Update float validator
 */

#include "Validate.h"

char Validate::get_char_from_user(string prompt) {
    string user_char;
    char valid_input;
    bool valid = false;

    while (!valid)
    {
        cout << prompt << ": ";
        getline(cin, user_char);

        if (user_char.length() > 1) {
            cout << "Invalid, input was not a singular character. ";
        } else if(user_char.length() < 1){
            cout << "No input. ";
        } else {
            valid_input = user_char[0];
            valid = true;
        }

        cin.clear();
    }
    return valid_input;
}

string Validate::get_word_from_user(string prompt) {
    string user_word;
    bool valid = false;
    while (!valid)
    {
        cout << prompt << ": ";
        getline(cin, user_word);

        if(user_word.length() < 1){
            cout << "No input. ";
        }else if (Validate::check_space(user_word)) {
            cout << "Invalid, input was not a word (Input must have no spaces)";
        } else {
            valid = true;
        }

    }
    return user_word;
}

string Validate::get_sentence_from_user(string prompt) {
    string user_sentence;
    bool valid = false;

    while (!valid)
    {
        cout << prompt << ": ";
        getline(cin, user_sentence);

        if(user_sentence.length() < 1){
            cout << "No input. ";
        } else {
            valid = true;
        }

        cin.clear();

    }
    return user_sentence;
}

int Validate::get_int_from_user(string prompt) {
    int valid_input;
    string user_int;
    stringstream ss;
    bool valid = false;

    while (!valid){

        cout << prompt << ": ";
        getline(cin, user_int);
        ss << user_int;
        if (check_digit(user_int, false)) {
            if (ss >> valid_input) {
                valid = true;
            } else {
                ss.clear();
                ss.str("");
                if (user_int.length() < 1) {
                    cout << "No input. ";
                } else {
                    cout << "Invalid, Input was not an integer(Input should have no decimals). ";
                }
            }
        } else {
            ss.clear();
            ss.str("");
            cout << "Invalid input. ";
        }

    }
    return valid_input;
}

double Validate::get_float_from_user() {
    double valid_input;
    string user_float;
    stringstream ss;
    bool valid = false;

    while (!valid){

        cout << "Enter a floating-point number: ";
        getline(cin, user_float);
        ss << user_float;

        if (check_digit(user_float, true)) {
            if (ss >> valid_input) {
                valid = true;
            } else {
                ss.clear();
                ss.str("");
                if (user_float.length() < 1) {
                    cout << "No input. ";
                } else {
                    cout << "Invalid, Input was not a float. ";
                }
            }
        } else {
            ss.clear();
            ss.str("");
            cout << "Invalid input. ";
        }

    }
    return valid_input;
}

bool Validate::check_digit(string user_input, bool is_float){
    for (int i = 0; i < user_input.length(); ++i) {
        if (i == 0){
            if (user_input[i] != '-') {
                if (is_float) {
                    if (user_input[i] != '.')
                        if (isdigit(user_input[i]) == false || isspace(user_input[i] == true))
                            return false;
                } else {
                    if (isdigit(user_input[i]) == false || isspace(user_input[i] == true))
                        return false;
                }
            }
        } else {
            if (is_float) {
                if (user_input[i] != '.')
                    if (isdigit(user_input[i]) == false || isspace(user_input[i] == true || user_input[i] != '.'))
                        return false;
            } else {
                if (isdigit(user_input[i]) == false || isspace(user_input[i] == true))
                    return false;
            }
        }
    }
    return true;
}

bool Validate::check_space(string user_input){
    for (int i; i < user_input.length(); ++i) {
        if (isspace((char) user_input[i])) {
            return true;
        }
    }
    return false;
}