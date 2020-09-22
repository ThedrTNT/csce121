
///Templated for easy use for ints and doubles
template<typename T>
T listAvg() {
	if (head == nullptr) {
		return nullptr;
	}
	T sum = 0;
	unsigned int size = 1;
	Node<T>* curr = head;
	while (curr != nullptr) {
		sum += curr->data;
		curr = curr->next;
		size++;
	}
	return sum/size;
}

template<typename T>
void reverse() {
	Node<T>* curr = head;
	while(curr->next != nullptr) {
		Node<T>* temp = curr;
		curr = curr->next;
		curr->next = temp;
	}
	head->next = nullptr;
	head = curr;
}

template<typename T>
