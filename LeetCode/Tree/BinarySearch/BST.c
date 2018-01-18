//
//  BST.c
//  LeetCode
//
//  Created by hongeSun on 2017/11/27.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "BST.h"
struct BinarySearchTreeNode {
    ElementType Element;
    BinarySearchTree Left;
    BinarySearchTree Right;
};

BinarySearchTree MakeEmpty(BinarySearchTree T) {
    if (T != NULL) {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}
//这里的两个递归调用事实上都是尾递归并且可以用一次赋值和一个goto语句代替
//尾递归的使用在这里是合理的，因为算法表达式的简明性是以速度的降低为代价的，而这里使用的栈空间的量不过是O(logN)而已
Position Find(ElementType X, BinarySearchTree T) {
    if (T == NULL)
        return NULL;
    
    if (X < T->Element) {
        return Find(X, T->Left);
    }
    else if (X > T->Element) {
        return Find(X, T->Right);
    }
    else
        return T;
}

//用递归编写，返回最小元的位置
Position FindMin(BinarySearchTree T) {
    if (T == NULL)
        return NULL;
    
    else if (T->Left == NULL)
        return NULL;
    else
        return FindMin(T->Left);
}

//用非递归编写，返回最大元的位置
Position FindMax(BinarySearchTree T) {
    if (T != NULL) {
        while (T->Right != NULL) {
            T = T->Right;
        }
    }
    
    return T;
}

//插入可以像用Find那样沿着树查找
//由于T指向该树的指针，而根又在第一次插入时变化，Insert返回了指向新树根的指针
BinarySearchTree Insert(ElementType X, BinarySearchTree T) {
    if (T == NULL){
        T = malloc(sizeof(struct BinarySearchTreeNode));
        if (T == NULL){
            printf("out of space");
        }
        else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element){
        T->Left = Insert(X, T->Left);
    }
    else if (X > T->Element) {
        T->Right = Insert(X, T->Right);
    }
    //Else X is in the tree already; we'll do nothing
    return T;
}

//如许多数据结构一样，最困难的操作是删除
//如果节点是一片树叶，可以立即删除；如果节点有一个儿子，需要在其父节点调整指针绕过该节点后被删除
//如果要删除的节点有两个儿子，一般的策略是用其右子树的最小的数据代替该节点的数据并递归的删除那个节点
//因为右子树中最小的节点不可能有左儿子，所以第二次Delete容易

//效率不高，因为沿该树进行两趟搜索以查找和删除右子树中最小的节点。
//写一个特殊的DeleteMin函数可以容易的改变效率不高的缺点
BinarySearchTree Delete(ElementType X, BinarySearchTree T) {
    Position TmpCell;
    
    if (T == NULL) {
        printf("element not found");
    }
    else if (X < T->Element) {
        T->Left = Delete(X, T->Left);
    }
    else if (X > T->Element) {
        T->Right = Delete(X, T->Right);
    }
    else if (T->Left && T->Right) { //Two children
        TmpCell = FindMin(T->Right);
        
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else { //One or zero children
        TmpCell = T;
        if (T->Left == NULL) {
            T = T->Right;
        }
        else if (T->Right == NULL) {
            T = T->Left;
        }
        
        free(TmpCell);
    }
    
    return T;
}
//如果删除的次数不多，通常使用的策略是懒惰删除：当一个元素要删除时，它仍留在树中，只是做了个被删除的记号
//如果树中的实际节点与“被删除”的节点数相同，那么熟的深度预计只上升一个小的常数，因此，存在一个与懒惰删除相关的非常小的时间损耗
//但是，如果被删除的关键字是重新插入的，那么分配一个新单元的开销就避免了


