//
//  HashSep.c
//  LeetCode
//
//  Created by hongeSun on 2017/12/4.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "HashSep.h"
#define MinTableSize 5

struct ListNode {
    ElementType Element;
    Position Next;
};

typedef Position List;
//散列表结构包括一个链表数组以及数组中的链表个数，它们在散列表结构初始化时动态分配空间。
//此时的HashTalbe类型就是指向该结构的指针类型
struct HashTbl {
    int TableSize;
    List *TheLists;
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
    
    H->TableSize = NextPrime(TableSize); //设置表的大小为一个素数
    
    
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        printf("out of space");
    
    //如果List的实现不用表头，就不用下面的初始化
    //但是用了表头，必须给每个表分配一个表头并设置它的Next域为NULL
    //下面的可以用H->TheLists[i] = MakeEmpty();来代替
    for (i = 0; i<H->TableSize; i++) {
        //这句比较低效，因为执行了TableSize次，可以在循环开始之前调用一次malloc操作代替
        //H->TheList = malloc(H->TableSize * sizeof(struct ListNode));
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            printf("out of space");
        else
            H->TheLists[i]->Next = NULL;
    }
    
    return H;
}

Position Find(ElementType Key, HashTable H) {
    Position P;
    List L;
    
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while (P != NULL && P->Element != Key) {//Probably need strcmp
        P = P->Next;
    }
    
    return P;
}

//这个插入例程多少有些不好，因为计算了两次散列函数
//如果这些散列例程真的构成程序运行时间的重要部分，这个程序就应该重写
void Insert(ElementType Key, HashTable H) {
    Position Pos, NewCell;
    List L;
    
    Pos = Find(Key, H);
    if (Pos == NULL) {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            printf("out of space");
        else {
            L = H->TheLists[Hash(Key, H)];
            NewCell->Next = L->Next;
            NewCell->Element = Key; //Probably need strcpy;
            L->Next = NewCell;
        }
    }
}

//删除例程是链表的删除操作的直接实现，如果在散列的诸例程中不包括删除操作，那么最好不要使用表头
//因为使用表头不仅不能简化问题而且还要浪费大量的空间。



