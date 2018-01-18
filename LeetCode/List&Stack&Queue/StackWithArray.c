//
//  StackWithArray.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "StackWithArray.h"

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType *Array;
};

Stack CreateStack(int MaxElements) {
    Stack S;
    
    if (MaxElements < MinStackSize) {
        printf("stack size is too small");
    }
    
    S = malloc(sizeof(struct StackRecord));
    if (S == NULL) {
        printf("out of space");
    }
    
    
    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array ==  NULL) {
        printf("out of space");
    }
    S->Capacity = MaxElements;
    MakeEmpty(S);
    
    return S;
}

//释放栈的例程
void DisposeStack(Stack S) {
    if (S != NULL) {
        free(S->Array);
        free(S);
    }
}

int IsEmpty(Stack S) {
    return S->TopOfStack == EmptyTOS;
}

void Push(ElementType X, Stack S) {
    if (IsFull(S)) {
        printf("full stack");
    }
    else {
        S->Array[++S->TopOfStack] = X;
    }
}

ElementType Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack];
    }
    printf("empty stack");
    return 0;
}

/**Pop偶尔写成返回弹出的元素（并使栈改变）的函数,
 虽然当前的想法是函数不应该改变其输入参数，但是TopAndPop表明这在C中是最方便的方法
 */
void Pop(Stack S) {
    if (IsEmpty(S)) {
        printf("empty stack");
    }
    else {
        S->TopOfStack--;
    }
}

ElementType TopAndPop(Stack S) {
    if (!IsEmpty(S)) {
        return S->Array[S->TopOfStack--];
    }
    
    printf("empty stack");
    return 0;
}
