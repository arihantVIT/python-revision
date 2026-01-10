#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

void push(struct stack *ptr, int element) {
    if(ptr->top == ptr->size - 1) {
        // Stack full (LeetCode won't hit this for constraints)
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = element;
}

void pop(struct stack *ptr) {
    if(ptr->top == -1) {
        // Stack empty
        return;
    }
    ptr->top--;
}

int calPoints(char **ops, int opsSize) {
    struct stack *record = (struct stack*)malloc(sizeof(struct stack));
    record->size = 1000; // Large enough
    record->top = -1;
    record->arr = (int*)malloc(record->size * sizeof(int));

    for(int i = 0; i < opsSize; i++) {
        char *op = ops[i];

        if(op[0] >= '0' && op[0] <= '9' || (op[0] == '-' && op[1] >= '0' && op[1] <= '9')) {
            // If it's a number (handle negative too)
            int val = atoi(op);
            push(record, val);
        }
        else if(op[0] == 'C') {
            pop(record);
        }
        else if(op[0] == 'D') {
            push(record, record->arr[record->top] * 2);
        }
        else if(op[0] == '+') {
            int val1 = record->arr[record->top];
            int val2 = record->arr[record->top - 1];
            push(record, val1 + val2);
        }
    }

    int sum = 0;
    for(int i = 0; i <= record->top; i++) {
        sum += record->arr[i];
    }

    free(record->arr);
    free(record);

    return sum;
}
