//
//  moveZeroes.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/18.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "moveZeroes.h"

void moveZeroes(int* nums, int numsSize) {
    int *pointer = nums;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            continue;
        }
        else {
            int tmp = *pointer;
            *pointer = nums[i];
            nums[i] = tmp;
            pointer++;
        }
    }
}
