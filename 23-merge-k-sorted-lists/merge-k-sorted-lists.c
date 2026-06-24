/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */ 
 struct ListNode *merge(struct ListNode *l1, struct ListNode *l2){
       struct ListNode *dummy = malloc(sizeof(struct ListNode));
        struct ListNode *node = dummy;
        while (l1&&l2){
            if (l1->val > l2->val){
                node -> next = l2; // gan bang ca 1 node
                l2 = l2 -> next;
            }
            else {
                node -> next = l1;
                l1 = l1 -> next;
            }
            node = node -> next;
        }
        node -> next = l1 ? l1 : l2; // gan not phan con lai
        return dummy -> next;
    }
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    while(listsSize > 1){
        int newsize = 0;
        for (int i=0;i<listsSize;i+=2){
            struct ListNode *l1 = lists[i];
            struct ListNode *l2 =  i<listsSize-1 ? lists[i+1]: NULL;
            lists[newsize++] = merge(l1,l2);
        }
        listsSize = newsize;
    }
    return lists[0];
}