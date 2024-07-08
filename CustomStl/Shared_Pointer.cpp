	#include <iostream>
	#include "Shared_Pointer.h"
	#include "Weak_Pointer.h"

	template <typename T>
	Shared_Pointer<T>::Shared_Pointer() : m_ptr(nullptr), m_refCount(nullptr) {
		std::cout << "기본 생성자" << std::endl;
	}

	template <typename T>
	Shared_Pointer<T>::Shared_Pointer(T* ptr) : m_ptr(ptr), m_refCount(new long(1)) {
		std::cout << "인자 생성자" << std::endl;
	}

	//복사 생성자
	//복사했으므로, 참조 수를 +1
	template <typename T>
	Shared_Pointer<T>::Shared_Pointer(const Shared_Pointer& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
		std::cout << "복사 생성자" << std::endl;
		if(m_refCount != nullptr) ++(*m_refCount);
	}

	//이동 생성자
	//이동 관련된 쉐어드 포인터는 매개변수로 받은 포인터를 현재 포인터로 정보를 '이동'시키고, 매개변수 포인터는 삭제한다.
	template <typename T>
	Shared_Pointer<T>::Shared_Pointer(Shared_Pointer&& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
		std::cout << "이동 생성자" << std::endl;
		ptr.m_ptr = nullptr;
		ptr.m_refCount = nullptr;
	}

	template <typename T>
	Shared_Pointer<T>::Shared_Pointer(const Weak_Pointer<T>* wp) : m_ptr(wp->m_ptr), m_refCount(wp->m_refCount) {
		std::cout << "Weak Pointer 생성자" << std::endl;
	}

	template <typename T>
	typename Shared_Pointer<T>::Shared_Pointer& Shared_Pointer<T>::operator=(const Shared_Pointer& ptr) noexcept {
		if (this != &ptr) {
			reset();
			m_ptr = ptr.m_ptr;
			++(*m_refCount);
		}
		return *this;
	}


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

	template <typename T>
	Shared_Pointer<T>::~Shared_Pointer() {
		Release();
	}

	template <typename T>
	void Shared_Pointer<T>::reset() noexcept {
		Release();
		m_ptr = nullptr;
		m_refCount = new long(0);
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
	void Shared_Pointer<T>::Release() {
		if (m_refCount != nullptr) {
			if (--(*m_refCount) == 0) {
				delete m_ptr;
				delete m_refCount;
			}
		}
	}