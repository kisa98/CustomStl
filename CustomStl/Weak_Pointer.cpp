#include <iostream>
#include "Weak_Pointer.h"
#include "Shared_Pointer.h"

template <typename T>
constexpr Weak_Pointer<T>::Weak_Pointer() noexcept : m_ptr(nullptr), m_refCount(nullptr), m_weakCount(nullptr) {
}

template <typename T>
Weak_Pointer<T>::Weak_Pointer(const Weak_Pointer& wp) noexcept : m_ptr(wp.m_ptr), m_refCount(wp.m_refCount), m_weakCount(wp.m_weakCount) {
	++(*m_weakCount);
}

template <typename T>
Weak_Pointer<T>::Weak_Pointer(Weak_Pointer&& wp) noexcept : m_ptr(wp.m_ptr), m_refCount(wp.m_refCount), m_weakCount(wp.m_weakCount) {
	if (this != wp) {
		wp.m_ptr = nullptr;
		wp.m_refCount = nullptr;
		wp.m_weakCount = nullptr;
	}
}

template <typename T>
Weak_Pointer<T>::Weak_Pointer(const Shared_Pointer<T>& sp) noexcept : m_ptr(sp.m_ptr), m_refCount(sp.m_refCount), m_weakCount(new long(1)) {
	std::cout << "Shared Pointer »ý¼ºÀÚ " << std::endl;
}


template <typename T>
Weak_Pointer<T>::~Weak_Pointer() {
	reset();
}

template <typename T>
bool Weak_Pointer<T>::expired() const noexcept {
	return use_count() == 0;
}



template <typename T>
typename Shared_Pointer<T> Weak_Pointer<T>::lock() const noexcept  {
	return expired() ? Shared_Pointer<T>() : Shared_Pointer<T>(this);
}


template <typename T>
void Weak_Pointer<T>::reset() noexcept {
	if (m_weakCount != nullptr) {
		if (--(*m_weakCount) == 0) {
			delete m_weakCount;
		}
		m_weakCount = nullptr;
	}
	m_ptr = nullptr;
	m_refCount = nullptr;
}

template <typename T>
long Weak_Pointer<T>::use_count() const noexcept {
	std::cout << "m_refCount is " << (m_refCount == nullptr ? "Null" : "Not Null") << std::endl;
	return m_refCount != nullptr ? *m_refCount : 0;
}

template <typename T>
typename Weak_Pointer<T>::Weak_Pointer& Weak_Pointer<T>::operator=(const Weak_Pointer& wp) noexcept {
	reset();
	m_ptr = wp.m_ptr;
	m_refCount = wp.m_refCount;
	m_weakCount = wp.m_weakCount;

	return *this;
}

template <typename T>
typename Weak_Pointer<T>& Weak_Pointer<T>::operator=(const Shared_Pointer<T>& sp) noexcept {
	reset();
	m_ptr = sp.m_ptr;
	m_refCount = sp.m_refCount;
	m_weakCount = new long(1);
}
