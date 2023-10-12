#include <ctype.h>
#include <iostream>
#include <sstream>
#include <string>

#ifndef M1OEP_MWILSO33_VALIDATE_H
#define M1OEP_MWILSO33_VALIDATE_H
using namespace std;

class Validate {

public:

    char get_char_from_user(string prompt);
    string get_word_from_user(string prompt);
    string get_sentence_from_user(string prompt);
    int get_int_from_user(string prompt);
    double get_float_from_user();
    bool check_digit(string user_input, bool is_float);
    bool check_space(string user_input);


};


#endif //M1OEP_MWILSO33_VALIDATE_H
