#include <iostream>
#include "Shared_Pointer.h"

template <typename T>
Shared_Pointer<T>::Shared_Pointer() : m_ptr(nullptr), m_refCount(new long(0)) {
}

template <typename T>
Shared_Pointer<T>::Shared_Pointer(T* ptr) : m_ptr(ptr), m_refCount(new long(1)) {
}

//복사 생성자
//복사했으므로, 참조 수를 +1
template <typename T>
Shared_Pointer<T>::Shared_Pointer(const Shared_Pointer& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
	++(*m_refCount);
}

//이동 생성자
//이동 관련된 쉐어드 포인터는 매개변수로 받은 포인터를 현재 포인터로 정보를 '이동'시키고, 매개변수 포인터는 삭제한다.
template <typename T>
Shared_Pointer<T>::Shared_Pointer(Shared_Pointer&& ptr) noexcept {
	if (this != ptr) {
		m_ptr = ptr.m_ptr;
		m_refCount = ptr.m_refCount;
		ptr.m_ptr = nullptr;
		ptr.m_refCount = nullptr;
	}
}


template <typename T>
typename Shared_Pointer<T>::Shared_Pointer& Shared_Pointer<T>::operator=(const Shared_Pointer& ptr) noexcept {
	if (this != &ptr) {
		release();
		m_ptr = ptr.m_ptr;
		++(*m_refCount);
	}
	return *this;
}


template <typename T>
typename Shared_Pointer<T>::Shared_Pointer& Shared_Pointer<T>::operator=(Shared_Pointer&& ptr) noexcept {
	if (this != &ptr) {
		release();
		m_ptr = ptr.m_ptr;
		m_refCount = ptr.m_refCount;
		ptr.m_ptr = nullptr;
		ptr.m_refCount = nullptr;
	}
	return *this;
}


template <typename T>
void Shared_Pointer<T>::reset() noexcept {
	release();
	m_ptr = nullptr;
	m_refCount = new long(0);
}


template <typename T>
void Shared_Pointer<T>::reset(T* ptr) {
	release();
	m_ptr = ptr;
	m_refCount = new long(1);
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
Shared_Pointer<T>::~Shared_Pointer() {
	release();
}

template <typename T>
void Shared_Pointer<T>::release() {
	if (m_refCount == nullptr || --(*m_refCount) == 0) {
		delete m_ptr;
		if(m_refCount != nullptr)
			delete m_refCount;
	}
}

