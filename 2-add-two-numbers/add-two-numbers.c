/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* create(int val){
    struct ListNode* new = malloc(sizeof( struct ListNode));
    new -> val = val;
    new -> next = NULL;
    return new;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = NULL;
    struct ListNode* tail = NULL;
    int du = 0, total = 0;
    while(l1!=NULL||l2!=NULL||du!=0){ // tuc khi nao phai ca 3 dkien sai ms break
    total = du; // luon de trc = du
    if(l1!=NULL){
        total += l1->val;
        l1 = l1->next;
    }
    if(l2!=NULL){
        total += l2->val;
        l2 = l2->next;
    }
    int num = total % 10;
    du = total / 10; // < 10: 0, >=10 : 1
    struct ListNode* new = create(num);
    if (res==NULL){ // nut ban dau
        res = new;
        tail = new;
    }
    else{
        tail->next = new;
        tail = new;
    }
    }
    return res;
}