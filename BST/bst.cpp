#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

//insertion(without repeating value)
bool insert(TreeNode* &root, int val){
    TreeNode* node = new TreeNode(val);
    if(root==NULL){
        root = node;
        return true;
    }
    if(val==root->val){
        return false;
    }
    else(val<root->val){
        return insert(root->left, val);
    }
    else(val>root->val){
        return insert(root->right, val);
    }
}

//search
bool search(TreeNode* root, int val){
    if(root==NULL){
        return false;
    }
    else if(root->val<val){
        return search(root->right, val);
    }
    else if(root->val>val){
        return search(root->left, val);
    }
    return true;
}

//deletion
//见Tree/450/
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL){
        return root;
    }
    else if(root->val<key){
        root->right = deleteNode(root->right, key);
    }
    else if(root->val>key){
        root->left = deleteNode(root->left, key);
    }
    else if(root->val==key)
        if(root->left==NULL || root->right==NULL){
            root = (root->left==NULL)? root->right : root->left;
        }
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
