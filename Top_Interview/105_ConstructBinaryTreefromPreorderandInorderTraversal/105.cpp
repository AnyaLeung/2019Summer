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
    TreeNode* helper(vector<int> preorder, int pindex, vector<int> inorder, int inL, int inR){
        if(inL>=inR){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[pindex]);
        
        int k = 0;
        while(inorder[k]!=node->val){
            k ++;
        }
        
        node->left = helper(preorder, pindex+1, inorder, inL, k);
        node->right = helper(preorder, pindex+1+k-inL, inorder, k+1, inR);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        return helper(preorder, 0, inorder, 0, inorder.size());
    }
};
