#include <stdbool.h>
#include <stdlib.h>

#define NULL_MARKER -10001   // outside LeetCode value range [-10000,10000]



// preorder traversal with NULL markers
void preorder(struct TreeNode* root, int arr[], int *index){
    if(root == NULL){
        arr[(*index)++] = NULL_MARKER;
        return;
    }

    arr[(*index)++] = root->val;

    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

// compare two arrays
int isSame(int arr1[], int size1, int arr2[], int size2){
    if(size1 != size2) return 0;

    for(int i=0;i<size1;i++){
        if(arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

    int arr_p[1000];
    int arr_q[1000];

    int index_p = 0;
    int index_q = 0;

    preorder(p, arr_p, &index_p);
    preorder(q, arr_q, &index_q);

    return isSame(arr_p, index_p, arr_q, index_q);
}
