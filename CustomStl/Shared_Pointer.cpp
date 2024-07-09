#include <iostream>
#include "Shared_Pointer.h"
#include "Weak_Pointer.h"

template <typename T>
Shared_Pointer<T>::Shared_Pointer() : m_ptr(nullptr), m_refCount(nullptr){
}

template <typename T>
Shared_Pointer<T>::Shared_Pointer(T* ptr) : m_ptr(ptr), m_refCount(new long(1)){
}

//���� ������
//���������Ƿ�, ���� ���� +1
template <typename T>
Shared_Pointer<T>::Shared_Pointer(const Shared_Pointer& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
	if(m_refCount != nullptr) ++(*m_refCount);
}

//�̵� ������
//�̵� ���õ� ����� �����ʹ� �Ű������� ���� �����͸� ���� �����ͷ� ������ '�̵�'��Ű��, �Ű����� �����ʹ� �����Ѵ�.
template <typename T>
Shared_Pointer<T>::Shared_Pointer(Shared_Pointer&& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
	ptr.m_ptr = nullptr;
	ptr.m_refCount = nullptr;
}

template <typename T>
Shared_Pointer<T>::Shared_Pointer(const Weak_Pointer<T>* wp) : m_ptr(wp->m_ptr), m_refCount(wp->m_refCount) {
	if (m_refCount != nullptr) ++(*m_refCount);
}

template <typename T>
typename Shared_Pointer<T>::Shared_Pointer& Shared_Pointer<T>::operator=(const Shared_Pointer& ptr) noexcept {
	if (this != &ptr) {
		reset();
		m_ptr = ptr.m_ptr;
		m_refCount = ptr.m_refCount;
		++(*m_refCount);
	}
	return *this;
}


//RValue ������: 1. ������ �״�� ���, 2. ���� ���� ����(�ð�/������ �̵�), 3. ���� ����
//������ �����ϰ� �ű�� �̵� �Ҵ� ������
template <typename T>
typename Shared_Pointer<T>::Shared_Pointer& Shared_Pointer<T>::operator=(Shared_Pointer&& ptr) noexcept {
	if (this != &ptr) {
		reset();
		m_ptr = ptr.m_ptr;
		m_refCount = ptr.m_refCount;
		ptr.m_ptr = nullptr;
		ptr.m_refCount = nullptr;
	}
	return *this;
}

//�ý��ۿ� ���� �ڿ� ����. ���� ������ ���� 0�̸� �ڿ��� �����Ѵ�.
template <typename T>
Shared_Pointer<T>::~Shared_Pointer() {
	release();
	if (m_refCount != nullptr && *m_refCount == 0) {
		if (m_ptr != nullptr) {
			std::cout << m_ptr << " will be deleted by destructor" << std::endl;
			delete m_ptr;
		}
		delete m_refCount;
	}
	m_ptr = nullptr;
	m_refCount = nullptr;
}

//��������� �ڿ��� ����. ���� ������ ���� 0�̵Ǹ� �ڿ��� �����Ѵ�.
template <typename T>
void Shared_Pointer<T>::reset() noexcept {
	release();
	if (m_refCount != nullptr && *m_refCount == 0) {
		std::cout << m_ptr << " will be deleted by reset" << std::endl;
		delete m_ptr;
	}
	m_ptr = nullptr;
	m_refCount = nullptr;
}

template <typename T>
T* Shared_Pointer<T>::get() const noexcept {
	return m_ptr;
}

template <typename T>
T& Shared_Pointer<T>::operator*() const noexcept {
	return *m_ptr;
}

template <typename T>
T* Shared_Pointer<T>::operator->() const noexcept {
	return m_ptr;
}

template <typename T>
long Shared_Pointer<T>::use_count() const noexcept {
	return m_refCount != nullptr ? *m_refCount : 0;
}

template <typename T>
bool Shared_Pointer<T>::unique() const noexcept {
	return use_count() == 1;
}

template <typename T>
Shared_Pointer<T>::operator bool() const noexcept {
	return m_ptr != nullptr;
}


template <typename T>
void Shared_Pointer<T>::release() {
	if (m_refCount != nullptr) {
		--(*m_refCount);
	}
}
	