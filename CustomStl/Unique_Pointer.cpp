#include <iostream>
#include "Unique_Pointer.h"

template <typename T>
Unique_Pointer<T>::Unique_Pointer() : m_ptr(nullptr) {}

template <typename T>
Unique_Pointer<T>::Unique_Pointer(T* ptr) : m_ptr(ptr) {
	std::cout << "Constructed" << std::endl;
};

template <typename T>
Unique_Pointer<T>::~Unique_Pointer() {
	delete m_ptr;
}

template <typename T>
Unique_Pointer<T>::Unique_Pointer(Unique_Pointer&& other) noexcept : m_ptr(other.m_ptr) {
	other.m_ptr = nullptr;
}

//이동 할당 연산자 : 현재 포인터를 지우고 새로운 포인터를 할당하는 연산자.
//&& : RValue 참조자 : 원래의 자료를 복사하지 않고 원본 그대로를 참조하는 연산자.
//원본을 복사하지 않고 그대로 가져다준다는 점에서 다음과 같이 사용할 수 있다.
//1. 복사하지 않고 매개변수료 사용
//2. 자료를 재사용
//3. 원본 자료를 수정
template <typename T>
typename Unique_Pointer<T>::Unique_Pointer& Unique_Pointer<T>::operator=(Unique_Pointer&& other) noexcept {
	if (this != &other) {
		delete m_ptr;
		m_ptr = other.m_ptr;
		other.m_ptr = nullptr;
	}
	return *this;
}

template <typename T>
T& Unique_Pointer<T>::operator*() const {
	return *m_ptr;
}

template <typename T>
T* Unique_Pointer<T>::operator->() const {
	return m_ptr;
}

template <typename T>
Unique_Pointer<T>::operator bool() const {
	return m_ptr != nullptr;
}


template <typename T>
T* Unique_Pointer<T>::get() const {
	return m_ptr;
}

template <typename T>
T* Unique_Pointer<T>::release() {
	T* temp = m_ptr;
	m_ptr = nullptr;
	return temp;
}

template <typename T>
void Unique_Pointer<T>::reset(T* ptr) {
	delete m_ptr;
	m_ptr = ptr;
}