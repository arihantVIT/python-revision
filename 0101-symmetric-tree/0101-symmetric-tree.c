#include <stdio.h>
#include <stdlib.h>
#define NULL_MARKER -10001
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct queue
{
    int size;
    int f;
    int r;
    struct TreeNode **arr;
};

int isEmpty(struct queue *q)
{
    return q->r == q->f;
}

int isFull(struct queue *q)
{
    return q->r == q->size - 1;
}

void enqueue(struct queue *q, struct TreeNode *val)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return;
    }
    q->r++;
    q->arr[q->r] = val;
}

struct TreeNode* dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    q->f++;
    return q->arr[q->f];
}

void BFS_left(struct TreeNode *root, int arr[], int *index)
{
    if (root == NULL)
    {
        return;
    }
    struct queue q;
    q.size=100;
    q.f = -1; q.r = -1;
    q.arr = (struct TreeNode**)malloc(q.size*sizeof(struct TreeNode*));
    enqueue(&q,root);

    while (!isEmpty(&q))
    {
        struct TreeNode* curr = dequeue(&q);
        if (curr==NULL)
        {
            arr[*index] = NULL_MARKER;
            (*index)++;
            continue;
        }

        arr[*index] = curr->val;
        (*index)++;

        enqueue(&q,curr->left);
        enqueue(&q,curr->right);
        
    }
    
}

void BFS_right(struct TreeNode *root, int arr[], int *index)
{
    if (root == NULL)
    {
        return;
    }
    struct queue q;
    q.size=100;
    q.f = -1; q.r = -1;
    q.arr = (struct TreeNode**)malloc(q.size*sizeof(struct TreeNode*));
    enqueue(&q,root);

    while (!isEmpty(&q))
    {
        struct TreeNode* curr = dequeue(&q);
        if (curr==NULL)
        {
            arr[*index] = NULL_MARKER;
            (*index)++;
            continue;
        }

        arr[*index] = curr->val;
        (*index)++;

        
        enqueue(&q,curr->right);
        enqueue(&q,curr->left);
        
    }
    
}

void display(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int isSame(int arr1[], int size1, int arr2[], int size2){
    if (size1!=size2)
    {
        return 0;
    }
    for (int i = 0; i < size1; i++)
    {
        if(arr1[i]!=arr2[i]){
            return 0;
        }
    }
    return 1;
    
    
}
bool isSymmetric(struct TreeNode* root) {
    //for p1;
    int arr_p1[100];
    int index_p1=0;
    BFS_left(root->left,arr_p1,&index_p1);
    display(arr_p1,index_p1);

    //for p2;
    int arr_p2[100];
    int index_p2=0;
    BFS_right(root->right,arr_p2,&index_p2);
    display(arr_p2,index_p2);

    if (isSame(arr_p1,index_p1,arr_p2,index_p2))
    {
        return true;
    }
    return false;
    
}