#include "../src/shared_ptr.h"
// #include <memory>
#include <iostream>

using namespace mystl_c;
using namespace std;


int main() {
    // 测试空指针行为
    {
        shared_ptr<int> ptr1(new int(10));
        shared_ptr<int> ptr2(nullptr);
        ptr2 = ptr1;
        cout<< *ptr1 << " " << *ptr2 << " ";
        cout << ptr1.use_count() << " " << ptr2.use_count() << endl;
    }
    
    // 测试赋值行为
    {
        // int *p1 = new int(10), *p2 = new int(100);
        // shared_ptr<int> ptr1(p1);
        // shared_ptr<int> ptr2(ptr1);

        // shared_ptr<int> ptr3(p2);
        // shared_ptr<int> ptr4(ptr3);
        // cout<< *ptr1 << " " << *ptr2 << " " << *ptr3 << " " << *ptr4 << endl;
        // cout << ptr1.use_count() << " " << ptr2.use_count() << " " << ptr3.use_count() << " " << ptr4.use_count() << endl;

        // // 赋值行为
        // ptr1 = ptr3;
        // cout<< *ptr1 << " " << *ptr2 << " " << *ptr3 << " " << *ptr4 << endl;
        // cout << ptr1.use_count() << " " << ptr2.use_count() << " " << ptr3.use_count() << " " << ptr4.use_count() << endl;

        // 正确行为
        // 10 10 100 100
        // 2 2 2 2
        // 100 10 100 100
        // 3 1 3 3
    }

    return 0;
}