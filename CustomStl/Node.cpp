#include <iostream>
#include "Node.h"
#include "LinkedList.h"

template <typename T>
Node<T>::Node() : data(nullptr), children(nullptr) {
}

template <typename T>
Node<T>::Node(T value) : data(value), children(new LinkedList<Node<T>*>) {

}

template <typename T>
Node<T>::~Node() {
	delete data;
	delete children;
}

template <typename T>
void Node<T>::addChild(Node* node) {
	children->push_back(node);
}

template <typename T>
void Node<T>::showChildren() {
	if (children != nullptr) {
		if (children->size() == 0) {
			std::cout << "Children is empty" << std::endl;
		}
		else {
			for (auto it = children->begin(); it != children->end(); ++it) {
				std::cout <<(*it)->data << " ";
			}
			std::cout << std::endl;
		}
	}
}

template <typename T>
typename Node<T>::Node& Node<T>::operator=(Node* node) {
	if (data != nullptr) {
		delete data;
	}
	if (children != nullptr) {
		delete children;
	}

	data = node->data;
	children = node->children;

	return this;
}