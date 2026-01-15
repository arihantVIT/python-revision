#include <stdlib.h>

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode* p = head;
    struct ListNode* q = head->next;

    while (q != NULL) {
        if (p->val == q->val) {
            p->next = q->next;
            free(q);
            q = p->next;   // stay on same p
        } else {
            p = q;
            q = q->next;
        }
    }

    return head;
}
