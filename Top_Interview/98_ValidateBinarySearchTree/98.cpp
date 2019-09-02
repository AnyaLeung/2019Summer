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
    bool helper(TreeNode* root, int minval, int maxval){
        if(root==NULL){
            return true;
        }
        if(root->val<=minval || root->val>=maxval){
            return false;
        }
        return helper(root->left, minval, root->val)
            && helper(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN, INT_MAX);
    }
};
