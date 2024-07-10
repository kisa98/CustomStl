#pragma once
template <typename T>
class MaxHeap
{
public:
	MaxHeap();
	~MaxHeap();
	void push(T value);
	T pop();
	T peek() const;
	void print();
	void tree();
	size_t getCapacity();
	size_t getSize();
private:
	void bubbleUp(size_t index);
	void bubbleDown(size_t index);
	void swap(size_t indexL, size_t indexR);
	void resize();

	T* heap;
	size_t level;
	size_t capacity;
	size_t size;
};