#ifndef TICTACTOE_H
#define TICTACTOE_J

class TicTacToe {
	int rows;
	char** board;

public:
	TicTacToe(int);
	TicTacToe(const TicTacToe&);
	TicTacToe operator=(const TicTacToe&);
	~TicTacToe();
	void printBoard();
	void getMove(int, int, char);
	void makeMove(char, int, int);
	bool hasWinner();
	int getWidth();
	char getWinner();




}

TicTacToe::TicTacToe(int rows) {
	this->rows = rows;
	board = new char*[rows];

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < rows; ++j) {
			board[i][j] = ' ';
		}
	}
}

TicTacToe::TicTacToe(const TicTacToe& source) {
	rows = source.rows;
	board = new char*[rows];

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < rows; ++j) {
			board[i][j] = source.board[i][j];
		}
	}
}

TicTacToe& TicTacToe::operator=(const TicTacToe& source) {
	for(int i = 0; i < rows; ++i) {
		delete[] board[i];
	}
	delete[] board;
	rows = source.rows;
	board = new char*[rows];

	for(int i = 0; i < rows; ++i) {
		for(int j = 0; j < rows; ++j) {
			board[i][j] = source.board[i][j];
		}
	}
}

TicTacToe::~TicTacToe() {
	for(int i = 0; i < rows; ++i) {
		delete[] board[i];
	}
	delete[] board;
}

void TicTacToe::printBoard() {
	
}

#endif