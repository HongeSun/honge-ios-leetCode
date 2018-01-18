//
//  main.m
//  LeetCode
//
//  Created by hongeSun on 2017/8/31.
//  Copyright © 2017年 lagou. All rights reserved.
//

#import <Foundation/Foundation.h>
//#include "hammingDistance.h"
//#include "encodeAndDecodeTinyURL.h"
//
//#include "twoSum.h"
//#include "judgeCircle.h"
//#include "mergeTwoBinaryTrees.h"
//#include "arrayPartitionI.h"
//#include "numberComplement.h"

#include "reverseString.h"
#include "fizzBuzz.h"
#include "singleNumber.h"
#include "sumOfTwoIntegers.h"
#include "moveZeroes.h"
#include "titleToNumber.h"
#include "maxProfit.h"
#include "mergeSortedArray.h"

#include "majorityElement.h"
#include "firstUniqChar.h"
#include "deleteNoe.h"
#include "isAnagram.h"

#include "productExceptSelf.h"
#include "topKFrequent.h"
#include "trappingRainWater.h"
#include "longestIncreasingPath.h"
//
//typedef struct Node Node;
//struct Node
//{
//    long item;
//    int count;
//    Node *pLeft;
//    Node *pRight;
//};
//
//void func();
//void list_treeNodes(struct TreeNode* node);
//
//void fileOperate();
//void fileStrOperate();

//int main(int argc, const char * argv[]) {

    
//    struct TreeNode tree1 = {5, NULL, NULL};
//    struct TreeNode tree2 = {3, &tree1, NULL};
//    struct TreeNode tree3 = {2, NULL, NULL};
//    struct TreeNode tree4 = {1, &tree2, &tree3};
//
//    struct TreeNode tree5 = {4, NULL, NULL};
//    struct TreeNode tree6 = {7, NULL, NULL};
//    struct TreeNode tree7 = {1, NULL, &tree5};
//    struct TreeNode tree8 = {3, NULL, &tree6};
//    struct TreeNode tree9 = {2, &tree7, &tree8};
//
    
//    int **nums = [
//                  [9,9,4],
//                  [6,6,8],
//                  [2,1,1]
//    ];
//    int rowSize = sizeof(nums[0])/sizeof(nums[0][0]);
//    int colSize = sizeof(nums)/sizeof(nums[0]);
//    int ans = longestIncreasingPath(nums, rowSize, colSize);
//    printf("longest increasing path is %d.\n", ans);
    
    
    int nums[] = {0,1,0,2,1,0,1,3,2,1,2,1};
//    int nums[] = {0,0,1};
    int numsSize = sizeof(nums)/sizeof(nums[0]);
    int result = trap(nums, numsSize);
    printf("trapping rain water count is %d\n", nums[2]);
    
    
//
//    int nums[] = {6,0,1,4,9,7,-3,1,-4,-8,4,-7,-3,3,2,-3,9,5,-4,0};
//    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    int k = 6;
//    int *returnSize = NULL;
//    int *res = topKFrequent(nums, numsSize, k, returnSize);
//    for (int i=0; i<k; i++) {
//        printf("top k i is %d\n", res[i]);
//    }
    
//    int nums[] = {0,0};
//    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    int *returnSize;
//    int *productArr = productExceptSelf(nums, numsSize, returnSize);
//    for (int i=0; i<numsSize; i++) {
//        printf("resturn i is %d\n", productArr[i]);
//    }
    
//    char s[] = "aa-";
//    char t[] = "a-a";
//    bool result = isAnagram1(s, t);
//    printf("anagram result is %d\n", result);

//    ListNode *node3 = malloc(sizeof(ListNode));
//    node3->val = 4, node3->next = NULL;
//
//    ListNode *node2 = malloc(sizeof(ListNode));
//    node2->val = 3, node2->next = node3;
//
//    ListNode *node1 = malloc(sizeof(ListNode));
//    node1->val = 2, node1->next = node2;
//
//    ListNode *node = malloc(sizeof(ListNode));
//    node->val = 1, node->next = node1;
//
//    deleteNode(node3);
//    while (node != NULL) {
//        printf("node val is %d\n", node->val);
//        node = node->next;
//    }
    
