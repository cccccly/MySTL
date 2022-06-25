#include "../src/algorithm.h"
#include <random>
using namespace mystl_c;

int main(){
    int n = 100;
    int num[n];
    // 测试快速排序
    puts("*************quik_sort***************");
    for(int i = 0;i < n;++i)
        num[i] = rand()%100;
    puts("原数组:");
    for(int i = 0;i < n;++i)
        printf("%d ", num[i]);
    puts("");
    puts("排序后数组:");
    sort(num, 0, n-1);
    for(int i = 0;i < n;++i)
        printf("%d ", num[i]);
    puts("");
    puts("*************quik_sort***************");

    puts("*************merge_sort**************");

    // 测试归并排序
    for(int i = 0;i < n;++i)
        num[i] = rand()%100;
    puts("原数组:");
    for(int i = 0;i < n;++i)
        printf("%d ", num[i]);
    puts("");
    puts("排序后数组:");
    merge_sort(num, 0, n-1);
    for(int i = 0;i < n;++i)
        printf("%d ", num[i]);
    puts("");
    puts("*************merge_sort**************");
    return 0;
}