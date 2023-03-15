#include <iostream>
#include <ctime>
using namespace std;
int main()
{
    int balance = 1000;   // initial bank balance
    int bet = 0;          // Declaration of bet variable
    bool GameLoop = 1;    // boolean which runs through the whole game
    char choice;          // A choice between number or color
    int number = 0;       // randomised number
    int PickedNumber = 0; // The number player picks when choosing number
    int replay;           // Allows the player to replay
    int money;            // Allows player to insert money
    bool LoopTwo = 1;     // boolean which wraps the choice to replay
    bool LoopThree = 1;   // boolean which wraps the entire number and color option
    bool NumLoop = 1;     // boolean which wraps the number option
    bool ColLoop = 1;     // boolean which wraps the color option
    int totalwin = 0;     // Total profit
    char color;           // choice between red or black
    bool refill = 1;      // boolean which wraps the option to refill the bank account

    // Game rules
    cout << " - Welcome to roulette! You start with 1000 kr." << endl;
    cout << " - You have the option to bet 100, 300 or 500 kr" << endl;
    cout << " - You can either bet on a color (red=odd numbers or black=even 
                numbers) or a single number (between 1 to 36)" << endl;
    cout << " - You have the option to end or replay the game after each round is 
                finished." << endl; 
    cout << " - You have maximum credit of -400 kr, in order to proceed you need at
                least 100 kr to place a bet to keep playing." << endl; 
    cout << " - You have the option to refill your bank balance if it goes below 
                100 kr in order to proceed. Let’s start!" << endl;
    cout << " Balance: " << balance << "kr" << endl;

    while (GameLoop)
    {
        // Player has the choice to play
        while (LoopTwo)
        {
            cout << "Play (1) roulette or Exit (0)?" << endl;
            cin >> replay;
            if (replay == 1)
            {
                cout << "Bet 100, 300 or 500 kr" << endl;
                cin >> bet;
                break;
            }
            else if (replay == 0)
            {
                cout << "Goodbye!" << endl;
                LoopTwo = 0;
                GameLoop = 0;
                LoopThree = 0;
            }
        }
        // If player makes a valid bet of either 100, 300 or 500
        while (LoopThree)
        {
            if (bet == 100 || bet == 300 || bet == 500)
            {
                cout << "Choose to bet on a number (n) or a color (c)" << endl;
                cin >> choice;
                // If player chooses to bet on number
                if (choice == 'n' || choice == 'N')
                {
                    while (NumLoop)
                    {
                        cout << "Choose a number between 1 to 36." << endl;
                        cin >> PickedNumber;
                        if ((PickedNumber <= 36) && (PickedNumber >= 0))
                        {
                            srand(time(0));
                            number = rand() % 36 + 1;
                            // If player wins on number
                            if (PickedNumber == number)
                            {
                                totalwin += (bet * 10);
                                cout << "The winning number is: " << number << endl;
                                balance = ((balance + (bet * 10)) - bet);
                                cout << "Congratulations! You won: " << bet * 10 << "kr" << endl;
                                cout << "Total winnings: " << totalwin << endl;
                                cout << "Current account balance: " << balance << "kr" << endl;
                                break;
                            }
                            // if player loses on number
                            else
                            {
                                cout << "The winning number is: " << number << endl;
                                cout << "You lost the bet of " << bet << "kr" << endl;
                                balance = (balance - bet);
                                cout << "New account balance: " << balance << "kr"
                                    << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
                // If player bets on color
                else if (choice == 'c' || choice == 'C')
                {
                    while (ColLoop)
                    {
                        cout << "Do you want to bet on red (r) or black (b)?" << endl;
                        cin >> color;
                        srand(time(0));
                        number = rand() % 36 + 1;
                        // If player wins or loses on red
                        if (color == 'r')
                        {
                            if ((color == 'r') && (number % 2 == 1))
                            {
                                balance = ((balance + (bet * 2)) - bet);
                                cout << "The winning number is: " << number << ", which is an odd number !" << endl;
                                cout << "Congratulations! You won: " << bet * 2 << "kr" << endl;
                                totalwin += (bet * 2);
                                cout << "Total winnings: " << totalwin << endl;
                                cout << "Current account balance: " << balance << "kr" << endl;
                                break;
                            }
                            else
                            {
                                cout << "The winning number is: " << number << ", which is an even number !" << endl;
                                cout << "You lost the bet of " << bet << "kr" << endl;
                                balance = (balance - bet);
                                cout << "New account balance: " << balance << "kr" << endl;
                                break;
                            }
                        }
                        // If player wins or loses on black
                        else if (color == 'b')
                        {
                            if ((color == 'b') && (number % 2 == 0))
                            {
                                balance = ((balance + (bet * 2)) - bet);
                                cout << "The winning number is: " << number << ", which is an even number !" << endl;
                                cout << "Congratulations! You won: " << bet * 2 << endl;
                                totalwin += (bet * 2);
                                cout << "Total winnings: " << totalwin << endl;
                                cout << "Current account balance: " << balance << "kr" << endl;
                                break;
                            }
                            else
                            {
                                cout << "The winning number is " << number << ", which is an odd number " << endl;
                                cout << "You lost the bet of " << bet << "kr" << endl;
                                balance = (balance - bet);
                                cout << "New account balance: " << balance << "kr" << endl;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            // If the input is a bet which is other than 100, 300 or 500 kr
            else
            {
                cout << "Please insert a valid bet of either 100, 300 or 500 kr." << endl;
                cin >> bet;
            }
        }
        // Refill account balance if too low
        if (balance < 100)
        {
            while (refill)
            {
                cout << "Your balance is too low! You need at least 100 kr in your 
                        account.Insert money to proceed or type in '0' to end the game,
                        you will be billed if your credit is below 0 !" << endl;
                cin >>
                money;
                balance = balance + money;
                cout << "Current balance: " << balance << "kr" << endl;

                if (money == 0)
                {
                    refill = 0;
                    GameLoop = 0;
                }
                else if (balance >= 100)
                {
                    break;
                }
            }
        }
    }
    return 0;
}