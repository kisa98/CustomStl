#include "DoublyLinkedList.h"
#include <iostream>

template <typename T>
DoublyLinkedList<T>::Node::Node(T value) : data(value), prev(nullptr), next(nullptr) {}

template <typename T>
DoublyLinkedList<T>::Iterator::Iterator(Node* node) : current(node) {}

template <typename T>
T& DoublyLinkedList<T>::Iterator::operator*() const {
	return current->data;
}

template <typename T>
T* DoublyLinkedList<T>::Iterator::operator->() const {
	return &(current->data);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++() {
	current = current->next;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator++(int) {
	Iterator temp = *this;
	++(*this);
	return temp;
}


template <typename T>
typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator--() {
	current = current->prev;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::Iterator::operator--(int) {
	Iterator temp = *this;
	--(*this);
	return temp;
}

template <typename T>
bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const {
	return current == other.current;
}
template <typename T>
bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
	return current != other.current;
}


template <typename T>
DoublyLinkedList<T>::ReverseIterator::ReverseIterator(Node* node) : current(node) {}

template <typename T>
T& DoublyLinkedList<T>::ReverseIterator::operator*() const {
	return current->data;
}

template <typename T>
T* DoublyLinkedList<T>::ReverseIterator::operator->() const {
	return &(current->data);
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator& DoublyLinkedList<T>::ReverseIterator::operator++() {
	current = current->prev;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::ReverseIterator::operator++(int) {
	Iterator temp = *this;
	++(*this);
	return temp;
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator& DoublyLinkedList<T>::ReverseIterator::operator--() {
	current = current.next;
	return *this;
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::ReverseIterator::operator--(int) {
	Iterator temp = *this;
	--(*this);
	return temp;
}

template <typename T>
bool DoublyLinkedList<T>::ReverseIterator::operator==(const ReverseIterator& other) const {
	return current == other.current;
}
template <typename T>
bool DoublyLinkedList<T>::ReverseIterator::operator!=(const ReverseIterator& other) const {
	return current != other.current;
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : count(0), head(nullptr), tail(nullptr) {}


template <typename T>
void DoublyLinkedList<T>::advance(Iterator& it, int distance) {
	if (distance > 0) {
		for (int i = 0; i < distance; ++i) {
			if (it.current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			++it;
		}
	}
	else if (distance < 0) {
		for (int i = 0; i < -distance; ++i) {
			if (it.current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			--it;
		}
	}
}

template <typename T>
void DoublyLinkedList<T>::advance(ReverseIterator& it, int distance) {
	if (distance > 0) {
		for (int i = 0; i < distance; ++i) {
			if (it.current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			--it;
		}
	}
	else if (distance < 0) {
		for (int i = 0; i < -distance; ++i) {
			if (it.current == nullptr) {
				throw std::out_of_range("Iterator out of range");
			}
			++it;
		}
	}
}

template <typename T>
T& DoublyLinkedList<T>::back() {
	if (count == 0) {
		throw std::out_of_range("List is empty.");
	}
	return tail->data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin() {
	return Iterator(head);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::cbegin() const {
	return Iterator(head);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::cend() const {
	return Iterator(nullptr);
}

template <typename T>
void DoublyLinkedList<T>::clear() {
	while (count > 0) {
		pop_back();
	}
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::crbegin() const {
	return ReverseIterator(tail);
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::crend() const {
	return ReverseIterator(nullptr);
}

template <typename T>
bool DoublyLinkedList<T>::empty() {
	return count == 0;
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::rbegin() {
	return ReverseIterator(tail);
}

template <typename T>
typename DoublyLinkedList<T>::ReverseIterator DoublyLinkedList<T>::rend() {
	return ReverseIterator(nullptr);
}


template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end() {
	return Iterator(nullptr);
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::erase(Iterator where) noexcept {
	Node* temp = where.current;
	if (temp == nullptr) {
		return temp;
	}

	++where;
	if (temp->prev != nullptr) {
		temp->prev->next = temp->next;
	} else {
		head = temp->next;
	}

	if (temp->next != nullptr) {
		temp->next->prev = temp->prev;
	} else {
		tail = temp->prev;
	}

	delete temp;
	--count;
	return where;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::erase(Iterator first, Iterator last) noexcept {
    while (first != last) {
        first = erase(first);
    }
    return last;
}

template <typename T>
T& DoublyLinkedList<T>::front() {
	if (count == 0) {
		throw std::out_of_range("List is empty.");
	}
	return head->data;
}

template <typename T>
typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::insert(Iterator where, const T& value) {
	Node* node = new Node(value);
	++count;
	if (where.current == nullptr) {
		if (head == tail) {
			head = node;
			tail = node;

			return begin();
		}
		else {
			tail->next = node;
			node->prev = tail;

			tail = node;
			return Iterator(tail);
		}
	}
	else {
		where.current->prev->next = node;
		node->prev = where.current->prev;

		node->next = where.current;
		where.current->prev = node;
		return where;
	}
}

template <typename T>
void DoublyLinkedList<T>::pop_back() {
	if (tail == nullptr) {
		throw std::out_of_range("List is empty.");
	}
	
	Node* temp = tail;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		tail = tail->prev;
		tail->next = nullptr;
	}
	--count;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::pop_front() {
	if (head == nullptr) {
		throw std::out_of_range("List is empty.");
	}

	Node* temp = head;
	if (head == tail) {
		head = tail = nullptr;
	}
	else {
		head = head->next;
		head->prev = nullptr;
	}
	--count;
	delete temp;
}

template <typename T>
void DoublyLinkedList<T>::push_back(T value) {
	Node* node = new Node(value);
	if (tail == nullptr) {
		head = node;
		tail = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	++count;
}

template <typename T>
void DoublyLinkedList<T>::push_front(T value) {
	Node* node = new Node(value);
	if (head == nullptr) {
		head = node;
		tail = node;
	}
	else {
		head->prev = node;
		node->next = head;
		head = node;
	}
	++count;
}


template <typename T>
void DoublyLinkedList<T>::remove(const T& value) {
	auto it = begin();
	while (it != end()) {
		if ((*it) == value) {
			it = erase(it);
		}
		else {
			++it;
		}
	}
}

template <typename T>
size_t DoublyLinkedList<T>::size() {
	return count;
}


template <typename T>
void DoublyLinkedList<T>::print() {
	if (count == 0) {
		throw std::out_of_range("List is empty");
	}
	Node* node = head;
	for (size_t i = 0; i < count; ++i) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}


template <typename T>
T& DoublyLinkedList<T>::operator[](size_t index) {
	if (index >= count) {
		throw std::out_of_range("Index is out of range.");
	}
	Node* temp = head;
	for (size_t i = 0; i < index; ++i) {
		temp = temp->next;
	}
	return temp->data;
}

template <typename T>
const T& DoublyLinkedList<T>::operator[](size_t index) const {
	if (index >= count) {
		throw std::out_of_range("Index is out of range.");
	}
	Node* temp = head;
	for (size_t i = 0; i < index; ++i) {
		temp = temp->next;
	}
	return temp->data;
}