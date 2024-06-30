#include <iostream>
#include "LinkedList.h"

template <typename T>
LinkedList<T>::Node::Node(T value) : data(value), next(nullptr) { ; }

template <typename T>
LinkedList<T>::LinkedList() : count(0), head(nullptr), tail(nullptr) { ; }

template <typename T>
T& LinkedList<T>::back() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	return tail->data;
}

template <typename T>
const T& LinkedList<T>::back() const {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	return tail->data;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(head);
}


template <typename T>
const typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
	return Iterator(head);
}

template <typename T>
const typename LinkedList<T>::Iterator LinkedList<T>::cbegin() const {
	return Iterator(head);
}


template <typename T>
void LinkedList<T>::clear() {
	while (count > 0) {
		Node* temp = head;
		head = head->next;
		temp->next = nullptr;
		delete temp;

		--count;
	}
	head = nullptr;
	tail = nullptr;
}

template <typename T>
bool LinkedList<T>::empty() {
	return count == 0;
}


template <typename T>
T& LinkedList<T>::front() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

template <typename T>
const T& LinkedList<T>::front() const {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
	return Iterator(nullptr);
}

template <typename T>
const typename LinkedList<T>::Iterator LinkedList<T>::end() const {
	return Iterator(nullptr);
}

template <typename T>
const typename LinkedList<T>::Iterator LinkedList<T>::cend() const {
	return Iterator(nullptr);
}

template <typename T>
void LinkedList<T>::pop_front() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	Node* node = head;
	head = head->next;
	node->next = nullptr;
	delete node;
	--count;
}

template <typename T>
void LinkedList<T>::pop_back() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	Node* node = head;

	if (head == tail) {
		delete head;
		head = tail = nullptr;
	}
	else {
		while (node->next != tail) {
			node = node->next;
		}
		delete tail;
		tail = node;
		node->next = nullptr;
	}
	--count;
}

template <typename T>
void LinkedList<T>::push_back(const T& val) {
	//성능 문제로 인해, 수정할 수 없는 const를 이용한 참조로 값을 넘겨준다.
	++count;
	Node* node = new Node(val);
	if (tail != nullptr) {
		tail->next = node;
	}
	else {
		head = node;
	}

	tail = node;
}

template <typename T>
void LinkedList<T>::push_front(const T& val) {
	//성능 문제로 인해, 수정할 수 없는 const를 이용한 참조로 값을 넘겨준다.
	++count;
	Node* node = new Node(val);
	if (head != nullptr) {
		node->next = head;
	}
	else {
		tail = node;
	}

	head = node;
}

template <typename T>
const size_t LinkedList<T>::size() const {
	return count;
}

//Operator[]
template <typename T>
T& LinkedList<T>::operator[](int index) {
	if (index < 0 || index >= count) {
		throw std::out_of_range("Index out of range");
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i) {
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
const T& LinkedList<T>::operator[](int index) const {
	if (index < 0 || index >= count) {
		throw std::out_of_range("Index out of range");
	}
	Node* temp = head;
	for (int i = 0; i < index; ++i) {
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
void LinkedList<T>::print() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	Node* node = head;
	for (size_t i = 0; i < count; ++i) {
		std::cout << node->data << " ";
		node = node->next;
	}
}

template <typename T>
LinkedList<T>::Iterator::Iterator(Node* node) : current(node) {}

template <typename T>
T& LinkedList<T>::Iterator::operator*() const {
	return current->data;
}

template <typename T>
T* LinkedList<T>::Iterator::operator->() const {
	return &(current->data);
}

template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	++(*this);
	return temp;
}

template <typename T>
bool LinkedList<T>::Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}

template <typename T>
bool LinkedList<T>::Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}