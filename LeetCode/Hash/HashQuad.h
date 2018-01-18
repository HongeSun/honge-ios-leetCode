//
//  HashQuad.h
//  LeetCode
//
//  Created by hongeSun on 2017/12/4.
//  Copyright © 2017年 lagou. All rights reserved.
//

//开放定址法解决冲突
//平方探测法

#ifndef HashQuad_h
#define HashQuad_h

#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif /* HashQuad_h */
