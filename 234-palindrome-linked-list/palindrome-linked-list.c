/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 typedef struct ListNode node;
bool isPalindrome(struct ListNode* head) {
    if (!head) return 0;
    node *cur = head;
    int cnt =0;
    while(cur){
        cnt++;
        cur = cur->next;
    }
    cur = head;
    int *tmp = malloc(cnt*sizeof(int));
    for (int i=0;i<cnt;i++){
        tmp[i] = cur -> val;
        cur = cur -> next;
    }

    int l = 0, r = cnt-1;
    while(l<r){
        if (tmp[l]!=tmp[r]) return 0;
        l++; r--;
    }
    return 1;
}