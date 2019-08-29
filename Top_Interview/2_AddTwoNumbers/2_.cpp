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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        
        while(p1 || p2){
            int sum = 0;
            if(p1!=NULL){
                sum += p1->val;
                p1 = p1->next;
            }
            if(p2!=NULL){
                sum += p2->val;
                p2 = p2->next;
            }
            ListNode* pre = new ListNode((sum+carry)%10);
            carry = (sum+carry) / 10;
             p->next = pre;
            p = p->next;
        }
        
        if(carry){
            ListNode* pre = new ListNode(1);
            p->next = pre;
        }
        return dummy->next;
    }
};
