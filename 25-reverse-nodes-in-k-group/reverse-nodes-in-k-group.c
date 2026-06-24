/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) return head;
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy -> next  = head;
    struct ListNode *cur, *prev;
    prev = dummy;
    cur = head;
    int cnt = 0;

    while(cur){
        cnt++;
        cur = cur->next;
    }

    while(cnt>=k){
        cur = prev->next;
        struct ListNode *next = cur->next;
        for (int i=0;i<k-1;i++){
            cur -> next = next -> next;
            next -> next = prev -> next;
            prev -> next = next;
            next = cur -> next;
            // prev van giu nguyen, next, cur dich 1
        }
        prev = cur;
        cnt -= k;
    }
    return dummy->next;
}