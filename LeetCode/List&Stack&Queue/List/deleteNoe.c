//
//  deleteNoe.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "deleteNoe.h"

//void deleteNode(struct ListNode node) {
//
//    if (node->Next == NULL) {
//        node = NULL;
//        free(node);
//    }
//    else {
//        struct ListNode *tmp = node->Next;
//        node->Element = tmp->Element;
//        node->Next = tmp->Next;
//        tmp = NULL;
//        free(tmp);
//    }
//
//}
//
////leetcode better solution
//void deleteNode1(struct ListNode node) {
//    if (!node || !node->next)
//        return;
//    ListNode *tmp = node->next;
//    *node = *node->next;
//    free(tmp);
//    return;
//}

