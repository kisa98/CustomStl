#pragma once

template <typename T>
class Shared_Pointer;

template <typename T>
class Weak_Pointer {
public: 
    constexpr Weak_Pointer() noexcept;
    Weak_Pointer(const Weak_Pointer& wp) noexcept;
    Weak_Pointer(Weak_Pointer&& wp) noexcept;
    Weak_Pointer(const Shared_Pointer<T>& sp) noexcept;
    ~Weak_Pointer();

    bool expired() const noexcept;
    Shared_Pointer<T> lock() const noexcept;

    void reset() noexcept;
    long use_count() const noexcept;

    Weak_Pointer& operator=(const Weak_Pointer& ptr) noexcept;
    Weak_Pointer& operator=(const Shared_Pointer<T>& ptr) noexcept;

    friend class Shared_Pointer<T>;
private:
    T* m_ptr;
    long* m_refCount;
    long* m_weakCount;

    void release();
};