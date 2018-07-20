// lost_fortune.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// FUNCTIONS
bool checkDeath(int killed, int adventurers) {
	if (killed == adventurers) {
		cout << "Everyone has died!" << endl;
		system("pause");
		return 0;
	}
}

/* ONLY FOR ARRAY
void displayInventory(int numItems, string inventory[]) {
	for (int i = 0; i < numItems; ++i) {
		cout << i+1 << ". ";
		cout << inventory[i] << endl;
	}
}
*/

void displayInventory(vector<string> inventory) {
	if (inventory.empty()) {
		cout << "You have nothing at all except the clothes on your back and your boots. Hopefully, your sanity as well.\n";
	}
	else {
		for (unsigned int i = 0; i < inventory.size(); ++i) {
			cout << i << ". ";
			cout << inventory[i] << endl;
		}
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
	// CONSTANTS & VARIABLES
	int adventurers, killed, survivors, choicenum;
	int adventurercost = 100;
	string leader;
	const int GOLD_PIECES = 900;
	int money = 1000;

	const int MAX_ITEMS = 10;
	/* DOn't use the following. Arrays suck. Use vector.
	string inventory[MAX_ITEMS];
	int numItems = 0;
	inventory[numItems++] = "steel short sword";
	inventory[numItems++] = "fine leather armor";
	inventory[numItems++] = "steel dagger";
	*/

	// hero's inventory with starting items
	vector<string> inventory;
	inventory.push_back("steel short sword");
	inventory.push_back("fine leather armor");
	inventory.push_back("steel dagger");

	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = { {'0', 'X', '0'}, {' ', 'X', 'X'}, {'X','O','O'} };

	// if random number generator here is not used, it will output the same sequence of random numbers every time it is run.
	srand(static_cast<unsigned int>(time(0))); // seed random number generator
	int secretNumber = rand() % 100 + 1;
	int tries = 0;
	int guess;

	// SHOW HIGH SCORES
	cout << "Welcome to Lost Fortune " << string(3, '!') << " \n";
	cout << "***********************\n\n";
	
	// START GAME
	cout << "Do you wish to start a new game?\n";
	cout << "1. Yes.\n";
	cout << "2. No, I want to quit the game.\n";
	cout << "3. No, load me a previously saved game.\n";
	cout << "4. No, I want to look at high scores.\n";
	cin >> choicenum;
	if (choicenum == 2) {
		return 0;
	} 
	
	if(choicenum == 3) {
		cout << "No saved game found. Let's start with a new game!\n";
	}
	
	if (choicenum == 4) {
		vector<int>::const_iterator iter;
		vector<int> scores;
		scores.push_back(1500);
		scores.push_back(2500);
		scores.push_back(4500);
		
		cout << "\nHigh Scores:\n";
		for (iter = scores.begin(); iter != scores.end(); ++iter) {
			cout << *iter << endl;
		}

		int score;
		cout << "\nEnter a score to find: ";
		cin >> score;

		iter = find(scores.begin(), scores.end(), score);
		if (iter != scores.end()) {
			cout << "Scores found.\n";
		}
		else {
			cout << "Scores not found.\n";
		}

		cout << "\nRandomizing scores.";
		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(scores.begin(), scores.end());
		cout << "\nHigh Scores:\n";
		for (iter = scores.begin(); iter != scores.end(); ++iter) {
			cout << *iter << endl;
		}

		cout << "\nSorting scores.";
		sort(scores.begin(), scores.end());
		cout << "\nHigh Scores:\n";
		for (iter = scores.begin(); iter != scores.end(); ++iter) {
			cout << *iter << endl;
		}

		system("pause");
	}

	// SETUP GAME
	cout << "What is your name, dear esteemed player?\n";
	cin >> leader;

	cout << "Would you like to play hangman as a bonus to your stats? Warning! If you lose, your stats drop by 1 point for each attribute.\n";
	cout << "1. Yes. I will take the risk! \n";
	cout << "2. No. I want to play it safe.\n";
	cin >> choicenum;
	if (choicenum == 1) { // play hangman
		// SETUP
		const int MAX_WRONG = 8;
		vector<string> words;
		words.push_back("SERAPH");
		words.push_back("SYMBIOSIS");
		words.push_back("SYZYGY");
		words.push_back("GERMANE");
		words.push_back("RELEVANT");
		words.push_back("PANACEA");
		words.push_back("SERENDIPITY");
		words.push_back("METALHEAD");
		words.push_back("VOID");

		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());
		const string THE_WORD = words[0];
		int wrong = 0;
		string soFar(THE_WORD.size(), '-');
		string used = "";

		// main loop
		while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
			cout << "\n\nYou have " << (MAX_WRONG - wrong);
			cout << " incorrect guesses left.\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << soFar << endl;

			char guess;
			cout << "\n\nEnter a letter from a to z for your guess: ";
			cin >> guess;
			guess = toupper(guess);
			while (used.find(guess) != string::npos) { // if word is not NOT FOUND in already guessed string
				cout << "Try another letter. You've already guessed " << guess << endl;
				cout << "Enter your next guess: ";
				cin >> guess;
				guess = toupper(guess);
			}
			
			used += guess;

			if (THE_WORD.find(guess) != string::npos) { // if the word is not NOT FOUND. Better to use npos instead of -1 since code is more readable)
				cout << "That is right! " << guess << " is in the word.\n";
				for (int i = 0; i < THE_WORD.length(); i++) {
					if (THE_WORD[i] == guess) {
						soFar[i] = guess;
					}
				}
			}
			else {
				cout << "Sorry, " << guess << " isn't in the word.\n";
				++wrong;
			}
		}

		// shutdown
		if (wrong >= MAX_WRONG) {
			cout << "\nTime for your punishment! All stats reduced by 1.";
		}
		else {
			cout << "\nTime for your reward. All stats increased by 1.";
		}
		return 0;
	}

	// display starting stats
	cout << "Your current stats: \n";
	cout << "Health: \n";
	cout << "Agility: \n";
	cout << "Intelligence: \n";
	cout << "Leadership: \n";
	cout << "Luck: \n";

	cout << "You open your eyes and look to the pillow next to you. Relieved to see that your money pouch with " << money << " pieces of gold still there next to you, you look around the room.";
	cout << "On the floor, you see your shoes, cloak, clothes and a few more useful items for adventuring: \n";
	displayInventory(inventory);

	cout << "\nAfter you washed up yourself, you went downstairs and had a hearty breakfast. The meaty adventurer from yesterday who has wanted to buy some of your things is still there loudly belching and drinking beer. He looked disgusting but he does have some money which you really need. You ponder on whether you want to sell anything. \n";
	cout << "1. Sell.\n";
	cout << "2. Don't sell.\n";
	cin >> choicenum;

	if (choicenum == 1) {
		cout << "You approach the meathead slowly and he raises his head to look at you. 'What do you want?' he growled.\n";
		cout << "'You still want some of my stuff?' you asked ignoring another belch that followed after his rude question.\n";
		cout << "He waved his hand impatiently waiting for you to continue. You look at your inventory and decide to sell:\n";
		displayInventory(inventory);
		cin >> choicenum;
		int worth = 300;
		cout << "'How about the " << inventory[choicenum] << " for " << worth << " gold pieces?' you asked.\n";
		cout << "'Too high!' he said. 'I will take it for 100 less.'\n";
		cout << "'That is highway robbery!' you exclaimed.\n";
		cout << "'Too bad. Take it or scram,' he said with a scowl.\n";
		cout << "You decide to: \n";
		cout << "1. Sell it anyway. You need the money.\n";
		cout << "2. Walk away.\n";
		cin >> choicenum;
		if (choicenum == 1) {
			cout << "'Nice doing business with ya,' the man said with a wicked grin. \n";
			cout << "You pocket the " << worth - 100 << " gold pieces he gives you and leave.\n";
			inventory.erase(inventory.begin() + choicenum);
			money += worth;
			cout << "You now have " << money << " gold pieces. You currently possess: \n";
			displayInventory(inventory);
		}
		else {
			cout << "He gave you a scowl as you walked away without a word.\n";
		}
	}

	cout << "Hiring some adventurers sounds like a good idea. You see a sign posting outside of the inn that says each newbie adventurer costs " << adventurercost << " gold pieces to hire.";
	cout << " Entering the adventurer's guild, you decide to hire a few. How many adventurers do you wish to hire?\n";
	cin >> adventurers;

	// hire 3 at a minimum
	if (adventurers == 0) {
		cout << "Hiring no one sounds very risky. You decide to hire three adventurers.";
		adventurers = 3;
	}

	// if more money than you can afford, then set to max number of people you bought and set money to 0
	if (adventurercost * adventurers > money) {
		cout << "You realize that you don't have enough money to hire this many people so you decide to hire as many as you can.";
		adventurers = (money / adventurercost);
		cout << " You hired " << adventurers << " people.";
	}
	// reduce money
	money -= adventurercost * adventurers;
	cout << "You have " << money << " gold pieces left.";
	adventurers++; // include yourself here from now on

	// Start the story
	cout << "\nYour intrepid group of " << adventurers << " including yourself sets out for the epic adventure";
	cout << " -- in search of the lost treasure in the mountain dwellings of the now extinct ancient dwarves. ";
	cout << "The group was led by you, that legendary rogue named " << leader << ".\n\n";
	cout << "These are the thoughts that go through your head. Unfortunately, reality proves to be a far cry. Your crew is already grumbling about your slow pace.";

	// Thief
	cout << "More trouble was to follow. Before you even reached the mountains, an adventurer decided to lighten your load a bit. ";
	cout << " Considering that your leadership is already under jeopardy, you decided to ignore it.\n";
	inventory.pop_back();
	cout << " You currently possess: \n";
	displayInventory(inventory);

	// Ogre attack
	killed = rand() % adventurers + 1;
	survivors = adventurers - killed;

	cout << "\nOutside of the mountain entrance, a band of marauding ogres ambushed the party. The adventurers won but " << killed << " were killed.\n\n";

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
		displayInventory(inventory);
		cin >> choicenum;

		if (choicenum < inventory.size() && choicenum > 0) {
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
	cout << "You take the " << inventory[0] << " back and led the way into the cavern.";

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