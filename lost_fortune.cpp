// lost_fortune.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// FUNCTIONS
bool checkDeath(int killed, int adventurers) {
	if (killed == adventurers) {
		cout << "Everyone has died!" << endl;
		system("pause");
		return 0;
	}
}

void displayInventory(int numItems, string inventory[]) {
	for (int i = 0; i < numItems; ++i) {
		cout << i+1 << ". ";
		cout << inventory[i] << endl;
	}
}

void showBoard(int ROWS, int COLUMNS, char board[][3]) {
	for (int i = 0; i < ROWS;++i) {
		for (int j = 0;j < COLUMNS;++j) {
			cout << board[i][j];
		}
		cout << endl;
	}
}

int main()
{
	// declare constants and variables
	const int GOLD_PIECES = 900;
	int money = 1000;

	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	int numItems = 0;
	inventory[numItems++] = "steel short sword";
	inventory[numItems++] = "fine leather armor";
	inventory[numItems++] = "steel dagger";

	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = { {'0', 'X', '0'}, {' ', 'X', 'X'}, {'X','O','O'} };

	int adventurers, killed, survivors, choicenum;
	int adventurercost = 100;
	string leader;


	// START GAME
	// if random number generator here is not used, it will output the same sequence of random numbers every time it is run.
	srand(static_cast<unsigned int>(time(0))); // seed random number generator
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;

	// SETUP GAME
	cout << "Welcome to Lost Fortune " << string(3, '!') << " \n\n";

	cout << "Enter your name: ";
	cin >> leader;

	cout << "\nAside from having " << money << " pieces of gold, you start with these items: \n";
	displayInventory(numItems, inventory);

	cout << "\nAt the nearby tavern before you head towards the mountains, you decide to hire some adventurers. Each adventurer here will cost you " << adventurercost << " gold pieces.";
	cout << " How many do you hire?\n";
	cin >> adventurers;

	// if more money than you can afford, then set to max number of people you bought and set money to 0
	if (adventurercost * adventurers > money) {
		cout << "You realize that you don't have enough money to hire this many people so you decide to hire as many as you can.";
		adventurers = (money / adventurercost);
		cout << " You hired " << adventurers << " people.";
	}
	money -= adventurercost * adventurers;
	cout << "You have " << money << " gold pieces left.";
	adventurers++;

	// Start the story
	cout << "\nYour brave group of " << adventurers << " including yourself set out on the quest.";
	cout << " -- in search of the lost treasure in the mountain dwellings of the now extinct ancient dwarves. ";
	cout << "The group was led by you, that legendary rogue named " << leader << ".\n\n";
	
	// Ogre attack
	killed = rand() % adventurers + 1;
	survivors = adventurers - killed;

	cout << "Outside of the mountain entrance, a band of marauding ogres ambushed the party. The adventurers won but " << killed << " were killed.\n\n";

	if (survivors == 0) {
		checkDeath(killed, adventurers);
		return 0;
	}

	cout << "Afterwards, the remaining " << survivors << " adventurers stumbled upon buried fortune and split the " << GOLD_PIECES << " gold pieces amongst themselves. The leader held on to the extra " << (GOLD_PIECES % survivors);
	cout << " pieces to keep things fair of course.\n\n";

	money += GOLD_PIECES / survivors + (GOLD_PIECES % survivors);
	cout << "You now have " << money << " gold pieces in total.\n\n";

	// Tic-tac-toe game
	cout << "The entrance had a huge door with nine squares of x's and o's. It looked like a giant Tic-Tac-Toe puzzle. On closer inspection, you realize it is a giant puzzle. The instructions say that you only have one move possible. You look for an X or O and you see nothing. What do you do? \n\n";
	showBoard(ROWS, COLUMNS, board);
	cout << endl;
	
	do {
		cout << "You decide to take a look of your inventory. You decide to use: " << endl;
		displayInventory(numItems, inventory);
		cin >> choicenum;

		if (choicenum < numItems) {
			cout << "You place the " << inventory[choicenum - 1] << " on to the empty box." << endl;
			cout << "Ouch! You were hit on the arm with an arrow from the side of the cave. " << endl;
		}
		else {
			cout << "You pull your hair in frustration. " << endl;
		}
	} while (choicenum != 1);

	cout << "Now the board looks like: \n";
	board[1][0] = 'X';
	showBoard(ROWS, COLUMNS, board);
	cout << endl;

	cout << "\nWaiting for a moment in anticipation, the door opens!" << endl;

	// Part with word game
	cout << "\nUpon entering the cavern, you notice immediately a giant metal gate in front of you. There doesn't seem to be an obvious way to open this gate. Suddenly, a loud voice booms in the cavern which almost makes you deaf.";
	cout << "The voice says 'Ye, who enter! Guess my word and the gate shall enter. Fail and you die.'";
	cout << "This must be one of those famed automated dwarven machines who love puzzles, you thought.\n\n";

	enum fields { WORD, HINT, NUM_FIELDS };
	const int NUM_WORDS = 5;
	const string WORDS[NUM_WORDS][NUM_FIELDS] = {
		{"wall", "Do you feel like banging your head against these?"},
		{"glasses", "You might see the answer now wearing these."},
		{"arrow", "Flying through the air these things can kill or maim you."},
		{"jumble", "Exactly how these words and your mind may be."},
		{"ogre", "These guys love to rampage and kill men."}
	};
	int choice = (rand() % NUM_WORDS);
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];
	string jumble = theWord;
	int length = jumble.size();
	for (int i = 0;i < length;++i) {
		int index1 = (rand() % length);
		int index2 = (rand() % length);
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	cout << "The voice yelled out, 'The word is spelled " << jumble << " !'\n";
	string guessstr;
	cout << "\n\nYou guessed: ";
	cin >> guessstr;

	while (guessstr.compare(theWord)!=0 && survivors!=0) {
		cout << "The voice yelled 'Incorrect! Die!'\n";
		cout << "A giant spike rose from the floor and impaled one of the adventurers.\n";

		if (survivors == 1) {
			cout << "You gulp as you look around and realize that you are the last one standing.";
		}
		else {
			cout << survivors << " adventurers remain.";
		}

		cout << "\n\nYou guessed: ";
		cin >> guessstr;

		survivors--;
		killed++;
	};

	if (survivors == 0) {
		cout << "The voice boomed one more time and a giant spike impaled you instantly.\n";
		checkDeath(killed, adventurers);
		return 0;
	}

	cout << "The voice boomed 'Correct! You may continue!'\n";
	cout << "With a sigh of relief, the " << survivors << " who remained walked through the gate immediately after it opened.\n";

	// Next part with sphinx and random number generator
	cout << "Entering the cavern, the adventurers saw a giant statue of a sphinx. Suddenly, the sphinx came alive! She opened its mouth and asked them to guess a number she was thinking. For every incorrect guess, one man will be devoured by the sphinx. Seeing no choice but to take the bet, the guessing game began.\n\n";
	cout << "The sphinx grinned and gave a hint that the number will be between 1 and 100. You, " << leader << ", started guessing.\n\n";

	do {
		if (survivors == 1) {
			cout << "You gulp as you realize that you are the last one standing. Praying to the Gods and your lucky rabbit foot, you venture a final guess.\n\n";
		}

		if (survivors == 0) {
			checkDeath(killed, adventurers);
			return 0;
		}

		cout << "There are " << survivors << " adventurers left. ";
		cout << "You guessed: ";
		cin >> guess;
		++tries;

		if (guess > secretNumber) {
			cout << "The sphinx yells too high! Then she proceeds to bite off the head of one of the adventurers. \n\n";
			survivors--;
			killed++;
		}
		else if (guess < secretNumber) {
			cout << "The sphinx yells too low! Then she proceeds to bite off the head of one of the adventurers. \n\n";
			survivors--;
			killed++;
		}
		else {
			cout << "\nThe sphinx frowned and sighed. Shen then thanked you for giving her " << tries << " men and stated she was no longer hungry. \n\n";
			cout << "The remaining " << survivors << " survivors all breathed a huge sigh of relief.\n\n";
		}
	} while (guess != secretNumber);
	
	cout << "The sphinx then gives " << GOLD_PIECES << " gold pieces to everyone still alive.\n\n";
	cout << "You took the extra " << (GOLD_PIECES % survivors) << " as usual.\n\n";

	money += GOLD_PIECES / survivors + GOLD_PIECES % survivors;
	cout << "You now have " << money << " gold pieces in total.\n\n";

	// Next part of journey...


	// cin.get();
	// getchar();
	system("pause");
    return 0;
}