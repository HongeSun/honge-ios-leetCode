//
//  hashTable.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/20.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "hashTable.h"

Index Hash(const char *key, int tableSize) {
    unsigned int hashVal = 0;
    while (*key != '\0') {
        hashVal += *key++;
    }
    return hashVal % tableSize;
}