//    char s[] ="aa";
//    int a = firstUniqChar(s);
//    printf("first uniq char is %d\n", a);
    
    
//    int array[] = {6,5,5};
//    int numsSize = sizeof(array)/sizeof(array[0]);
//    int a = majorityElement(array, numsSize);
//    printf(" majority element is %d\n", a);
    
    
//    int nums1[10] = {1, 3, 4};
//    int nums2[] = {2, 5};
//    int m = 3;
//    int n = sizeof(nums2)/sizeof(nums2[0]);
//    merge(nums1, m, nums2, n);
//    for(int i=0; i < m+n; i++) {
//        printf("%d\n", nums1[i]);
//    }
    
//    char titles[] = "CFDGSXM";
//    int number = titleToNumber(titles);
//    printf("title to number is %d\n", number);
    
//    int nums[] = {1, 0, 3, 4};
//    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    moveZeroes(nums, numsSize);
//    for(int i = 0; i < numsSize; i++) {
//        printf("nums[i] is %d\n", nums[i]);
//    }
    
//    int a = 3, b = 9;
//    int sum = getSum(a, b);
//    printf("sum of two integers is %d\n", sum);
    
//    struct TreeNode tree1 = {5, NULL, NULL};
//    struct TreeNode tree2 = {3, &tree1, NULL};
//    struct TreeNode tree3 = {2, NULL, NULL};
//    struct TreeNode tree4 = {1, &tree2, &tree3};
//
//    struct TreeNode tree5 = {4, NULL, NULL};
//    struct TreeNode tree6 = {7, NULL, NULL};
//    struct TreeNode tree7 = {1, NULL, &tree5};
//    struct TreeNode tree8 = {3, NULL, &tree6};
//    struct TreeNode tree9 = {2, &tree7, &tree8};
//
//    int maxdepth = maxDepth(&tree9);
//    printf("max depth is %d\n", maxdepth);

//    int nums[] = {1, 2,2};
//    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    int resultNum = singleNumber(nums, numsSize);
//    
//    printf("singleNumber is %d.\n", resultNum);
    
//    int n = 5, i = 0;
//    int* returnSize = malloc(100);
//    char** result = fizzBuzz(n, returnSize);
//    while (i < n) {
//        printf("%s\n", *result);
//        result++;
//        i++;
//    }
//    
//    char inputStr[] = "hello";
//    char* outputStr = reverseString(inputStr);
//    while (*outputStr != '\0') {
//        printf("output str is %c.\n", *outputStr);
//        outputStr++;
//    }
    
    
//    int count = hammingDistance(1, 4);
//    printf("hamming distance is %i\n", count);
    
//    int a = findComplement(1);
//    printf("number complement is %d.\n", a);
    
//    int arr[] = {3, 0, 4, 7, 1, 4};
//    int a = arrayPairSum(arr, sizeof(arr)/sizeof(arr[0]));
    

//    
//    struct TreeNode* resultTree = mergeTrees(&tree4, &tree9);
//    list_treeNodes(resultTree);
    
//    
//    char longUrl[] = "https://leetcode.com/problems/design-tinyurl";
//    char shortUrl[] = "http://tinyurl.com/4e9iAK";
//    
//    char *longout, *shortout;
//    longout = encode(longUrl);
    
//    int b = 36;
//    char a = b;
//    printf("long out is %c | %d\n", b, b);

//    
//    char *moves = "UD";
//    bool value = judgeCircle(moves);
//    printf("judge circle result is %i.\n", value);

//    int nums[7] = {3, 3, 7, 12, 15, 1, 8};
//    int target = 9;
//    int numsSize = sizeof(nums)/sizeof(nums[0]);
//    
//    
//    int *result = twoSum(nums, numsSize, target);
//    if (result != NULL) {
//        printf("%i %i\n", result[0], result[1]);
//    }
//    else {
//        printf("没有结果\n");
//    }
//

//    puts("Is there no end to input and output?");
//    putchar('');
    
