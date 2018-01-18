//
//  List.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

/**
 除了Find和FindPrevious例程外，已经编码的所有操作均需O(1)时间。
 因为在所有情况下，不管表有多大，都只执行固定数目的指令
 
 对于Find和FindPrevious，最坏的情形下运行时间是O(N)
 平均来看，运行时间是O(N)，因为必须平均扫描半个表。
 
 */

#include "List.h"

struct Node {
    ElementType Element;
    Position Next;
};

int IsEmpty(List L) {
    return L->Next == NULL;
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    
    return P;
}

void Delete(ElementType X, List L) {
    Position P, TmpCell;
    
    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
//        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L) {
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P) {
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL) {
        printf("out of space");
    }
    
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L) {
    Position P, Tmp;
    
    P = L->Next;
    L->Next = NULL;
    while (P != NULL) {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
