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
    int DFS(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = DFS(root->left);
        int right = DFS(root->right);
        if(root->left!=NULL && root->val==root->left->val){
            left++;
        }
        else{
            left = 0;
        }
        
        if(root->right!=NULL && root->val==root->right->val){
            right++;
        }
        else{
            right = 0;
        }
        res = max(res, left+right);
        return max(left, right);
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        DFS(root);
        return res;
    }
};
