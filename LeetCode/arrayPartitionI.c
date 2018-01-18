//
//  arrayPartitionI.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/11.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "arrayPartitionI.h"
int cmp(const void *a, const void *b);

int arrayPairSum(int* nums, int numSize) {
    
    qsort(nums, numSize, sizeof(nums[0]), cmp);
    
    int i = 0, result = 0;
    while (i < numSize) {
        result += nums[i];
        i = i + 2;
    }
    return result;
    
}

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


//todo less runtime analyse


