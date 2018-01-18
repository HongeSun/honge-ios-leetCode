//
//  trappingRainWater.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/8.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "trappingRainWater.h"
#include <stdbool.h>

int max (int a, int b) {
    return a > b ? a : b;
}

int min (int a, int b) {
    return a < b ? a : b;
}


//Dynamic Programming
//穷举中，通过迭代反复计算当前元素的左右边最大，但是这个可以被存储
//时间复杂度：O(n)；空间复杂度：O(n)
int trap(int *height, int heightSize) {
//    if (heightSize <= 0) {
//        return 0;
//    }
//
//    int ans = 0;
//    int size = heightSize;
//    int left_max[size];
//    int right_max[size];
//
//    left_max[0] = height[0];
//    for (int i=1; i<size; i++) {
//        left_max[i] = max(height[i], left_max[i-1]);
//    }
//
//    right_max[size-1] = height[size-1];
//    for (int i=size-2; i>=0; i--) {
//        right_max[i] = max(height[i], right_max[i+1]);
//    }
//
//    for (int i=1; i<size-1; i++) {
//        ans += min(left_max[i], right_max[i]) - height[i];
//    }
//
//    return ans;
    
    height[2] = 99;
    return 0;
}


//Brute force， 穷举
//即，计算每个i上面的积水数量 = 包括自己在内的左边最大高度与包含自己在内的右边最大高度的最小值 - 自己的高度；
//时间复杂度：O(n^2); 空间复杂度：O(1)
int trap1(int *height, int heightSize) {
    int ans = 0;
    int size = heightSize;
    for (int i=0; i<size-1; i++) {
        int max_left = 0, max_right = 0;
        for (int j=i; j>=0; j--) {
            max_left = max(max_left, height[j]);
        }
        
        for (int j=i; j<size; j++) {
            max_right = max(max_right, height[j]);
        }
        
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}


//计算每一个高度中的积水数量
bool haveNoZeros(int *nums, int numsSize) {
    for (int i=0; i<numsSize; i++) {
        if(nums[i] > 0) {
            return true;
        }
    }
    
    return false;
}

int trap_self(int *height, int heightSize) {
    
    if (heightSize <= 0) {
        return 0;
    }
    
    int arr[heightSize];
    bool haveNoZero = true;
    int i = 0;
    int count = 0;
    
    while (haveNoZero) {
        if (height[i] >= 2) {
            height[i] --;
            arr[i] = 1;
        }
        else if (height[i] == 1) {
            height[i] = 0;
            arr[i] = 1;
        }
        else {
            height[i] = 0;
            arr[i] = 0;
        }
        
        
        
        if (i < heightSize - 1) {
            i++;
        }
        else {
            
            haveNoZero = haveNoZeros(height, heightSize);
            
            
            int firstOneIndex = 0;
            for (int j=0; j<heightSize; j++) {
                if (arr[j] == 0) {
                    continue;
                }
                else {
                    firstOneIndex = j;
                    break;
                }
            }
            
            int lastOneIndex = heightSize - 1;
            for (int k=heightSize-1; k>=firstOneIndex; k--) {
                if (arr[k] == 0) {
                    continue;
                }
                else {
                    lastOneIndex = k;
                    break;
                }
            }
            
            for (int t=firstOneIndex; t<lastOneIndex;t++) {
                if (arr[t] == 0) {
                    count++;
                }
            }
                
            i = 0;
        }
    }
    
    return count;
    
}



