//
//  firstUniqChar.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "firstUniqChar.h"

int getIndex(int index, char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (index == i){
            i++;
            continue;
        }
        else if (s[index] == s[i]) {
            index++;
            return getIndex(index, s);
        }
        else {
            i++;
        }
    }
    return index;
}

int firstUniqChar(char *s) {
    if (*s == '\0')
        return -1;
    else {
        int index = getIndex(0, s);
        if (index >= strlen(s)) {
            return -1;
        }
        else {
            return index;
        }
    }
}

//leetcode better solution
#define TOINDEX(x) x-97  //a的ASCII字符码为97，转化为index是0
int firstUniqChar1(char *s) {
    int vec[26] = {0}, i, len = strlen(s);
    for (i=0; i<len; i++) {
        vec[TOINDEX(s[i])]++;
    }
    for (i=0; i<len; i++) {
        if (vec[TOINDEX(s[i])] == 1) {
            return i;
        }
    }
    return -1;
}

