
//  hammingDistance.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/7.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "hammingDistance.h"

struct BinaryNode {
    int bit;
    struct BinaryNode* next;
};

struct BinaryNode* getBinary(int x) {
    struct BinaryNode* node = malloc(sizeof(struct BinaryNode));
    struct BinaryNode* pointer = node;
    int rest = x % 2;
    int divisor = x / 2;
    
    while (x != 0) {
        node->bit = rest;
        x = divisor;
        rest = x % 2;
        divisor = x / 2;
        
        if (x == 0) {
            if (divisor != 0) {
                node->next = malloc(sizeof(struct BinaryNode));
                node = node->next;
                node->bit = divisor;
                node->next = NULL;
            }
            else {
                node->next = NULL;
            }
        }
        else {
            node->next = malloc(sizeof(struct BinaryNode));
            node = node->next;
        }
        
    }
    
    return pointer;
}

int hammingDistance(int x, int y) {
    
    struct BinaryNode* node_x = getBinary(x);
    struct BinaryNode* node_y = getBinary(y);
    
    int result = 0;
    
    while (node_x || node_y) {
        if (!node_x) {
            if (node_y->bit == 1) {
                ++result;
            }
        }
        else if (!node_y) {
            if (node_x->bit == 1) {
                ++result;
            }
        }
        else if (node_x->bit != node_y->bit) {
            ++result;
            
        }
        if (node_x) {
            node_x = node_x->next;
        }
        if (node_y) {
            node_y = node_y->next;
        }
        
    }
    
    return result;
}

//leetcode better solution
int hammingDistance1(int x, int y) {
    int distance = 0;
    for (int i = 0; i < 32; i++) {
        if (x % 2 != y % 2) {
            distance ++;
        }
        x /= 2;
        y /= 2;
    }
    return distance;
}


