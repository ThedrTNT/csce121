#include <iostream>
#include <fstream>
#include <string>
#include "censorFunctions.h"

using namespace std;

string replaceString(string word) {
	string replacement;
	for (unsigned int i = 0; i < word.size(); ++i) {
		int num = rand()%10;
		switch (num) {
			case 0: replacement += '!'; break;
			case 1: replacement += '@'; break;
			case 2: replacement += '#'; break;
			case 3: replacement += '$'; break;
			case 4: replacement += '%'; break;
			case 5: replacement += '^'; break;
			case 6: replacement += '&'; break;
			case 7: replacement += '*'; break;
			case 8: replacement += '?'; break;
			case 9: replacement += '~'; break;
		}
	}
	return replacement;
}

string tolower(string word) {
	for (unsigned int i = 0; i <word.size(); ++i) {
		word.at(i) = tolower(word.at(i));
	}
	return word;
}

int loadWords(string words[], ifstream& inFile, int maxCapacity) {
	int index = 0;
	string word;
	while (inFile >> word && index < maxCapacity) {
		words[index] = tolower(word);
		index++;
	}
	return index;
}

void printStrings(string strings[], int size) {
	for (int i = 0; i < size; i++) {
		cout << strings[i] << endl;
	}
}

void processFiles(ifstream& inFile, string censorWords[], int size, ofstream& outfile) {
	while(!inFile.eof()) {
		string line;
		getline(inFile, line);
		string lowerLine = tolower(line);
		for (int i = 0; i < size; ++i) {
			size_t location = lowerLine.find(censorWords[i]);
			while (location != string::npos) {
				line.replace(location, censorWords[i].size(), replaceString(censorWords[i]));
				lowerLine.replace(location, censorWords[i].size(), replaceString(censorWords[i]));
				location = lowerLine.find(censorWords[i]);
			}
		}
		outfile << line << endl;
	}
}