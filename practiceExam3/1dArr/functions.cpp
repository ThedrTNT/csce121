#include <iostream>
#include "functions.h"

using std::cout, std::endl;

// add function definition here

///s is  a phrase and v is letters to check against
bool isEvenGeneric(char * s, char * v) 	{
	int count = 0;
	for (int i = 0; s[i] != '\0'; ++i) {
		for (int j = 0; v[j] != '\0'; ++j) {
			if (tolower(s[i]) == tolower(v[j])) {
				count++;
			}
		}
	}
	if (count % 2 == 0) {
		return true;
	}
	return false;
}

int main() {
	char s[] = "Some phrase.";
	cout << isEvenGeneric(s, "aeiou") << endl;
	cout << isEvenGeneric(s, "aeiouy") << endl;
	cout << isEvenGeneric(s, "so") << endl; 
}