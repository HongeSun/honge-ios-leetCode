//
//  binaryHeap.h
//  LeetCode
//
//  Created by hongeSun on 2017/11/16.
//  Copyright © 2017年 lagou. All rights reserved.
//

#ifndef binaryHeap_h
#define binaryHeap_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);


#endif /* binaryHeap_h */
