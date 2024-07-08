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

//�̵� �Ҵ� ������ : ���� �����͸� ����� ���ο� �����͸� �Ҵ��ϴ� ������.
//&& : RValue ������ : ������ �ڷḦ �������� �ʰ� ���� �״�θ� �����ϴ� ������.
//������ �������� �ʰ� �״�� �������شٴ� ������ ������ ���� ����� �� �ִ�.
//1. �������� �ʰ� �Ű������� ���
//2. �ڷḦ ����
//3. ���� �ڷḦ ����
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