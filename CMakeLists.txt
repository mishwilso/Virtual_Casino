cmake_minimum_required(VERSION 3.23)
project(M2OEP_mwilso33)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Casino_Main
        Validate.cpp
        Validate.h
        Game.cpp
        Game.h
        Hand.cpp
        Hand.h
        Casino.cpp
        Casino.h
        Cashier.cpp
        Cashier.h
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Poker.cpp
        Poker.h
        Register.cpp
        Register.h
        mergeSort.h
        main.cpp)
add_executable(Casino_Testing
        Validate.cpp
        Validate.h
        Game.cpp
        Game.h
        Hand.cpp
        Hand.h
        Casino.cpp
        Casino.h
        Cashier.cpp
        Cashier.h
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Poker.cpp
        Poker.h
        Register.cpp
        Register.h
        mergeSort.h
        Casino_Testing.cpp)
