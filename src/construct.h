/*
    构造和析构函数的定义，供allocator调用
*/

#ifndef MYSTL_CONSTRUCT_H
#define MYSTL_CONSTRUCT_H

#include <new>
#include "iterator.h"

namespace mystl_c
{

// construct 构造
// placement new 在ptr上实例Ty()，所以不需要返回
template <class Ty>
void construct(Ty* ptr)
{
    ::new ((void*)ptr) Ty();
}


}

#endif // !MYSTL_CONSTRUCT_H