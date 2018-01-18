//
//  AVL.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/29.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "AVL.h"

struct AVLNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

static int Height(Position P) {
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

static int Max(int a, int b) {
    return a > b ? a : b;
}

/**
this funciton can be called only if K2 has a left child
 perform a rotate between a node K2 and its left child
 update heights, then return new root
 */
static Position SingleRotateWithLeft(Position K2) {
    Position K1;
    
    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;
    
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    K1->Height = Max(Height(K1->Left), K2->Height) + 1;
    
    return K1;
}

static Position SingleRotateWithRight(Position K2) {
    
}

/**
 this function can be called only if K3 has a left child and K3's left child has a right child
 do the left-right double rotation
 update heights, then return new root
 */
static Position DoubleRotateWithLeft(Position K3) {
    K3->Left = SingleRotateWithRight(K3->Left);
    return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K3) {
    
}

AvlTree Insert(ElementType X, AvlTree T) {
    if (T == NULL){
        T = malloc(sizeof(struct AVLNode));
        if (T == NULL)
            printf("out of space");
        else {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element) {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft(T);
        }
    }
    else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }
    //ELSE X is in the tree already; we'll do noting
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

