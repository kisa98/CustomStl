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
	T& back();	//	목록의 마지막 요소에 대한 참조를 반환합니다.
	Iterator begin();	//	목록에서 첫 번째 요소의 주소를 지정하는 반복기를 반환합니다.
	Iterator cbegin() const;	//	목록에서 첫 번째 요소의 주소를 지정하는 const 반복기를 반환합니다.
	Iterator cend() const;	//	목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 const 반복기를 반환합니다.
	void clear();	//	목록의 모든 요소를 지웁니다.
	ReverseIterator crbegin() const;	//	역방향 목록에서 첫 번째 요소의 주소를 지정하는 const 반복기를 반환합니다.
	ReverseIterator crend() const;	//	역방향 목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 상수 반복기를 반환합니다.
	bool empty();	//	목록이 비어 있는지 여부를 테스트합니다.
	Iterator end();	//	목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 반복기를 반환합니다.
	Iterator erase(Iterator where) noexcept;	//	목록의 지정된 위치에서 요소를 제거합니다.
	Iterator erase(Iterator first, Iterator last) noexcept;	//	목록의 지정된 위치에서 요소 범위를 제거합니다.
	T& front();	//	목록의 첫 번째 요소에 대한 참조를 반환합니다.
	Iterator insert(Iterator where, const T& value);	//	요소 하나 또는 여러 개나 요소의 범위를 목록의 지정된 위치에 삽입합니다.
	//size_t max_size();	//	목록의 최대 길이를 반환합니다.
	void pop_back();	//	목록의 끝에 있는 요소를 삭제합니다.
	void pop_front();	//	목록의 시작 부분에 있는 요소를 삭제합니다.
	void push_back(T value);	//	목록의 끝에 요소를 추가합니다.
	void push_front(T value);	//	목록의 시작 부분에 요소를 추가합니다.
	ReverseIterator rbegin();	//	역방향 목록에서 첫 번째 요소의 주소를 지정하는 반복기를 반환합니다.
	void remove(const T& value);	//	목록에서 지정된 값과 일치하는 요소를 지웁니다.
	ReverseIterator rend();	//	역방향 목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 반복기를 반환합니다.
	size_t size();	//	목록에 있는 요소 수를 반환합니다.

	T& operator[](size_t index);
	const T& operator[](size_t index) const;

	void print();
private:
	size_t count;
	Node* head;
	Node* tail;
};

