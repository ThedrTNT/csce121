#include <iostream>
#include "Node.h"
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
	DoublyLinkedList<int> testList(1);
	cout << testList << endl;

	cout << "Pushing to back..." << endl;

	testList.push_back(2);
	cout << testList << endl;

	testList.push_back(43);
	cout << testList << endl;

	cout << "Pushing to front..." << endl;

	testList.push_front(2);
	cout << testList << endl;

	testList.push_front(2);
	cout << testList << endl;

	cout << "Popping front..." << endl;

	while (testList.size() > 0) {
		testList.pop_front();
		cout << testList << endl;
	}

	cout << "Popping back..." << endl;

	testList.pop_back();
	cout << testList << endl;

	/*cout << "Inserting..." << endl;

	testList.insert(69, 0);
	cout << testList.to_str() << endl;

	testList.insert(420, 3);
	cout << testList.to_str() << endl;

	testList.insert(42069, testList.size());
	cout << testList.to_str() << endl;*/

	/*cout << "Erasing..." << endl;
	
	testList.erase(0);
	cout << testList << endl;

	testList.erase(testList.size() - 1);
	cout << testList << endl;

	testList.erase(1);
	cout << testList << endl;*/

	/*cout << "Testing = operator..." << endl;

	DoublyLinkedList<int> testListDefault(1);
	cout << testListDefault << endl;

	testListDefault = testList;
	cout << testListDefault << endl;

	cout << "Testing Copy Constructor..." << endl;

	DoublyLinkedList<int> testListCopyConst(testList);
	testList.clear();
	cout << testListCopyConst << endl;*/

    return 0;
}