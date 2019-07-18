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
    int DFS(TreeNode* root, int sum){
        int res = 0;
        if(root==NULL){
            return res;
        }
        int rem = sum - root->val;
        if(root!=NULL){
            int rem = sum - root->val;
            if(!rem){
                res ++;
            }
            res += DFS(root->left, rem) + DFS(root->right, rem);
        }
        return res;
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL){
            return 0;
        }
        return DFS(root, sum) + pathSum(root->left, sum) + 
            pathSum(root->right, sum); 
    }
};
