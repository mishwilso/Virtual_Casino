/**
 * This is the Casino Class. This class contains the interactive menu's
 * the user needs to select different actions. It contains the welcome
 * menu, user menu (For Admin, Player and Cashier) and game menu.
 * TODO:
 *  - Finish Implementing Game Menu
 *  - Finish user menu for Admin and Cashier
 */

#include "Casino.h"

void Casino::welcome_menu() {
    int selection;
    Register::User user_information;

    cout << "======================== Welcome to ======================" << endl;
    cout << "\n"
            "\t         __  __ _____  _____ _    _ \n"
            "\t        |  \\/  |_   _|/ ____| |  | |\n"
            "\t        | \\  / | | | | (___ | |__| |\n"
            "\t        | |\\/| | | |  \\___ \\|  __  |\n"
            "\t        | |  | |_| |_ ____) | |  | |\n"
            "\t        |_|  |_|_____|_____/|_|  |_|\n" << endl;
    cout << "      .------..------..------..------..------..------.\n"
            "      |C.--. ||A.--. ||S.--. ||I.--. ||N.--. ||O.--. |\n"
            "      | :/\\: || (\\/) || :/\\: || (\\/) || :(): || :/\\: |\n"
            "      | :\\/: || :\\/: || :\\/: || :\\/: || ()() || :\\/: |\n"
            "      | '--'C|| '--'A|| '--'S|| '--'I|| '--'N|| '--'O|\n"
            "      `------'`------'`------'`------'`------'`------'" << endl;
    cout << "============================================================" << endl;

    cout << "Please Select one of the following options by entering the \ncorresponding number: \n";
    cout << "[1] Login \n[2] Register \n[3] Exit" << endl;
    selection = valid.get_int_from_user("Selection");
    cout << "\n";

    //Validate User's input
    while(selection < 1 || selection > 3){
        cout << "Invalid Selection, please select from the following options: " << endl;
        cout << "[1] Login "
                "\n[2] Register "
                "\n[3] Exit" << endl;
        selection = valid.get_int_from_user("Selection");
        cout << "\n";
    }

    //Options based on user input
    if (selection == 1){
        cout << "===================== Login User ======================" << endl;
        //Check user, and logged them
        string username = valid.get_word_from_user("Username");
        string password = valid.get_word_from_user("Password");
        user_information = r.login_user(username, password);

        //Open menu to Casino :) - separate function
        if (user_information.valid)
        {
            user_menu(user_information.username, user_information.access_levels);
            welcome_menu();
        } else {
            cout << "Invalid User Login" << endl;
            welcome_menu();
        }


    } else if (selection == 2) {
        cout << "=================== Register User =====================" << endl;
        r.register_user();
        welcome_menu();
    } else {
        cout << "Goodbye!";
        exit(0);
        //End program!
    }
    
}

void Casino::user_menu(string username, int access_level) {
    int selection;

    switch (access_level) {
        case PLAYER:
            cout << "=================== Welcome " << username << " =====================" << endl;
            cout << "Please Select one of the following options by entering the \ncorresponding number: \n";

            cout << "[1] User Statistics "
                    "\n[2] Casino Games "
                    "\n[3] Cash Request "
                    "\n[4] Log-Out" << endl;
            selection = valid.get_int_from_user("Selection");
            cout << "\n";

            while (selection < 1 || selection > 4) {
                cout << "Invalid Selection, please select from the following options: " << endl;
                cout << "[1] User Statistics "
                        "\n[2] Casino Games "
                        "\n[3] Cash Request "
                        "\n[4] Log-Out" << endl;
                selection = valid.get_int_from_user("Selection");
                cout << "\n";
            }

            if (selection == 1) {
                cout << "=================== User Statistics =====================" << endl;
                //Call Cashier class and display user stats
                cash.user_stats(username);
                user_menu(username, access_level);

            } else if (selection == 2) {
                cout << "=================== Casino Games =====================" << endl;
                //Call Casino Game list method (in casino class) have it display game options
                game_menu(username, access_level);
                user_menu(username, access_level);

            } else if (selection == 3) {
                cout << "===================Cash Request=====================" << endl;
                //Call Cashier class and have User enter request for more cash. Which gets reviewed by the cashier.
                cash.cash_request(username);
                user_menu(username, access_level);

            } else {
                cout << "Goodbye!" << endl;
                cout << "\n";
                welcome_menu();
                //End program!
            }

        case CASHIER:
            cout << "=================== Welcome " << username << " =====================" << endl;
            cout << "Please Select one of the following options by entering the \ncorresponding number: \n";

            cout << "[1] Cash Requests "
                    "\n[2] Game Statistics "
                    "\n[3] Player Ranking "
                    "\n[4] Log-Out" << endl;
            selection = valid.get_int_from_user("Selection");
            cout << "\n";

            while (selection < 1 || selection > 4) {
                cout << "Invalid Selection, please select from the following options: " << endl;
                cout << "[1] Cash Requests "
                        "\n[2] Game Statistics "
                        "\n[3] Player Ranking "
                        "\n[4] Log-Out" << endl;
                selection = valid.get_int_from_user("Selection");
                cout << "\n";
            }

            if (selection == 1) {
                cout << "=================== Cash Requests =====================" << endl;
                //Call Cashier class and review cash requests for approval. (or rejection!)
                cash.request_approval();
                user_menu(username, access_level);

            } else if (selection == 2) {
                cout << "=================== Game Statistic =====================" << endl;
                //Call Casino to display Game statistics*
                cout << "Currently Under Repairs!" << endl;
                cout << "\n";
                user_menu(username, access_level);

            } else if (selection == 3) {
                cout << "=================== Player Rankings =====================" << endl;
                //Call Casino to display Player Rankings.
                cout << "Currently Under Repairs!" << endl;
                cout << "\n";
                user_menu(username, access_level);

            } else {
                cout << "Goodbye!" << endl;
                cout << "\n";
                //End program!
            }

        case ADMIN:
            cout << "=================== Welcome " << username << " =====================" << endl;
            cout << "Admin User Menu is Under Construction!" << endl;

    }
}

void Casino::game_menu(string username, int access_level) {
    p = Poker(username);
    //Method is currently a placeholder for games to be made!
    int selection;
    cout << "Please Select one of the following options by entering the \ncorresponding number: \n";
    cout << "[1] Poker"
            "\n[2] Game 2 "
            "\n[3] Game 3 "
            "\n[4] Game 4 " << endl;
    selection = valid.get_int_from_user("Selection");
    cout << "\n";

    while (selection < 1 || selection > 4) {
        cout << "Invalid Selection, please select from the following options: " << endl;
        cout << "[1] Poker "
                "\n[2] Game 2 "
                "\n[3] Game 3 "
                "\n[4] Game 4 " << endl;
        selection = valid.get_int_from_user("Selection");
        cout << "\n";
    }

    if (selection == 1) {
        p.poker_menu();

    } else if (selection == 2) {
        cout << "This is a work In-Progress Page! Initiating User Log-Out" << endl;
        cout << "\n";
        welcome_menu();
        //End program!


    } else if (selection == 3) {
        cout << "This is a work In-Progress Page! Initiating User Log-Out" << endl;
        cout << "\n";
        welcome_menu();
        //End program!


    } else {
        cout << "This is a work In-Progress Page! Initiating User Log-Out" << endl;
        cout << "\n";
        welcome_menu();
        //End program!
    }

}