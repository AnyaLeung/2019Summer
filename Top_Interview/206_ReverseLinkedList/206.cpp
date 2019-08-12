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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* last = head; 
        ListNode* current = last->next;
        while(current!=NULL){
            last->next = current->next;
            current->next = head;
            //维护head指向链表头
            head = current;
            //维护current，指向last下一个节点，直到current为空，last为最后一节点
            current = last->next;
        }
        return head;
    }
};
