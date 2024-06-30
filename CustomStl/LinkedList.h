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

	T& back();						//목록의 마지막 요소에 대한 참조를 반환합니다.
	const T& back() const;			//목록의 마지막 요소에 대한 참조를 반환합니다.
	Iterator begin();				//목록에서 첫 번째 요소의 주소를 지정하는 반복기를 반환합니다.
	const Iterator begin() const;	//목록에서 첫 번째 요소의 주소를 지정하는 반복기를 반환합니다.
	const Iterator cbegin() const;	//목록에서 첫 번째 요소의 주소를 지정하는 const 반복기를 반환합니다.
	const Iterator cend() const;	//목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 const 반복기를 반환합니다.
	void clear();					//목록의 모든 요소를 지웁니다.
	bool empty();					//목록이 비어 있는지 여부를 테스트합니다.
	Iterator end();					//목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 반복기를 반환합니다.
	const Iterator end() const;		//목록에서 마지막 요소 다음에 나오는 위치의 주소를 지정하는 반복기를 반환합니다.
	T& front();						//목록의 첫 번째 요소에 대한 참조를 반환합니다.
	const T& front() const ;		//목록의 첫 번째 요소에 대한 참조를 반환합니다.
	void pop_back();				//목록의 끝에 있는 요소를 삭제합니다.
	void pop_front();				//목록의 시작 부분에 있는 요소를 삭제합니다.
	void push_back(const T& val);	//목록의 끝에 요소를 추가합니다.
	void push_front(const T& val);	//목록의 시작 부분에 요소를 추가합니다.
	const size_t size() const ;		//목록에 있는 요소 수를 반환합니다.

	T& operator[](int index);
	const T& operator[](int index) const;

	void print();

private:
	size_t count;
	Node* head;
	Node* tail;
};
