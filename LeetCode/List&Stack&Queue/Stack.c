//
//  Stack.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

/**
 stack with linked list
 */

#include "Stack.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack() {
    Stack S;
    
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("out of space");
    }
    
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("must use createStack first");
    }
    else {
        while (!IsEmpty(S)) {
            Pop(S);
        }
    }
}

void Push(ElementType X, Stack S) {
    PtrToNode TmpCell;
    
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL){
        printf("out of space");
    }
    else {
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

ElementType Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->Next->Element;
    }
    
    printf("empty stack");
    return 0; //return value used to avoid warning
}

void Pop(Stack S) {
    PtrToNode FirstCell;
    
    if (IsEmpty(S)) {
        printf("empty stack");
    }
    else {
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}
