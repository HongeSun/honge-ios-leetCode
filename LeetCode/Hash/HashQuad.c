//
//  HashQuad.c
//  LeetCode
//
//  Created by hongeSun on 2017/12/4.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "HashQuad.h"

#define MinTableSize 5

enum KindOfEntry {Legitimate, Empty, Deleted};
struct HashEntry {
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl {
    int TableSize;
    Cell *TheCells;
};

HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    
    if (TableSize < MinTableSize) {
        printf("table size too small");
        return NULL;
    }
    
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        printf("out of space");
    
    H->TableSize = NextPrime(TableSize);
    
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL)
        printf("out of space");
    for (i=0; i<H->TableSize; i++) {
        H->TheCells[i].Info = Empty;
    }
    
    return H;
}

//比通常的方法要快，因为避免了看似需要的乘法和除法
Position Find(ElementType Key, HashTable H) {
    Position CurrentPos;
    int CollisionNum;
    
    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    
    while (H->TheCells[CurrentPos].Info != Empty
           && H->TheCells[CurrentPos].Element != Key) { //测试顺序很重要，切勿改变它
        CurrentPos += 2* ++CollisionNum - 1; //实际上就是进行一位二进制移位并减一
        if (CurrentPos >= H->TableSize) {
            CurrentPos -= H->TableSize;
        }
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H) {
    Position Pos;
    
    Pos = Find(Key, H);
    if (H->TheCells[Pos].Info != Legitimate) {
        H->TheCells[Pos].Info = Legitimate;
        H->TheCells[Pos].Element = Key;
    }
}

//再散列
HashTable Rehash(HashTable H) {
    int i, OldSize;
    Cell *OldCells;
    
    OldCells = H->TheCells;
    OldSize = H->TableSize;
    
    H = InitializeTable(2*OldSize);
    
    for (i=0; i<OldSize; i++) {
        if (OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);
    }
    
    free(OldCells);
    return H;
}
