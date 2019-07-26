class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        
        for(int i=0; i<n+1; i++){
            q = q->next;
        }
        while(q){
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        
        return retNode;
    }
};
