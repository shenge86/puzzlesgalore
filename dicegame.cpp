// dicegame.cpp
// A simple dice game
// Comments are notes

#include "stdafx.h"
#include <iostream>
#include <math.h>
// #include <cstdlib>

// namespace std;
using namespace std;

class Dice {
private:
	int value;
public:
	Dice::Dice(); // constructor
	~Dice(); // destructor	

	static int s_numdice; // total number of dice
	static int s_rolls; // the number of total rolls
	static int s_score; // the total quantity from all dice rolls
	static int s_scoretrue; // true score dependent on condition from CheckValue()

	/*
	All static data is initialized to zero when the first object is created, if no other initialization is present. We can't put it in the class definition but it can be initialized outside the class as done in the following example by redeclaring the static variable, using the scope resolution operator :: to identify which class it belongs to. 
	*/

	// methods
	void Roll(); // method prototype
	// int GetValue() { return value; }; // do this only for simple ones
	int GetValue(); // method prototype
	static int GetRolls();
	static int GetScore();
	static int GetScoreTrue();
	static void CheckValue(int val);
};

// constructor
Dice::Dice() {
	s_numdice++;
}

// destructor
Dice::~Dice() {
	cout << "Dice destroyed." << endl;
}

// static member variable initialization
// This is REQUIRED
int Dice::s_numdice = 0;
int Dice::s_rolls = 0;
int Dice::s_score = 0;
int Dice::s_scoretrue = 0;

// Methods (public)
void Dice::Roll() {
	int val;
	val = rand() % 6 + 1;
	this->value = val; // sets the value of this class member variable equal to val
	
	// increment roll and add up total score
	s_rolls ++;
	s_score += val; // total dice amount
}

int Dice::GetValue() {
	// check for score
	return value;
}

// Methods (private)



// Methods (static)
int Dice::GetRolls() {
	return s_rolls;
}

int Dice::GetScore() {
	return s_score;
}

int Dice::GetScoreTrue() {
	return s_scoretrue;
}

void Dice::CheckValue(int val) {
	if (val < 11) {
		s_scoretrue -= 1;
	}
	else if (val > 11) {
		s_scoretrue += 1;
	}
}

int main() {
	// create variables and objects
	int val1, val2;
	char input = 0;
	int vallose = -1;
	int valwin = 1;

	Dice dice1;
	Dice dice2;

	// run the game
	while (input != 'q' || Dice::GetScoreTrue() > valwin || Dice::GetScoreTrue() < vallose) {
		dice1.Roll();
		dice2.Roll();
		val1 = dice1.GetValue();
		val2 = dice2.GetValue();

		cout << "You rolled a " << val1+val2 << endl;
		cout << "This was roll #: " << Dice::GetRolls() / 2 << endl;
		cout << "Your total dice amount is: " << Dice::GetScore() << endl;

		Dice::CheckValue(val1 + val2);
		cout << "Your total score is: " << Dice::GetScoreTrue() << endl;

		if (Dice::GetScoreTrue() > valwin) {
			cout << "YOU WIN!";
			cin >> input;
			break;
		}
		else if (Dice::GetScoreTrue() < vallose) {
			cout << "YOU LOSE!";
			cin >> input;
			break;
		} else {
			cout << "Roll again? Enter q to quit." << endl;
			cin >> input;
		}

		
	}
    return 0;
}