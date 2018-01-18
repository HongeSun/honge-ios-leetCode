//
//  judgeCircle.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/7.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "judgeCircle.h"

bool judgeCircle(char *moves) {
//    int vertical[30] = {0};
//    int i = 0, j = 0;
//    int horizantal[30];
//    
//    while (*moves != '\0') {
//        if (*moves == 'U') {
//            horizantal[i] = 1;
//            ++i;
//        }
//        else if (*moves == 'D') {
//            horizantal[i] = -1;
//            ++i;
//        }
//        else if (*moves == 'L') {
//            vertical[j] = -1;
//            ++j;
//        }
//        else if (*moves == 'R') {
//            vertical[j] = 1;
//            ++j;
//        }
//        else {
//            break;
//        }
//        
//        ++moves;
//    }
//    
//    int resultV = 0, resultH = 0;
//    for (int x = 0; x < 30; x++) {
//        resultV += vertical[x];
//    }
//    for (int y = 0; y < 30; y++) {
//        resultH += horizantal[y];
//    }
//    
//    if (resultH + resultV == 0) {
//        return true;
//    }
//    else {
//        return false;
//    }
    
    int ret[2] = {0};
    do {
        switch (*moves) {
            case 'U':
                ret[0] += 1;
                break;
            case 'D':
                ret[0] -= 1;
                break;
            case 'L':
                ret[1] += 1;
                break;
            case 'R':
                ret[1] -= 1;
                break;
        }

    } while (*moves++);
    return ret[0] == 0 && ret[1] ==0;
}



