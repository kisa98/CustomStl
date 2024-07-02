#pragma once

template <typename T>
class DoublyLinkedList
{
public:
	struct Node {
		T data;
		Node* next;
		Node* prev;
		Node(T value);
	};

	class Iterator {
	public:
		Iterator(Node* node = nullptr);

		T& operator*() const;
		T* operator->() const;


		// Increment operators
		Iterator& operator++();
		Iterator operator++(int);
		Iterator& operator--();
		Iterator operator--(int);

		// Comparison operators
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
		
		Node* current;
	};

	class ReverseIterator {
	public:
		ReverseIterator(Node* node = nullptr);

		T& operator*() const;
		T* operator->() const;


		// Increment operators
		ReverseIterator& operator++();
		ReverseIterator operator++(int);
		ReverseIterator& operator--();
		ReverseIterator operator--(int);

		// Comparison operators
		bool operator==(const ReverseIterator& other) const;
		bool operator!=(const ReverseIterator& other) const;

		Node* current;
	};
	DoublyLinkedList();

	void advance(Iterator& it, int distance);
	void advance(ReverseIterator& it, int distance);
	T& back();	//	����� ������ ��ҿ� ���� ������ ��ȯ�մϴ�.
	Iterator begin();	//	��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	Iterator cbegin() const;	//	��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� const �ݺ��⸦ ��ȯ�մϴ�.
	Iterator cend() const;	//	��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� const �ݺ��⸦ ��ȯ�մϴ�.
	void clear();	//	����� ��� ��Ҹ� ����ϴ�.
	ReverseIterator crbegin() const;	//	������ ��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� const �ݺ��⸦ ��ȯ�մϴ�.
	ReverseIterator crend() const;	//	������ ��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� ��� �ݺ��⸦ ��ȯ�մϴ�.
	bool empty();	//	����� ��� �ִ��� ���θ� �׽�Ʈ�մϴ�.
	Iterator end();	//	��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	Iterator erase(Iterator where) noexcept;	//	����� ������ ��ġ���� ��Ҹ� �����մϴ�.
	Iterator erase(Iterator first, Iterator last) noexcept;	//	����� ������ ��ġ���� ��� ������ �����մϴ�.
	T& front();	//	����� ù ��° ��ҿ� ���� ������ ��ȯ�մϴ�.
	Iterator insert(Iterator where, const T& value);	//	��� �ϳ� �Ǵ� ���� ���� ����� ������ ����� ������ ��ġ�� �����մϴ�.
	//size_t max_size();	//	����� �ִ� ���̸� ��ȯ�մϴ�.
	void pop_back();	//	����� ���� �ִ� ��Ҹ� �����մϴ�.
	void pop_front();	//	����� ���� �κп� �ִ� ��Ҹ� �����մϴ�.
	void push_back(T value);	//	����� ���� ��Ҹ� �߰��մϴ�.
	void push_front(T value);	//	����� ���� �κп� ��Ҹ� �߰��մϴ�.
	ReverseIterator rbegin();	//	������ ��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	void remove(const T& value);	//	��Ͽ��� ������ ���� ��ġ�ϴ� ��Ҹ� ����ϴ�.
	ReverseIterator rend();	//	������ ��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	size_t size();	//	��Ͽ� �ִ� ��� ���� ��ȯ�մϴ�.

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	void print();
private:
	size_t count;
	Node* head;
	Node* tail;
};

