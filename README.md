# Module 1 - OpenEnded Project (Mish Casino)

Name: Mish Wilson

For this Project, My aim to create a virtual casino that has a varying collection
of games based on probability and chance. As of Module 2, the Casino now has the game POker
where the user can bet their money. 

## C++ Concepts Included

* Has-A Relationships
  * Casino Has-A: 
    * Validate : Which it uses to validate user input when interacting with Casino menus
    * Register : Which it uses to register users to the Casino
    * Cashier  : Which it uses to read in uses information, such as cash amount and general user statistics. Also allows users to make cash requests
    * Poker : Which it uses to play Poker
  * Cashier Has-A:
    * Validate : Which it uses to validate user input during cash request
  * Register Has-A:
    * Validate : Which it uses to validate user input during the registration process.
  * Deck Has-A:
    * Card : The deck is constructed of 52 unique* cards, as in no repeating cards can be found in the deck
  * Hand Has-A:
    * Card : The hand is constructed of cards, depending on the size of hand dealt the number of cards change
  * Poker Has-A:
    * Deck : A deck of cards is constructed and shuffled at the beginning of every poker game
    * Hand : A hand is dealt to the user, the cashier and one for the community hand
    * Card : Poker utilizes cards, which it needs for the different comparison of hands such as royal flush, pair, etc..

* Is-A Relationships
  * Poker Is-A:
    * Game : Poker is a Game, which allows it to make updates to the user statistics as well as check if the user has enough money for their bets
  
* Input Files
  * Cashier reads in from cashier.csv for user balance and total games played
  * Cashier reads in from request.csv for user's cash-requests and whether they were approved or not
  * Register reads in from user.csv to check if user exists, and to ensure duplicate usernames aren't being inputted
  * Poker reads in from poker.csv for the amount of poker games a user has played
* Output Files
  * Game updates' cashier.csv, incrementing the users total games played by one each time they play a game 
  * Poker updates poker.csv, increment the users total poker games played by one.
  * Cashier updates cashier.csv with the users update balance from winnings and from approved cash requests.
  * Cashier updates the request.csv with user's cash-requests
  * Register updates user.csv with newly registered users.

## Known Bugs
  * Currently, the poker game doesn't make comparison of matching hands. For example if both the Cashier and User have pairs.
  * If the user makes a choice to Raise, there is a chance the choice will be ignored if the cashier (Lisa) has already decided to fold prior. Not necessarily a bug, but it's something I noticed.
  * Poker sometimes reads in one pair as two pairs.

## Future Work
There are a few features that I wish to add to the Mish Casino, these include:
* 3 more games utilizing the card system to the Casino
* Add Password hashing for extra security.

## Citation
MergeSort Class from Lisa Dion (CS124 Data Structures & Algorithms)

## Grade I think I earned

Main Program : 40 pts 
Reason: I believe my main program has a lot of intractability, and user input is validated correctly.

Testing Program : 20 pts
Reason: I have a robust testing program is place, primarily for my Poker Game and Deck of Cards since it contained nontrivial class methods to test. 

Concept Is-A or Has-A: 220 pts
Reason: I have created 11 Is-A or Has-A Relationships, which are designed and implemented in my program robustly in ways that made sense for my program.

Concept File I/O: 45 pts
Reason: I have File Input/Output occur during 9 different occasions of my program. Included above are the different ways each one is used.

Style : 0 pts
Reason: I fully document every method, as well as left line comments throughout my program

Video : 0 pts
Reason I showcased validation as well as the intractability of my program

Lifespan of Project : 0 pts
