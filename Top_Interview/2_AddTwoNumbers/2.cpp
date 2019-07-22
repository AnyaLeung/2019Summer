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
        ListNode* dummyhead = new ListNode(0);
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* restmp = dummyhead;
        int carry = 0;
        
        while(tmp1 || tmp2){
            int sum = 0;
            if(tmp1){
                sum += tmp1->val;
                tmp1 = tmp1->next;
            }
            if(tmp2){
                sum += tmp2->val;
                tmp2 = tmp2->next;
            }
            sum += carry;
            carry = sum / 10;
            restmp->next = new ListNode(sum%10);
            restmp = restmp->next;
        }
        
        if(carry){
            restmp->next = new ListNode(1);
        }
        
        return dummyhead->next;
    }
};
