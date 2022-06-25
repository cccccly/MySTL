#ifndef MYSTL_ITERATOR_H
#define MYSTL_ITERATOR_H

#include <cstddef>
#include "type_traits.h"

namespace mystl_c
{
// 五种迭代器类型
struct input_iterator_tag {};
struct ouput_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};    

// iterator 模板
template <class Category, class T, class Distance = ptrdiff_t,
    class Pointer = T*, class Reference = T&>
    struct iterator
{
    typedef Category  iterator_category;
    typedef T         value_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Distance  difference_type;
};

} // namespace mystl_c

#endif  // !MYSTL_ITERATOR_H