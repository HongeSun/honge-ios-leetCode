//
//  mergeSortedArray.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/19.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "mergeSortedArray.h"

void merge(int* nums1, int m, int* nums2, int n) {
    
    int *pointer = nums2;
    for (int i=0; i< m+n; i++) {
        if(*pointer >= nums1[i] && *pointer <= nums1[i+1]) {
            int tmp = *pointer;
            *pointer = nums1[i+1];
            nums1[i+1] = tmp;
        }
    }
    
}
