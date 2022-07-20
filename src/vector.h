#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <initializer_list>
// #include <iterator>
#include "iterator.h"
#include "allocator.h"
namespace mystl_c
{

// 模板类: vector
template <class T>
class vector
{
public:
    typedef mystl_c::allocator<T>                    allocator_type;
    typedef mystl_c::allocator<T>                    data_allocator;

    typedef typename allocator_type::value_type      value_type;
    typedef typename allocator_type::pointer         pointer;
    typedef typename allocator_type::const_pointer   const_pointer;
    typedef typename allocator_type::reference       reference;
    typedef typename allocator_type::const_reference const_reference;
    typedef typename allocator_type::size_type       size_type;
    typedef typename allocator_type::difference_type difference_type;

    typedef value_type*                              iterator;
    typedef const value_type*                        const_iterator;

public:
    // 构造
    vector() { 
        try_init(); 
    }

    // 析构
    ~vector() {
        
    }
private:
    iterator begin_;  // 所占空间头部 == 所用空间头部
    iterator end_;    // 所用空间尾部
    iterator cap_;    // 所占空间尾部

private:
    // 帮助函数

    // 初始化
    void try_init();
    
    // 销毁
    void destroy_and_recover(iterator first, iterator last, size_type n);
};

// 初始化函数，分配存储空间，初始化3根指针
template <class T>
void vector<T>::try_init()
{
    try{
        begin_ = data_allocator::allocate(16);
        end_ = begin_;
        cap_ = begin_+16;
    }
    catch (...){
        begin_ = end_ = cap_ = nullptr;
    }
}

// 销毁函数，销毁
template <class T>
void vector<T>::destroy_and_recover(iterator first, iterator last, size_type n)
{
    data_allocator::destroy(first, last);
    data_allocator::deallocate(first, n);
}

} // namespace mystl_c

#endif // !MYSTL_VECTOR_H