//
//  isAnagram.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "isAnagram.h"

bool isAnagram(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2) {
        return false;
    }
    else {
        int table[26] = {0};
        for (int i=0; i<len1; i++) {
            table[s[i]-'a']++;
            table[t[i]-'a']--;
        }
        for (int j=0; j<26; j++) {
            if (table[j] != 0)
                return false;
        }
        return true;
    }
}

//leetcode better solution 支持256个公用字符集的ASCII编码
#define MAX 256
bool isAnagram1(char *s, char *t) {
    int len1 = strlen(s), len2 = strlen(t);
    if (len1 != len2) {
        return false;
    }
    else {
        char *hashA = calloc(MAX, sizeof(char));
        char *hashB = calloc(MAX, sizeof(char));
        
        for (int i=0; i<len1; i++) {
            hashA[s[i]]++;
        }
        for (int j=0; j<len2; j++) {
            hashB[t[j]]++;
        }
        for (int i=0; i<len2; i++) {
            printf("hashA i is %c\n", hashA[s[i]]);
            printf("hashB i is %c\n\n", hashB[s[i]]);
            if (hashA[s[i]] != hashB[s[i]])
                return false;
        }
        return true;
    }
}
