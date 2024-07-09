#include <iostream>
#include "Shared_Pointer.h"
#include "Weak_Pointer.h"

template <typename T>
Shared_Pointer<T>::Shared_Pointer() : m_ptr(nullptr), m_refCount(nullptr){
}

template <typename T>
Shared_Pointer<T>::Shared_Pointer(T* ptr) : m_ptr(ptr), m_refCount(new long(1)){
}

//복사 생성자
//복사했으므로, 참조 수를 +1
template <typename T>
Shared_Pointer<T>::Shared_Pointer(const Shared_Pointer& ptr) noexcept : m_ptr(ptr.m_ptr), m_refCount(ptr.m_refCount) {
	if(m_refCount != nullptr) ++(*m_refCount);
}

//이동 생성자
//이동 관련된 쉐어드 포인터는 매개변수로 받은 포인터를 현재 포인터로 정보를 '이동'시키고, 매개변수 포인터는 삭제한다.
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


//RValue 참조자: 1. 원본을 그대로 사용, 2. 복사 하지 않음(시간/공간적 이득), 3. 재사용 가능
//원본을 삭제하고 옮기는 이동 할당 연산자
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

//시스템에 의해 자원 해제. 참조 포인터 수가 0이면 자원을 해제한다.
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

//명시적으로 자원을 해제. 참조 포인터 수가 0이되면 자원을 해제한다.
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
	