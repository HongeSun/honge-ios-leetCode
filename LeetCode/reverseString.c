//
//  reverseString.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/12.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "reverseString.h"

char* reverseString(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    char* result = malloc(i+1);
    char* pointer = result;
    while (i > 0) {
        *result = s[i-1];
        i--;
        result++;
    }
    *result = '\0';
    
    return pointer;
}

//leetcode better solution
char* reverseString1(char* s) {
    char* start = s;
    char* end = s;
    
    while (*end) {
        end++;
    }
    
    end--;
    
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    
    return s;
}
