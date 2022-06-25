#ifndef MYSTL_ALGORITHM_H
#define MYSTL_ALGORITHM_H

#include <stdio.h>

namespace mystl_c
{

// 快速排序算法分区
int partition(int *num, int l, int r){
    int pivot = num[l];
    while(l < r){
        while(l < r && num[r] >= pivot)
            r--;
        num[l] = num[r];
        while(l < r && num[l] < pivot)
            l++;
        num[r] = num[l]; 
    }
    num[l] = pivot;
    return l;
}


// 快速排序
void sort(int *num, int l, int r){
    if(l >= r){
        return ;
    }
    int m = partition(num, l, r);
    sort(num, l, m-1);
    sort(num, m+1, r);
}

// 归并排序

void merge(int *num, int l, int r){
    if(l >= r)
        return ;
    int n = r-l+1;
    int temp[n];
    int i = 0, mid = (l+r)/2;
    int f1 = l, f2 = mid+1;
    while(f1 <= mid && f2 <= r){
        if(num[f1] >= num[f2]){
            temp[i++] = num[f2++];
        }
        else{
            temp[i++] = num[f1++];
        }
    }
    while(f1 <= mid)
        temp[i++] = num[f1++];
    while(f2 <= r)
        temp[i++] = num[f2++];
    for(i = 0;i < n;++i){
        num[l++] = temp[i];
    }
}

void merge_sort(int *num, int l, int r){
    if(l >= r)
        return ;
    // int mid = l + ((r - l) >> 1);
    int mid = (l+r)/2;
    // printf("mid:%d\n", mid);
    // return ;
    merge_sort(num, l, mid);
    merge_sort(num, mid+1, r);
    merge(num, l, r);
}



}


#endif // !MYSTL_ALGORITHM_H