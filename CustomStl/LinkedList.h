#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node {
		T data;
		Node* next;
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

		// Comparison operators
		bool operator==(const Iterator& other) const;
		bool operator!=(const Iterator& other) const;
	private:
		Node* current;
	};

	LinkedList();

	T& back();						//����� ������ ��ҿ� ���� ������ ��ȯ�մϴ�.
	const T& back() const;			//����� ������ ��ҿ� ���� ������ ��ȯ�մϴ�.
	Iterator begin();				//��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	const Iterator begin() const;	//��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	const Iterator cbegin() const;	//��Ͽ��� ù ��° ����� �ּҸ� �����ϴ� const �ݺ��⸦ ��ȯ�մϴ�.
	const Iterator cend() const;	//��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� const �ݺ��⸦ ��ȯ�մϴ�.
	void clear();					//����� ��� ��Ҹ� ����ϴ�.
	bool empty();					//����� ��� �ִ��� ���θ� �׽�Ʈ�մϴ�.
	Iterator end();					//��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	const Iterator end() const;		//��Ͽ��� ������ ��� ������ ������ ��ġ�� �ּҸ� �����ϴ� �ݺ��⸦ ��ȯ�մϴ�.
	T& front();						//����� ù ��° ��ҿ� ���� ������ ��ȯ�մϴ�.
	const T& front() const ;		//����� ù ��° ��ҿ� ���� ������ ��ȯ�մϴ�.
	void pop_back();				//����� ���� �ִ� ��Ҹ� �����մϴ�.
	void pop_front();				//����� ���� �κп� �ִ� ��Ҹ� �����մϴ�.
	void push_back(const T& val);	//����� ���� ��Ҹ� �߰��մϴ�.
	void push_front(const T& val);	//����� ���� �κп� ��Ҹ� �߰��մϴ�.
	const size_t size() const ;		//��Ͽ� �ִ� ��� ���� ��ȯ�մϴ�.

	T& operator[](int index);
	const T& operator[](int index) const;

	void print();

private:
	size_t count;
	Node* head;
	Node* tail;
};
