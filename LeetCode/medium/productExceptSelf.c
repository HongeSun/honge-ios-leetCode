//
//  productExceptSelf.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "productExceptSelf.h"

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
//    *returnSize = numsSize;
    
    int *returnArr = calloc(numsSize, sizeof(int));
    
    returnArr[0] = 1;
    for (int i=1; i<numsSize; i++) {
        returnArr[i] = returnArr[i-1] * nums[i-1];
    }
    int right = 1;
    for (int i=numsSize-1; i>=0; i--) {
        returnArr[i] *= right;
        right *= nums[i];
    }
    
    return returnArr;
}
