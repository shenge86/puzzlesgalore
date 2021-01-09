/*----------------------------------------------------------------
* Blackjack
* Description: 
    Plays simple version of casino game - for 1 - 7 players
* Version: 1.0
----------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;
// using std::cout;
// using std::endl;

class Card {
    public:
        enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JAcK, QUEEN, KING};
        enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

        // overloading << operator so can send Card object to standard output
        friend ostream& operator<<(ostream& os, const Card& aCard);

        Card(rank r = ACE, suit s = SPADES, bool ifu = true);

        // returns value of a card, 1 - 11
        int GetValue() const;

        // flips a card; if face up, becomes face down
        voidFlip();

    private:
        rank m_Rank;
        suit m_Suit;
        bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int main() {
    cout << "\t\tWelcome to virtual blackjack!\n\n"
    cout << "=========================" << endl;


    return 0;
}