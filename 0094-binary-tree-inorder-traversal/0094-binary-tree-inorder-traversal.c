#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


void inOrder(struct TreeNode* root, int arr[], int *index){
    if(root==NULL){
        return;
    }
    inOrder(root->left, arr, index);
    arr[*index] = root->val;
    (*index)++;
    inOrder(root->right,arr,index);

}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int *arr = (int*)malloc(sizeof(int) * 100);
    int index=0;
    inOrder(root,arr,&index);
    *returnSize = index;
    return arr;

}