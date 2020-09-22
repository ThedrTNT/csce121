#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "functions.h"

using std::ifstream;
using std::string, std::getline;
using std::cout, std::endl;
using std::runtime_error, std::invalid_argument, std::exception;

void readPrefs(string fileName, int ngames, int prefs[]) {
	ifstream inFile(fileName);
	if(!inFile.is_open()) {
		throw runtime_error("Invalid preferences file.");
	}

	for (int i = 0; i < ngames; i++) {
        prefs[i] = 0;
    }

	int gameID;
	int rating;
	while(!inFile.eof()) {
		inFile >> gameID;
		if (inFile.good()) {
			if (gameID >= 0  && gameID < ngames) {
				int p = 0;
				inFile >> p;
				prefs[gameID] = p;
			} else {
				inFile >> rating;
			}
		} else {
			inFile.clear();
			inFile >> rating;
		}
	}
}

void readPlan(string fileName, int plan[]) {
	ifstream inFile(fileName);
	if(!inFile.is_open()) {
		throw runtime_error("Invalid plan file.");
	}

	for (int i = 0; i < 366; i++) {
        plan[i] = 0;
    }

	int gameID;
	int day;
	while(!inFile.eof()) {
		inFile >> day;
		if (inFile.good()) {
			if (day >= 1  && day <= 365) {
				int p = 0;
				inFile >> p;
				plan[day] = p;
			} else {
				inFile >> gameID;
			}
		} else {
			inFile.clear();
			inFile >> gameID;
		}
	}
}

int computeFunLevel(int start, int duration, int prefs[], int plan[]) {
	if(366 - start < duration || start > 365) {
		//cout << "Time left: " << 365 - start << endl;
		//cout << "Duration: " << duration << endl;
		throw invalid_argument("");
	}
	int funLevel = 0;
	for (int i = start; i < duration + start; ++i) {
		funLevel += prefs[plan[i]];
		//cout << "Start: " << start << " Fun Level:" << funLevel << endl;
	}
	return funLevel;
}

int findBestVacation(int duration, int prefs[], int plan[]) {
	int earliestStart = 0;
	int highestFun = 0;
	int testFun = 0;
	if (duration > 365 || duration < 1) {
		throw invalid_argument("");
	}
	for (int i = 1; i < 367 - duration; ++i) {
		try {
			testFun = computeFunLevel(i, duration, prefs, plan);
			//cout << testFun << endl;
		} catch (exception& e) {
			cout << e.what() << endl;
		}
		//cout << "Start: " << i << " Fun Level:" << testFun << endl;
	
		if (testFun > highestFun) {
			highestFun = testFun;
			earliestStart = i;
		}
	}
	//cout << "Start: " << earliestStart << endl;
	return earliestStart;
}