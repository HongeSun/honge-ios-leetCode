//
//  topKFrequent.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "topKFrequent.h"
//hash table, heap



int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    
    int count = 0;
    
    for (int i=0; i<numsSize; i++) {
        if (count < nums[i]) {
            count = nums[i];
        }
        else {
            break;
        }
    }
    
    int *arr = calloc(count, sizeof(int));
    for (int i=0; i<numsSize; i++) {
        arr[nums[i]] += 1;
    }
    
    int *returnArr = calloc(k, sizeof(int));
    for (int i=0; i<count; i++) {
        
    }
    return nums;
}

//run time error
int* topKFrequent1(int* nums, int numsSize, int k, int* returnSize) {
//    *returnSize = k;
    int *returnArr = calloc(k, sizeof(int));
    
    returnArr[0] = nums[0];
    int j = 0;
    for (int i=1; i<numsSize; i++) {
        
        if (nums[i] == returnArr[j]) {
            continue;
        }
        else {
            if (j<k) {
                returnArr[++j] = nums[i];
            }
            else {
                break;
            }
        }
    }

    return returnArr;
}
