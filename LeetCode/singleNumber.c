//
//  singleNumber.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/12.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "singleNumber.h"

/** bit manipulation 异或运算^，0^a == a, a^a == 0，所以a^b^a == a^a^b == 0^b == b **/
int singleNumber(int* nums, int numsSize) {
    
    int a = 0;
    for (int i=0; i<numsSize; i++) {
        a ^= nums[i];
    }
    
    return a;
}


/** 递归实现，时间复杂度O(n^2)，空间复杂度O(1) **/
//void fun(int** nums, int numsSize) {
//    int i;
//    int* pointer = *nums;
//    
//    for (i = 1; i < numsSize; i++) {
//
//        if (pointer[i] == INT_MAX) {
//            continue;
//        }
//        if (**nums == INT_MAX) {
//            (*nums)++;
//            fun(nums, numsSize-1);
//            break;
//        }
//        
//        if (**nums == pointer[i]) {
//            pointer[i] = INT_MAX;
//            (*nums)++;
//            fun(nums, numsSize-1);
//            break;
//        }
//    }
//}
//
//int singleNumber(int* nums, int numsSize) {
//    
//    int** pointer = &nums;
//    
//    fun(pointer, numsSize);
//    
//    return **pointer;
//
//}


/** 2∗(a+b+c)−(a+a+b+b+c)=c 但是对于C语言来说时间复杂度为O(n^2) **/
//bool isValueInArray(int val, int *arr, int size) {
//    for (int i=0;i<size;i++) {
//        if (arr[i] == val) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int singleNumber(int* nums, int numsSize) {
//    
//    int numsSum = 0, singleNumsCount = 0, singleNumsSum = 0;
//    int* singleNumsSet = malloc(sizeof(int) * (numsSize/2 + 1));
//    
//    for(int i=0;i<numsSize;i++) {
//        numsSum += nums[i];
//        
//        if (!isValueInArray(nums[i], singleNumsSet, singleNumsCount)) {
//            singleNumsSet[singleNumsCount] = nums[i];
//            singleNumsCount++;
//            singleNumsSum += 2*nums[i];
//        }
//        
//    }
//    
//    
//    return singleNumsSum - numsSum;
//}


