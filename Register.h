#include <ctype.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Validate.h"

#ifndef M1OEP_MWILSO33_REGISTER_H
#define M1OEP_MWILSO33_REGISTER_H

using namespace std;

class Register {
private:
    Validate valid;
    const string SPECIAL_CHAR = "!@#$%^&*";
    const int PASSWORD_MIN_LENGTH = 8;
    const int PASSWORD_MAX_LENGTH = 25;
    const int BASE_CASH = 100;
    const int BASE_GAMES_PLAYED = 0;

public:
    //Struct for User Information
    struct current_user {
        bool valid;
        string username;
        int access_levels;
    };

    typedef struct current_user User;

    /*
     * Allows user to login into the Casino, by checking
     * their information in 'user.csv'
     * Requires: (string) username, (string) password
     * Modifies: nothing
     * Effects: Returns (User) user_information,
     * user_information will have empty values if user doesn't
     * exist in 'user.csv'
     */
    User login_user(string username, string password);

    /*
     * Allows user to register into the Casino
     * Requires: nothing
     * Modifies: nothing
     * Effects: Returns true if user successfully registered,
     * false if there was an issue with registration.
     */
    bool register_user();

    /*
    * Checks if "username" exists in 'user.csv'
    * Requires: (string) username
    * Modifies: nothing
    * Effects: Returns true if username is available,
    * returns false if the name is unavailable or if issues arise.
    */
    bool is_username_available(string username);


    /*
    * Gets User input for username
    * Requires: (string) username
    * Modifies: nothing
    * Effects: Returns (string) username
    */
    string get_username();

    /*
   * Gets User input for password
   * Requires: (string) password
   * Modifies: nothing
   * Effects: Returns (string) password
   */
    string get_password();

    /*
   * Checks if users password is a strong password.
   * Requires: (string) password
   * Modifies: nothing
   * Effects: Returns true if password passes all the requirements
   * thus is a strong password, returns false otherwise
   */
    bool test_password(string password);

};


#endif //M1OEP_MWILSO33_REGISTER_H
