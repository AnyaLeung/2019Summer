/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool Judge(TreeNode* root, int v){
        if(root==NULL){
            return true;
        }
        if(root->val!=v){
            return false;
        }
        return Judge(root->left, v) &&
            Judge(root->right, v);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return Judge(root, root->val);
    }
};
