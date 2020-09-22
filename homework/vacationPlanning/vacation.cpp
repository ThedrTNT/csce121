#include <iostream>
#include <string>
#include <stdexcept>
#include "functions.h"
#include "provided.h"

using std::string;
using std::cin, std::cout, std::endl;
using std::exception;

int main() {
	cout << "Please enter the number of games and the duration: ";
	int numGames;
	cin >> numGames;
	int duration;
	cin >> duration;

	if (numGames > MAX_NB_GAMES || numGames <= 0 || duration > 365 || duration <= 0) {
		cout << "Invalid input." << endl;
		return 0;
	}

	string titleFile;
	cout << "Please enter name of file with titles: ";
	cin >> titleFile;
	string prefsFile;
	cout << "Please enter name of file with preferences: ";
	cin >> prefsFile;
	string planFile;
	cout << "Please enter name of file with plan: ";
	cin >> planFile;

	int start = 0;
	//string gameTitles[MAX_NB_GAMES];
	string* gameTitles = new string[MAX_NB_GAMES];
	try {
		readGameTitles(titleFile, numGames, gameTitles);
	} catch (exception& e) {
		cout << e.what() << endl;
		return 1;
	}
	//int prefs[MAX_NB_GAMES];
	int* prefs = new int[MAX_NB_GAMES];
	try {
		readPrefs(prefsFile, numGames, prefs);
	} catch (exception& e) {
		cout << e.what() << endl;
		return 1;
	}
	//int plan[MAX_NB_GAMES];
	int* plan = new int[MAX_NB_GAMES];
	try {
		readPlan(planFile, plan);
	} catch (exception& e) {
		cout << e.what() << endl;
		return 1;
	}

	try {
		start = findBestVacation(duration, prefs, plan);
	} catch (exception& e) {
		cout << e.what() << endl;
		return 1;
	}

	cout << "Best start day is " << start << endl;
	cout << "Games to be played:" << endl;
	printGamesPlayedInVacation(start, duration, plan, gameTitles, numGames);

	delete[] gameTitles;
	delete[] prefs;
	delete[] plan;
}