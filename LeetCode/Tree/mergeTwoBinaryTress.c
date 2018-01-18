//
//  mergeTwoBinaryTrees.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/11.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "mergeTwoBinaryTrees.h"


//struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
//    struct TreeNode* result = (struct TreeNode*)malloc(sizeof(struct TreeNode));
//    
//    if (t1 && t2) {
//        result->val = t1->val + t2->val;
//    }
//    else if (t1 && !t2) {
//        result->val = t1->val;
//    }
//    else if (!t1 && t2) {
//        result->val = t2->val;
//    }
//
//    if (t1 && t2) {
//        result->left = mergeTrees(t1->left, t2->left);
//        result->right = mergeTrees(t1->right, t2->right);
//    }
//    else if (t1 && !t2) {
//        result->left = mergeTrees(t1->left, NULL);
//        result->right = mergeTrees(t1->right, NULL);
//    }
//    else if (!t1 && t2) {
//        result->left = mergeTrees(NULL, t2->left);
//        result->right = mergeTrees(NULL, t2->right);
//    }
//    else {
//        result = NULL;
//        
//    }
//    return result;
//}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL)
        return NULL;
    
    if (t1 == NULL)
        return t2;
    
    if (t2 == NULL)
        return t1;
    
    t1->val = t1->val + t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}


