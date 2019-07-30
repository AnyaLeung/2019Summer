class Solution {
public:
    struct cmp{
        bool operator()(ListNode* list1, ListNode* list2){
            return list1->val > list2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto node : lists){
            if(node){
                pq.push(node);
            }
        }
        while(!pq.empty()){
            ListNode* tmp = pq.top();
            curr->next = tmp;
            curr = curr->next;
            pq.pop();
            if(tmp->next){
                pq.push(tmp->next);
            }
        }
        
        return dummyHead->next;
    }
};
