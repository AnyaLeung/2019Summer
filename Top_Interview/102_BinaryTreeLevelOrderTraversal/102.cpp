class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
       if(root==NULL){
           return res;
       }
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        
        
        while(myqueue.size()){
            int len = myqueue.size();
            vector<int> levelres;
            while(len){
                TreeNode* tmp = myqueue.front();
                if(tmp->left){
                    myqueue.push(tmp->left);
                }
                if(tmp->right){
                    myqueue.push(tmp->right);
                }
                levelres.push_back(tmp->val);
                myqueue.pop();
                len --;
            }
            res.push_back(levelres);
        }
        return res;
    }
};
