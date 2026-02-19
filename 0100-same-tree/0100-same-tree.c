#include <stdbool.h>
#include <stdlib.h>

#define NULL_MARKER -10001   // outside [-10000,10000]

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// queue for TreeNode*
struct queue{
    int size;
    int f;
    int r;
    struct TreeNode** arr;
};

static int isFull(struct queue* q){
    return q->r == q->size - 1;
}

static int isEmpty(struct queue* q){
    return q->r == q->f;
}

static void enqueue(struct queue* q, struct TreeNode* val){
    if(isFull(q)) return;
    q->r++;
    q->arr[q->r] = val;
}

static struct TreeNode* dequeue(struct queue* q){
    if(isEmpty(q)) return NULL;
    q->f++;
    return q->arr[q->f];
}

static void BFS(struct TreeNode* root, int arr[], int *index){
    if(root == NULL) return;

    struct queue q;
    q.size = 2000;                  // enough for constraints in typical tests
    q.f = q.r = 0;
    q.arr = (struct TreeNode**)malloc(q.size * sizeof(struct TreeNode*));

    enqueue(&q, root);

    while(!isEmpty(&q)){
        struct TreeNode* curr = dequeue(&q);

        if(curr == NULL){
            arr[(*index)++] = NULL_MARKER;
            continue; // don't expand NULL
        }

        arr[(*index)++] = curr->val;

        enqueue(&q, curr->left);
        enqueue(&q, curr->right);
    }

    // trim trailing NULL markers
    //while(*index > 0 && arr[*index - 1] == NULL_MARKER){
    //    (*index)--;
    //}

    free(q.arr);
}

static int isSameArr(int arr1[], int size1, int arr2[], int size2){
    if(size1 != size2) return 0;
    for(int i = 0; i < size1; i++){
        if(arr1[i] != arr2[i]) return 0;
    }
    return 1;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // handle both NULL quickly
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    int arr_p[2000];
    int arr_q[2000];
    int index_p = 0, index_q = 0;

    BFS(p, arr_p, &index_p);
    BFS(q, arr_q, &index_q);

    return isSameArr(arr_p, index_p, arr_q, index_q) ? true : false;
}
