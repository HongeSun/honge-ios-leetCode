//
//  fizzBuzz.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/12.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "fizzBuzz.h"

char* toCharArray(int x) {
    int n = log10(x) + 1;
    int i;
    char *array = calloc(n, sizeof(char));
    for (i = n - 1; i >= 0; --i, x /= 10) {
        array[i] = x % 10 + '0';
    }
    return array;
}

char** fizzBuzz(int n, int* returnSize) {
    *returnSize = n;
    char** result = malloc(sizeof(char*) * n);
    char** pointer = result;
    int i = 1;
    while (i <= n) {
        if (i % 3 == 0 && i % 5 == 0) {
            *result = "FizzBuzz";
        }
        else if (i % 3 == 0) {
            *result = "Fizz";
        }
        else if (i % 5 == 0) {
            *result = "Buzz";
        }
        else {
            *result = toCharArray(i);
        }
        result++;
        i++;
    }
    return pointer;
}

//leetcode better solution
char** fizzBuzz1(int n, int* returnSize) {
    int i = 0;
    char** output = calloc(n, sizeof(char*));
    *returnSize = n;
    for(i = 0;i < n;i++) {
        output[i] = malloc(sizeof(char)*9);
        if ((i+1)%15 == 0) {
            strcpy(output[i], "FizzBuzz");
            output[i][8] = '\0';
        }
        else if ((i+1)%3 == 0) {
            strcpy(output[i], "Fizz");
            output[i][4] = '\0';
        }
        else if ((i+1)%5 == 0) {
            strcpy(output[i], "Buzz");
            output[i][4] = '\0';
        }
        else {
            sprintf(output[i], "%d", i+1);
        }
    }
    return output;
}
