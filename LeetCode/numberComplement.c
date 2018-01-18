//
//  numberComplement.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/11.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "numberComplement.h"

struct BinaryNode {
    int bit;
    struct BinaryNode* next;
};

struct BinaryNode* getBinaryFromInt(int x) {
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

int getIntFromBinary(struct BinaryNode* node) {
    int result = 0, i = 0;
    while (node) {
        result += node->bit * pow(2, i);
        ++i;
        node = node->next;
    }
    return result;
}

int findComplement(int num) {
    
    struct BinaryNode* node = getBinaryFromInt(num);
    
    struct BinaryNode* node_complementary = malloc(sizeof(struct BinaryNode));
    struct BinaryNode* pointer = node_complementary;
    
    while (node) {
        node_complementary->bit = node->bit == 0 ? 1 : 0;
        node = node->next;
        
        if (!node) {
            node_complementary->next = NULL;
        }
        else {
            node_complementary->next = malloc(sizeof(struct BinaryNode));
            node_complementary = node_complementary->next;
        }
    }

    return getIntFromBinary(pointer);
}


//leetcode better solution
int findComplement1(int num) {
    num = ~num;
    int flag = 1 << 31;
    while (num & flag) {
        num &= (~flag);
        flag = flag >> 1;
    }
    return num;
}
