#ifndef MYSTL_ALLOCATOR_H
#define MYSTL_ALLOCATOR_H

namespace mystl_c
{

template <class T>
class allocator
{
public:
    typedef T         value_type;
    typedef T*        pointer;
    typedef const T*  const_pointer;
    typedef T&        reference;
    typedef const T&  const_reference;
    typedef size_t    size_type;
    typedef ptrdiff_t different_type;

public:
    // static修饰让函数可以在类不实例化情况下被调用
    // 分配内存
    static T* allocate();
    static T* allocate(size_type n);
    // 释放内存
    static void deallocate(T* ptr);
    static void deallocate(T* ptr, size_type n);
    // 构造
    static void construct(T* ptr);
    static void construct(T* ptr, const T& value);
    // 析构
    static void destroy(T* ptr);
    static void destroy(T* first, T* last);
};

template <class T>
T* allocator<T>::allocate()
{
    return static_cast<T*>(::operator new(sizeof(T)));
}

template <class T>
T* allocator<T>::allocate(size_type n)
{
    return static_cast<T*>(::operator new(n * sizeof(T)));
}

template <class T>
void allocator<T>::deallocate(T* ptr)
{
    if (ptr == nullptr)
        return;
    ::operator delete(ptr);
}

template <class T>
void allocator<T>::deallocate(T* ptr, size_type)
{
    deallocator(ptr);
}

// template <class T>
// void allocator<T>::construct(T* ptr)
// {
//     ::new ((void*)ptr) T
// }

template <class T>
void 

} // namespace mystl

#endif // !MYSTL_ALLOCATOR_H    