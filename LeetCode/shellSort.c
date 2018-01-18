//
//  shellSort.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/28.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "shellSort.h"

void shellSort(int *arr, int numsSize) {
    
    int i, j, increment;
    int tmp;
    
    for (increment=numsSize/2; increment>0; increment/=2) {
        for (i=increment; i<numsSize; i++) {
            tmp = arr[i];
            for(j=i; j>=increment; j-= increment) {
                if (tmp<arr[j-increment]) {
                    arr[j] = arr[j-increment];
                }
                else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
    
}
