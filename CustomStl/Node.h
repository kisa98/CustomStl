#pragma once

template <typename T>
class LinkedList;

template <typename T>
struct Node
{
	T data;
	LinkedList<Node*>* children;

	Node();
	Node(T value);
	~Node();

	void addChild(Node* node);
	void showChildren();

	Node& operator=(Node* node);
};

