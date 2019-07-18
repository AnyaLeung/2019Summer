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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return false;
        }
        int val = sum - root->val;
        if(root->left==NULL && root->right==NULL){
            return val==0;
        }
        return hasPathSum(root->left, val) ||
            hasPathSum(root->right, val);
    }
};
