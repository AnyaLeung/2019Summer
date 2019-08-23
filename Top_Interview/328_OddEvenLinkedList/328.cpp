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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* head2 = second;
        
        while(second!=NULL && second->next!=NULL){
            first->next = second->next;
            first = first->next;
            second->next = first->next;
            second = second->next;
        }
        first->next = head2;
        return head;
    }
};
