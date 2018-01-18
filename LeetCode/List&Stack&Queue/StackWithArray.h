//
//  StackWithArray.h
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

#ifndef StackWithArray_h
#define StackWithArray_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MinStackSize 5
#define EmptyTOS -1

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);

void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif /* StackWithArray_h */
