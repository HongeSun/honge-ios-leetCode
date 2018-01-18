//
//  insertionSort.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "insertionSort.h"

void insertionSort(int *nums, int numsSize) {
    int j, p;
    int temp;
    for (p=1; p<numsSize; p++) {
        temp = nums[p];
        for (j=p; j>0 && nums[j-1]>temp; j--) {
            nums[j] = nums[j-1];
        }
        nums[j] = temp;
    }
}
