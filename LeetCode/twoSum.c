//
//  twoSum.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/7.
//  Copyright © 2017年 lagou. All rights reserved.
//
#include "twoSum.h"

//int* twoSum(int *nums, int numsSize, int target) {
//    
//    int index = 0;
//    int* res = malloc(2 * sizeof(int));
//    
//    for (int j=1;j<numsSize;j++) {
//        for (int i=j;i<numsSize;i++) {
//            
//            if (nums[index] + nums[i] == target) {
//                res[0] = index;
//                res[1] = i;
//                return res;
//            }
//            
//            if (i == numsSize - 1) {
//                index ++;
//            }
//            
//        }
//        
//    }
//    return NULL;
//}

typedef struct HashNode {
    int key;
    int val;
} HashNode;

typedef struct HashMap {
    int size;
    HashNode** storage;
} HashMap;

HashMap* hash_create(int size);
void hash_destroy(HashMap* hashMap);
void hash_set(HashMap* hashMap, int key, int value);
HashNode* hash_get(HashMap* hashMap, int key);

HashMap* hash_create(int size) {
    HashMap* hashMap = malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->storage = calloc(size, sizeof(HashNode*));
    return hashMap;
}

void hash_destroy(HashMap* hashMap) {
    for(int i = 0; i < hashMap->size; i++) {
        HashNode* node;
        if ((node = hashMap->storage[i])) {
            free(node);
        }
    }
    free(hashMap->storage);
    free(hashMap);
}

void hash_set(HashMap* hashMap, int key, int value) {
    int hash = abs(key) % hashMap->size; //abs对整数取绝对值
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (hash < hashMap->size - 1) {
            hash ++;
        }
        else {
            hash = 0;
        }
    }
    node = malloc(sizeof(HashNode));
    node->key = key;
    node->val = value;
    hashMap->storage[hash] = node;
}

HashNode* hash_get(HashMap *hashMap, int key) {
    int hash = abs(key) % hashMap->size;
    HashNode* node;
    while ((node = hashMap->storage[hash])) {
        if (node->key == key)
        {
            return node;
        }
        
        if (hash < hashMap->size - 1) {
            hash ++;
        }
        else {
            hash = 0;
        }
    }
    return NULL;
}

int* twoSum(int* nums, int numsSize, int target) {
    HashMap* hashMap;
    HashNode* node;
    int rest, i;
    
    int* result = malloc(sizeof(int) * 2);
    hashMap = hash_create(numsSize * 2);
    for (i = 0; i < numsSize; i++) {
        rest = target - nums[i];
        node = hash_get(hashMap, rest);
        if (node) {
            result[0] = node->val;
            result[1] = i;
            hash_destroy(hashMap);
            return result;
        }
        else {
            hash_set(hashMap, nums[i], i);
        }
    }
    return result;
}
