#include <iostream>
#include <string>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    Stack<string> s;

   	string origString;
   	getline(cin, origString);

   	size_t pos = 0;
   	while ((pos = origString.find(" ")) != string::npos) {
   		s.push(origString.substr(0, pos));
   		origString.erase(0, pos + 1);
   	}
   	pos = origString.find(".");
   	s.push(origString.substr(0,pos));

   	string retString;

   	while (!s.isEmpty()) {
   		retString += s.pop() + " ";
   	}

   	cout << retString << endl;
    
    return 0;
}
