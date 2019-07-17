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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> que;
        int len = 0;
        if(root==NULL){
            return result;
        }
        else{
            que.push(root);
        }
        
        while(que.size()){
            vector<int> pres;
            len = que.size();
            
            while(len>0){
                TreeNode* tmp;
                tmp = que.front();
                if(tmp->left){
                    que.push(tmp->left);
                }
                if(tmp->right){
                    que.push(tmp->right);
                }
                pres.push_back(tmp->val);
                que.pop();
                len--;
            }
            result.push_back(pres);
        }
        return result;
    }
};
