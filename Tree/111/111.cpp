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
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        else if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int res = INT_MAX;
        if(root->left!=NULL){
            res = min(minDepth(root->left), res);
        }
        if(root->right!=NULL){
            res = min(minDepth(root->right), res);
        }
       return res + 1;
        
    }
};
