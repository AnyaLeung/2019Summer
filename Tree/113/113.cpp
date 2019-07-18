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
    void DFS(TreeNode* root, int sum, vector<int> tmp, vector<vector<int>> &res){
        if(root!=NULL){
        tmp.push_back(root->val);
        int rem = sum - root->val;
        
        if(root->left==NULL && root->right==NULL && !rem){
            res.push_back(tmp);
        }
        else{
           DFS(root->left, rem, tmp, res);
           DFS(root->right, rem, tmp, res);
        }
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> tmp;
        
        if(root==NULL){
            return res;
        }
        DFS(root, sum, tmp, res);
        return res;
    }
};