//    char arr[20];
//    int count = 4;
//    int nchars = snprintf(arr, sizeof(result), "A dog has %d legs", count);
//    printf("%i", nchars);
//    
//    func();

//    fileOperate();
    
    
//    setlocale(LC_ALL, "US");
//    struct lconv *pconverntions = localeconv();
//    printf("the currency symbol in use is %c.\n", *(pconverntions->currency_symbol));
    
//    return 0;
//}


#include "findPeakElement.h"

int main(int argc, const char * argv[]) {
    
    return 0;
}


#pragma mark -
#pragma mark Heap (PriorityQueue)
//No.295
void medianFinder() {
    
}




#pragma mark -
#pragma mark List & Stack & Queue


#pragma mark -
#pragma mark Sort

#pragma mark -
#pragma mark Tree


#pragma mark BinarySearch



#pragma mark -
#pragma mark Hash



void fileStrOperate()
{
    int length = 81;
    char *proverbs[] = {
        "Many a mickle makes a muckle.\n",
        "Too many cooks spoil the broth.\n",
        "He who laughs last didn't get the joke in"
        " the first place.\n"
    };
    char more[length];
    FILE *pfile = NULL;
    char *filename = "myfile.txt";
    
    pfile = fopen(filename, "w");
    if(pfile == NULL) {
        printf("Error opening %s for writing. Program terminated.\n", filename);
        exit(1);
    }
    setvbuf(pfile, NULL, _IOFBF, BUFSIZ);
    
    for (size_t i = 0; i < sizeof(proverbs)/sizeof(proverbs[0]); ++i) {
        if (EOF == fputs(proverbs[i], pfile)) {
            printf("Error writing file.\n");
            exit(1);
        }
    }
    fclose(pfile);
    pfile = NULL;
    
    pfile = fopen(filename, "a");
    if (pfile == NULL) {
        printf("Error opening %s for appending. Program terminated.\n", filename);
        exit(1);
    }
    setvbuf(pfile, NULL, _IOFBF, BUFSIZ);
    
    printf("Enter proverbs of up to %d characters or press Enter to end:\n", length - 1);
    
    while (true) {
        fgets(more, length, stdin);
        if (more[0] == '\n')
            break;
        if (EOF == fputs(more, pfile))
        {
            printf("Error writing file.\n");
            exit(1);
        }
    }
    fclose(pfile);
    pfile = NULL;
    
}

void fileOperate()
{
    int length = 81;
    char mystr[length];
    int mychar = 0;
    FILE *pfile = NULL;
    char *filename = "myfile.txt";
    
    printf("Enter an interesting string of up to %d characters:\n", length - 1);
    if (!fgets(mystr, length, stdin))
    {
        printf("Input from keyboard failed.\n");
        exit(1);
    }
    pfile = fopen(filename, "w");
    if (pfile == NULL) {
        printf("Error opening %s for writing. Program terminated.\n", filename);
        exit(1);
    }
    setvbuf(pfile, NULL, _IOFBF, BUFSIZ);
    
    for (int i = (int)strnlen(mystr, length) - 1; i >= 0; --i)
    {
        fputc(mystr[i], pfile);
    }
    
    fclose(pfile);
    
    pfile = fopen(filename, "r");
    if (pfile ==  NULL) {
        printf("Error opening %s for reading. Program terminated.", filename);
        exit(1);
    }
    setvbuf(pfile, NULL, _IOFBF, BUFSIZ);
    
    printf("the data read from the file is:\n");
    
    while ((mychar = fgetc(pfile)) != EOF) {
        putchar(mychar);
    }
    putchar('\n');
    
    fclose(pfile);
    pfile = NULL;
    remove(filename);
}

void func() {
    char initial[3] = {' '};
    char name[80] = {' '};
    
    printf("Enter your first initial: ");
    gets(initial);
    
    printf("Enter your name: ");
    gets(name);
    
    if (initial[0] != name[0]) {
        printf("%s, you got your initial wrong.\n", name);
    }
    else {
        printf("Hi, %s. Your initial is correct. Well done!\n", name);
    }
    
}

