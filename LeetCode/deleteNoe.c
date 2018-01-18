//
//  deleteNoe.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "deleteNoe.h"

void deleteNode(ListNode* node) {
    
    if (node->next == NULL) {
        node = NULL;
        free(node);
    }
    else {
        ListNode *tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        tmp = NULL;
        free(tmp);
    }

}

//leetcode better solution
void deleteNode1(ListNode *node) {
    if (!node || !node->next)
        return;
    ListNode *tmp = node->next;
    *node = *node->next;
    free(tmp);
    return;
}
