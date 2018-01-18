//
//  titleToNumber.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/19.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "titleToNumber.h"

int titleToNumber(char* s) {
    int sum = 0, i = strlen(s);
    do {
        sum += ( (*s) - 64 ) * pow(26, i-1);
        s++;
        i--;
    } while (i != 0);
    
    return sum;
}
