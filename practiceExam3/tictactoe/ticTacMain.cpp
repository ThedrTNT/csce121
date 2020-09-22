# include <iostream >
# include " TicTacToe .h"
using namespace std ;

int main () {
	char again = 'y';
	while (tolower(again) == 'y') {
		int numRows = 0;
		int turnNum = 0;
		/* returns a value from the user and
		* ensures that it is between 3 and 9 */
		numRows = getRows();

		/* TicTacToe class , the constructor creates a
		* numRowsXnumRows array of char on the heap
		* which will have spaces and set to ’X’ and ’O’
		* as the game is played */
		TicTacToe game(numRows);

		do { // play game
			/* prints blanks for empty cells and uses
			* capital ’X’ and ’O’ otherwise */
			game.printBoard();
			turnNum++;
			char curLetter;
			if (turnNum % 2 == 0) {
				curLetter = 'O';
			}
			else {
				curLetter = 'X';
			}
			int row, col;
			/* getMove sets row and col to values from user
			* and ensures valid , available location on the
			* board and uses curLetter to indicate
			* who is entering move */
			game.getMove(row, col, curLetter);
			// curLetter must be ’X’ or ’O’ or ’x’ or ’o’
			game.makeMove(curLetter, row, col);

			// while no winner and not all places are full
		} while (!game.hasWinner() && (turnNum != game.getWidth() * game.getWidth()));

		game.printBoard();
		char winner = game.getWinner();
		/* getWinnerreturns the winning letter or
		* a ’C’ if it is cat (i.e. a tie) */
		if (winner == 'C') {
			cout << "Cat !" << endl;
		}
		else {
			cout << winner << " wins!" << endl;
		}
		cout << "Do you want to play again?" << endl;
		cin >> again;
	} // end of while statement
}