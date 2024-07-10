#pragma once

template <typename T>
class BinarySearchTree
{
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
		Node* parent;
	};
};

