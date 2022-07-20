#ifndef MYSTL_SHARED_PTR_H
#define MYSTL_SHARED_PTR_H
#include <utility>
#include <iostream>
namespace mystl_c{

class shared_count {
public:
    shared_count() : count_(1) {

    }

    // 增加计数
    void add_count() {
        ++count_;
    }

    // 减少计数
    long reduce_count() {
        return --count_;
    }

    // 获取当前计数
    long get_count() const {
        return count_;
    }

private:
    long count_;
};


template<typename T>
class shared_ptr {
public:
    explicit shared_ptr(T *ptr = nullptr) noexcept
        : ptr_(ptr) 
    {
        // std::cout<< "ctor" << std::endl;
        shared_count_ = new shared_count();
    }

    // 拷贝构造
    shared_ptr(const shared_ptr& rhs) noexcept;

    // 实现强制类型转换需要的构造函数
    template<typename U>
    shared_ptr(const shared_ptr<U> &other, T *ptr) noexcept {
        ptr_ = ptr;
        if (ptr_) {
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }

    ~shared_ptr() noexcept {
        // 最后一个shared_ptr再去删除对象与共享计数
        // ptr_不为空且此时共享计数减为0的时候,再去删除
        if (!shared_count_->reduce_count()) {
            if(ptr_)
                delete ptr_;
            delete shared_count_;
        }
    }

    T &operator*() const noexcept { return *ptr_; }

    T *operator->() const noexcept { return ptr_; }

    operator bool() const noexcept { return ptr_; }

    T *get() const noexcept { return ptr_; }

    // 带模板的拷贝与移动构造函数 模板的各个实例间并不天然就有 friend 关系，因而不能互访私有成员 ptr_ 和 shared_count_。
    // 需要下面显示声明
    template<typename U>
    friend
    class shared_ptr;

    // template<typename U>
    // shared_ptr(const shared_ptr<U> &other) noexcept {
    //     // std::cout << "调用了带模板的拷贝构造!" << std::endl;
    //     ptr_ = other.ptr_;
    //     if (ptr_) {
    //         other.shared_count_->add_count();
    //         shared_count_ = other.shared_count_;
    //     }
    // }

    template<typename U>
    shared_ptr(shared_ptr<U> &&other) noexcept {
//        cout << "调用了带模板的移动构造!" << endl;
        ptr_ = other.ptr_;
        if (ptr_) {
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
            other.shared_count_ = nullptr;
        }
    }

    // copy by swap 通过pass-by-value生成一个局部rhs，引用计数器+1
    // 然后交换*this和rhs，这样，原来的值变为了局部变量rhs，当rhs结束生命周期时
    // 让原本的lhs引用计数器-1
    shared_ptr &operator=(shared_ptr rhs) noexcept {
        rhs.swap(*this);
        return *this;
    }

    void swap(shared_ptr &rhs) noexcept {
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    long use_count() const noexcept {
        if (ptr_) {
            return shared_count_->get_count();
        } else {
            return 0;
        }
    }

private:
    T *ptr_;
    shared_count *shared_count_;
};

template<typename T>
void swap(shared_ptr<T> &lhs, shared_ptr<T> &rhs) noexcept {
    lhs.swap(rhs);
}

template<typename T>
shared_ptr<T> ::shared_ptr(const shared_ptr& rhs) noexcept
    : ptr_(rhs.ptr_), shared_count_(rhs.shared_count_) 
{
    shared_count_->add_count();
}

template<typename T, typename U>
shared_ptr<T> dynamic_pointer_cast(const shared_ptr<U> &other) noexcept {
    T *ptr = dynamic_cast<T *>(other.get());
    return shared_ptr<T>(other, ptr);
}

template<typename T, typename U>
shared_ptr<T> static_pointer_cast(const shared_ptr<U> &other) noexcept {
    T *ptr = static_cast<T *>(other.get());
    return shared_ptr<T>(other, ptr);
}

template<typename T, typename U>
shared_ptr<T> const_pointer_cast(
        const shared_ptr<U> &other) noexcept {
    T *ptr = const_cast<T *>(other.get());
    return shared_ptr<T>(other, ptr);
}

template<typename T, typename U>
shared_ptr<T> reinterpret_pointer_cast(
        const shared_ptr<U> &other) noexcept {
    T *ptr = reinterpret_cast<T *>(other.get());
    return shared_ptr<T>(other, ptr);
}

} // namespace mystl_c

#endif // !MYSTL_SHARED_PTR_H