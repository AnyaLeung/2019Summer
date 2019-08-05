/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
* 第一层->，第二层<-，第三层-> ...
*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return res;
        }
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        bool rev = false;
        
        while(myqueue.size()){
            vector<int> levelres;
            int len = myqueue.size();
            while(len){
                TreeNode* tmp = myqueue.front();
                myqueue.pop();
                levelres.push_back(tmp->val);
                if(tmp->left){
                    myqueue.push(tmp->left);
                }
                if(tmp->right){
                    myqueue.push(tmp->right);
                }
                len --;
            }
            if(rev){
                reverse(levelres.begin(), levelres.end());
            }
            res.push_back(levelres);
            rev = !rev; 
        }
        return res;
    }
};
