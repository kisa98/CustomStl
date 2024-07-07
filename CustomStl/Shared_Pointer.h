#pragma once

template <typename T>
class Shared_Pointer {
public:
    // Constructors
    Shared_Pointer();
    Shared_Pointer(T* ptr = nullptr);
    Shared_Pointer(const Shared_Pointer& r) noexcept;
    Shared_Pointer(Shared_Pointer&& r) noexcept;
//    Shared_Pointer(const weak_ptr<T>& r); // weak_ptr로부터 생성자

    // Assignment operators
    Shared_Pointer& operator=(const Shared_Pointer& r) noexcept;
    Shared_Pointer& operator=(Shared_Pointer&& r) noexcept;

    // Reset
    void reset() noexcept;
    void reset(T* ptr);

    // Observers
    T* get() const noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    long use_count() const noexcept;
    bool unique() const noexcept;
    operator bool() const noexcept;

    // Destructor
    ~Shared_Pointer();

private:
    T* m_ptr;
    long* m_refCount;

    void release();
};