//
//  sumOfTwoIntegers.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/13.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "sumOfTwoIntegers.h"

int getSum(int a, int b) {
    
    if (a == 0) {
        return b;
    }
    else {
        return getSum((a&b)<<1 , (b^a));
    }
}
