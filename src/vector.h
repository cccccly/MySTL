#ifndef MYSTL_VECTOR_H
#define MYSTL_VECTOR_H

#include <initializer_list>
#include <iterator>
// #include "iterator.h"

namespace mystl
{

template <class T>
class vector
{
public:
    // 构造
    vector() 
    { try_init(); }
private:
    std::iterator begin_;
    
};

} // namespace mystl

#endif // !MYSTL_VECTOR_H