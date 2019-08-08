/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:  
    ListNode *sortList(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ListNode* head1 = head;
        
        head1 = sortList(head1);
        head2 = sortList(head2);
        
        return merge(head1, head2);
    }
 
private:
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = dummyHead;
        
        while(h1!=NULL && h2!=NULL){
            if(h1->val<h2->val){
                p->next = h1;
                h1 = h1->next;
            }
            else{
                p->next = h2;
                h2 = h2->next;
            }
            p = p->next;
        }
        
        if(h1!=NULL){
            p->next = h1;
        }
        if(h2!=NULL){
            p->next = h2;
        }
        
        return dummyHead->next;
    }
};
