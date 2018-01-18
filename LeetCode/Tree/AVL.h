//
//  AVL.h
//  LeetCode
//
//  Created by hongeSun on 2017/11/29.
//  Copyright © 2017年 lagou. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);

#endif /* AVL_h */
