//
//  deleteNoe.h
//  LeetCode
//
//  Created by hongeSun on 2017/9/21.
//  Copyright © 2017年 lagou. All rights reserved.
//

#ifndef deleteNoe_h
#define deleteNoe_h

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode ListNode;
struct ListNode {
    int val;
    ListNode *next;
};

void deleteNode(struct ListNode* node);

#endif /* deleteNoe_h */
