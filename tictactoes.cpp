// tictactoes.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global constants
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';;

// function prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int high, int low = 0);

char humanPiece();
char opponent(char piece);

void displayBoard(const vector<char>& board);
char winner(const vector<char>& board);
bool isLegal(int move, const vector<char>& board);
int humanMove(const vector<char>& board, char human);
int computerMove(vector<char> board, char computer);

void announceWinner(char winner, char computer, char human);


int main() {
	int move;
	const int NUM_SQUARES = 9;
	vector<char> board(NUM_SQUARES, EMPTY);

	instructions();

	char human = humanPiece();
	char computer = opponent(human);
	char turn = X;

	displayBoard(board);

	while (winner(board) == NO_ONE) {
		if (turn == human) {
			move = humanMove(board, human);
			board[move] = human;
		} else { // computer's turn
			move = computerMove(board, computer); 
			board[move] = computer;
		}
		displayBoard(board); // display the new board
		turn = opponent(turn); // now the opponent's turn
	}

	announceWinner(winner(board), computer, human);
	system("pause");
	return 0;
}

// Functions
void instructions() {
	cout << "Welcome to Tic-Tac-Toe";
	cout << "Make your move by entering a number, 0 - 8\n";
	cout << "corresponds to desired board position, as shown:\n\n";

	cout << " 0 | 1 | 2" << endl;
	cout << " ---------" << endl;
	cout << " 3 | 4 | 5" << endl;
	cout << " ---------" << endl;
	cout << " 6 | 7 | 8" << endl;
}

char askYesNo(string question) {
	char response;
	do {
		cout << question << " (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');
	return response;
}

int askNumber(string question, int high, int low) {
	int number;
	do {
		cout << question << "(" << low << "-" << high << "): ";
		cin >> number;
	} while (number > high || number < low);
	return number;
}

// see who goes first
char humanPiece() {
	char go_first = askYesNo("Do you require the first move?");
	if (go_first == 'y') {
		cout << "\nTake the first move.\n";
		return X;
	}
	else {
		cout << "\nI will go first.\n";
		return O;
	}
}

// gets a piece and returns opponent's piece (either X or O)
char opponent(char piece) {
	if (piece == X) {
		return O;
	}
	else {
		return X;
	}
}

// displays board
void displayBoard(const vector<char>& board) {
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\n";
}

char winner(const vector<char>& board) {
	const int WINNING_ROWS[8][3] = {
		{0, 1, 2}, // top row
		{3, 4, 5}, // middle row
		{6, 7, 8}, // bottom row
		{0, 3, 6}, // left column
		{1, 4, 7}, // middle column
		{2, 5, 8}, // last column
		{0, 4, 8}, // left upper diagonal
		{2, 4, 6} // right upper diagonal
	};

	// now check wheter the actual passed values match any of the winning rows
	const int TOTAL_ROWS = 8;
	for (int row = 0; row < TOTAL_ROWS; ++row) { // loop through each possible winning row
		if ( (board[WINNING_ROWS[row][0]] != EMPTY) && // check that the row doesn't have any blank spaces (EMPTY)
			 (board[WINNING_ROWS[row][0]] == board[WINNING_ROWS[row][1]]) && // check that input vector's index value (for instance X) matches index value (for instance another X) of the second index
			 (board[WINNING_ROWS[row][1]] == board[WINNING_ROWS[row][2]]) ) // repeat number 2 to see if the third number is either a X or O matching the first 2 numbers
		{
			return board[WINNING_ROWS[row][0]];
		}
	}

	// if no player won, check for tie game
	if (count(board.begin(), board.end(), EMPTY) == 0) {
		return TIE;
	}

	// if no one has won and it isn't a tie, the game isn't over so keep looping in the main function
	return NO_ONE;
}

inline bool isLegal(int move, const vector<char>& board) {
	return (board[move] == EMPTY); // if does not equal empty, then return false
}

// asks player for square number to move
int humanMove(const vector<char>& board, char human) {
	int move = askNumber("Where will you move?", (board.size() - 1));
	
	while (!isLegal(move, board)) {
		cout << "\nSquare already occupied.\n";
		move = askNumber("Where will you wish to move?", (board.size() - 1));
	}

	cout << "Fine.\n";
	
	return move;
}

// a bit of artificial intelligence here
// do not pass board by reference since I need to work with and modify a copy of the board
int computerMove(vector<char> board, char computer) {
	unsigned int move = 0;
	bool found = false;

	// I am smart, kind, and cute
	// if no winning move is found...
	// if computer can lose on next move, prevent the human move!
	if (!found) {
		move = 0;
		char human = opponent(computer);
		while (!found && move < board.size()) {
			if (isLegal(move, board)) {
				board[move] = human; // set the particular vector value to be X or O (the human value)
				found = winner(board) == human; // see if now that the value is set to be X or O whether there is a winning row, column, or diagonal
				board[move] = EMPTY; // reset particular value to be empty
			}

			if (!found) { // if not found this time, iterate to next index
				++move;
			}
		}
	}

	// if computer can win on next move, make that move!
	// check through all possible moves for a winning move
	while (!found&&move < board.size()) {
		if (isLegal(move, board)) { // check that the move is legal
			board[move] = computer; // set the index value of the vector board to be either a X or O
			found = winner(board) == computer; // check that a winning row, column, or diagonal exists (if so, set found to be true)
			board[move] == EMPTY; // reset the particular value to be empty
		}

		if (!found) { // if no winning move for this index number, go to next index number and test that one
			++move; 
		}
	}

	// otherwise, take the best remaining open square
	if (!found) {
		move = 0;
		unsigned int i = 0;
		const int BEST_MOVES[] = { 4, 0, 2, 6, 8, 1, 3, 5, 7 };
		// pick best open square
		while (!found && i < board.size()) {
			move = BEST_MOVES[i];
			if (isLegal(move, board)) {
				found = true;
			}
			++i;
		}
	}

	cout << "I shall take square number " << move << endl;
	return move;
}

void announceWinner(char winner, char computer, char human) {
	if (winner == computer) {
		cout << winner << "'s won!\n";
		cout << "You need to practice more.\n";
	}
	else if (winner == human) {
		cout << winner << "'s won!\n";
		cout << "How did I, the computer, lose?\n";
	} else {
		cout << "A tie.\n";
	}
}