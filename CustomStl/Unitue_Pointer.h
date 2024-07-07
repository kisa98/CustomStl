#pragma once

template <typename T>
class Unique_Pointer {
private:
    T* m_ptr; // 소유한 포인터

public:
    Unique_Pointer();
    explicit Unique_Pointer(T* ptr);
    ~Unique_Pointer();
    Unique_Pointer(Unique_Pointer&& other) noexcept;
    Unique_Pointer& operator=(Unique_Pointer&& other) noexcept;
    T& operator*() const;
    T* operator->() const;
    operator bool() const;
    T* get() const;
    T* release();
    void reset(T* ptr = nullptr);

    Unique_Pointer(const Unique_Pointer&) = delete;
    Unique_Pointer& operator=(const Unique_Pointer&) = delete;
};
