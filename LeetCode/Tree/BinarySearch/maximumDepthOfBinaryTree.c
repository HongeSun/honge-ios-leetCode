//
//  maximumDepthOfBinaryTree.c
//  LeetCode
//
//  Created by hongeSun on 2017/9/13.
//  Copyright © 2017年 lagou. All rights reserved.
//

#include "maximumDepthOfBinaryTree.h"
int findNode(struct BinarySearchTreeNode *root, int count) {
    if (root == NULL) {
        return 0;
    }
    else if (root->left && root->right){
        count++;
        int a = findNode(root->left, count);
        int b = findNode(root->right, count);
        if (a > b) {
            return a;
        }
        else {
            return b;
        }
    }
    else if (root->left) {
        count++;
        return findNode(root->left, count);
    }
    else if (root->right) {
        count++;
        return findNode(root->right, count);
    }
    else {
        return count;
    }
}

int maxDepth(struct BinarySearchTreeNode* root) {
    return findNode(root, 1);
}


//leetcode better solution
int maxDepth1(struct BinarySearchTreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    else {
        if (!root->left) return maxDepth(root->right)+1;
        else if (!root->right) return maxDepth(root->left)+1;
        else {
            int a = maxDepth(root->left), b = maxDepth(root->right);
            return (a > b ? a+1 : b+1);
        }
    }
}
