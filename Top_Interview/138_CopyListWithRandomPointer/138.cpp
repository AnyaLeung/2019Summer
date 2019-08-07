/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return head;
        }
        
        Node* node = head;
        while(node){
            Node* clone = new Node(node->val, node->next, nullptr);
            node->next = clone;
            node = node->next->next;
        }
        
        node = head;
        while(node){
            node->next->random = (node->random==NULL)? NULL : node->random->next;
            node = node->next->next;
        }
        
        node = head;
        Node* res = head->next;
        while(node->next){
            Node* tmp = node->next;
            node->next = node->next->next;
            node = tmp;
        }
        
        return res;
    }
};
