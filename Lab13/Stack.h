#ifndef STACK_H
#define STACK_H

template <class baseType>
class Stack {
 private:
  baseType* A;
  int capacity;
  int length;
 public:  
  Stack() {
  	A = new baseType[1];
  	capacity = 1;
  	length = 0;
  }
  ~Stack() {
  	delete[] A;
  }
  bool isEmpty() {
  	if (length == 0) {
  		return true;
  	}
  	else {
  		return false;
  	}
  }
  void push(baseType element) {
  	if(length + 1 > capacity) {
		baseType* newArr = new baseType[length * 2];
		for (int i = 0; i < length; ++i) {
			newArr[i] = A[i];
		}
		A = newArr;
		capacity = length * 2;

	}
	length++;
	A[length - 1] = element;
  }
  baseType pop() {
  	if(isEmpty()) {
		exit(0);
	}
	length--;
	baseType element = A[length];
	//A[length] = 0;
	return element;
  }
};
#endif
