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
    int res = 0;
    int getDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        res = max(res, left+right);
        return max(left, right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        getDepth(root);
        return res;
    }
};
