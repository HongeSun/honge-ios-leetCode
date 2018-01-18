//
//  binaryHeap.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/16.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "binaryHeap.h"
#define MinPQSize 10
#define MinData 0

struct HeapStruct
{
    int Capacity; //堆的最大容量
    int Size; //当前堆的大小
    ElementType *Elements; //数组
};

int IsEmpty (PriorityQueue H) {
    return 0;
}

int IsFull (PriorityQueue H) {
    return 0;
}

PriorityQueue Initialize(int MaxElements) {
    PriorityQueue H;
    if (MaxElements < MinPQSize)
        printf("Priority queue size is too small");
    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        printf("Out of space");
    
    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        printf("out of space");
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}

//上滤
void Insert(ElementType X, PriorityQueue H) {
    int i;
    if (IsFull(H)) {
        printf("priority queue is full");
        return;
    }
    
    for (i = ++H->Size; H->Elements[i/2] > X; i/=2) {
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H) {
    int i, Child;
    ElementType MinElement, LastElement;
    
    if (IsEmpty(H)) {
        printf("priority queue is empty");
        return H->Elements[0];
    }
    
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size--];
    
    for (i=1; i*2 <= H->Size; i=Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child]) {
            Child ++;
        }
        if (LastElement > H->Elements[Child]) {
            H->Elements[i] = H->Elements[Child];
        }
        else {
            break;
        }
    }
    
    H->Elements[i] = LastElement;
    return MinElement;
}

