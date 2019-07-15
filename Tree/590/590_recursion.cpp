/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> res;
    vector<int> postorder(Node* root) {
        if(root==NULL){
            return res;
        }
        else{
            for(auto node : root->children){
                postorder(node);
            }
            res.push_back(root->val);
        }
        return res;
    }
};
