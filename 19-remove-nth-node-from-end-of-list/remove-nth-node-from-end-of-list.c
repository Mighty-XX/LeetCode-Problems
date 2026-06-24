/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void xoahientai( struct ListNode *prev){
    struct ListNode *tmp = prev->next;
    prev -> next = tmp -> next; // ko bi mat lket giua cac ptu
    // if (tmp == *head) *head = cur;
    free(tmp);
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy -> next = head;
    int cnt = 0;
    while(head){
        cnt++;
        head = head -> next;
    }
    int idx = cnt - n + 1;
    head = dummy;
    struct ListNode *cur = head;
    for (int i=0;i<idx-1;i++){
        cur = cur->next;
    }
    xoahientai(cur);
    return dummy->next;
}