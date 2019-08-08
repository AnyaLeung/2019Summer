class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                return true;
            }
            if(fast==NULL){
                return false;
            }
        }
        return false;
    }
};
