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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val>key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val<key){
            root->right = deleteNode(root->right, key);
        }
        else{
            //左右子树中有一个为空，则另一个替上来
            if(root->left==NULL || root->right==NULL){
                root = (root->left!=NULL)? root->left : root->right;
            }
            //左右子树都非空
            else{
                TreeNode* curr = root->right;
                while(curr->left){
                    curr = curr->left;
                }
                root->val = curr->val;
                root->right = deleteNode(root->right, curr->val);
            }
        }
        return root;
    }
};
