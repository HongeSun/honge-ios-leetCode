//
//  BST.h
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct BinarySearchTreeNode;
typedef struct BinarySearchTreeNode *Position;
typedef struct BinarySearchTreeNode *BinarySearchTree;

BinarySearchTree MakeEmpty(BinarySearchTree T);
Position Find(ElementType X, BinarySearchTree T);
Position FindMin(BinarySearchTree T);
Position FindMax(BinarySearchTree T);
BinarySearchTree Insert(ElementType X, BinarySearchTree T);
BinarySearchTree Delete(ElementType X, BinarySearchTree T);
ElementType Retrieve(Position P);

#endif /* BST_h */
