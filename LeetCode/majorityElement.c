//
//  majorityElement.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/20.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "majorityElement.h"

typedef struct CountNode CountNode;
struct CountNode {
    int val;
    int count;
    CountNode *next;
};

int majorityElement(int* nums, int numsSize) {
    
    CountNode *root = malloc(sizeof(CountNode));
    CountNode *pointer = root;
    root->val = nums[0];
    root->count = 1;
    root->next = NULL;
    
    for (int i=1; i<numsSize; i++) {
        
        int exit = 0;
        
        while (pointer->next != NULL) {
            if (nums[i] == pointer->val) {
                pointer->count++;
                exit = 1;
                break;
            }
            else {
                pointer = pointer->next;
            }
        }
        
        if (exit == 0) {
            if (pointer->val == nums[i]) {
                pointer->count++;
            }
            else {
                pointer->next = malloc(sizeof(CountNode));
                pointer->next->val = nums[i];
                pointer->next->count = 1;
                pointer->next->next = NULL;
            }
        }
        
        pointer = root;
    }
    
    while (root != NULL) {
        if (root->count > numsSize/2) {
            break;
        }
        else {
            root = root->next;
        }
    }
    
    return root->val;
}

//leetcode better solution


