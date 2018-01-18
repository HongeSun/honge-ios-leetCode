//
//  HashSep.h
//  LeetCode
//
//  Created by hongeSun on 2017/12/4.
//  Copyright © 2017年 lagou. All rights reserved.
//

//分离链表法解决冲突

#ifndef HashSep_h
#define HashSep_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);


#endif /* HashSep_h */
