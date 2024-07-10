#include <iostream>
#include "Heap.h"

template <typename T>
MaxHeap<T>::MaxHeap() : heap(new T[1]), level(0), size(0), capacity(1) {
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
	delete[] heap;
}

template <typename T>
void MaxHeap<T>::swap(size_t l, size_t r) {
	T temp = heap[r];
	heap[r] = heap[l];
	heap[l] = temp;
}

template <typename T>
void MaxHeap<T>::bubbleUp(size_t index) {
	if (index == 0) return;

	size_t parent = (index - 1) / 2;
	if (heap[index] > heap[parent]) {
		swap(index, parent);
		bubbleUp(parent);
	}
}

template <typename T>
void MaxHeap<T>::bubbleDown(size_t index) {
	size_t lc = index * 2 + 1;
	size_t rc = index * 2 + 2;

	//lc도 크기가 넘을 때 - 리프노드일 때
	if (lc >= capacity) {
		return;
	}

	//lc만 크기가 안넘을 때
	if (lc < capacity && rc >= capacity) {
		if (heap[lc] > heap[index]) {
			swap(index, lc);
		}
	}
	else if (lc < capacity && rc < capacity) {
		if (heap[lc] > heap[index] && heap[rc] < heap[index]) {
			swap(index, lc);
		}
		else if (heap[lc] < heap[index] && heap[rc] > heap[index]) {
			swap(index, rc);
		}
		else if (heap[lc] > heap[index] && heap[rc] > heap[index]) {
			if (heap[lc] < heap[rc]) {
				swap(index, rc);
			}
			else {
				swap(index, lc);
			}
		}
	}
	
}

template <typename T>
void MaxHeap<T>::push(T value) {
	if (size == capacity) {
		resize();
	}
	heap[size] = value;
	bubbleUp(size);
	++size;
}

template <typename T>
T MaxHeap<T>::pop() {
	if (size == 0) {
		throw std::out_of_range("Heap is empty");
	}

	T temp = heap[0];
	heap[0] = heap[--size];

	for (size_t i = 0; i < size; ++i) {
		bubbleDown(i);
	}

	return temp;
}

template <typename T>
T MaxHeap<T>::peek() const {
	if (size == 0) {
		throw std::out_of_range("Heap is empty");
	}
	return heap[0];
}


template <typename T>
size_t MaxHeap<T>::getCapacity() {
	return capacity;
}

template <typename T>
size_t MaxHeap<T>::getSize() {
	return size;
}

template <typename T>
void MaxHeap<T>::print() {
	for (size_t i = 0; i < size; ++i) {
		std::cout << heap[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void MaxHeap<T>::resize() {
	++level;
	size_t size = 1;
	for (size_t i = 0; i < level + 1; ++i) {
		size *= 2;
	}
	--size;
	this->capacity = size;

	T* newHeap = new T[size];
	std::memcpy(newHeap, heap, this->size * sizeof(T));
	delete[] heap;
	heap = newHeap;
}
