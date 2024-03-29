class Solution {
public:
    int calcTreeSize(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1 + calcTreeSize(root->left) + calcTreeSize(root->right);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL){
            return 0;
        }
        int leftSize = calcTreeSize(root->left);
        if(k==leftSize+1){
            return root->val;
        }
        else if(leftSize>=k){
            return kthSmallest(root->left, k);
        }
        else if(leftSize<k){
            return kthSmallest(root->right, k-leftSize-1);
        }
        return -1;
    }
};
