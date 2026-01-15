/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;

    struct ListNode* prev = &dummy;
    struct ListNode* curr = head;
    while(curr!=NULL){
        if(curr->val == val){
            prev->next = curr->next;
            free(curr);
            curr = prev->next;
        }
        else{
            prev = prev->next;
            curr = curr->next;
        }

    }
    return dummy.next;
}