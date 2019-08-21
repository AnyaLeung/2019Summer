class Codec {
public:
    TreeNode* DFS(istringstream& is){
        string val;
        is >> val;
        if(val=="#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(val));
        TreeNode* left = DFS(is);
        TreeNode* right = DFS(is);
        root->left = left;
        root->right = right;
        return root;
    }
    
    // Encodes a tree to a single string.
    //先序遍历 Pre-Order Traversal 
    string serialize(TreeNode* root) {
        //if is NULL, put "#"
        if(!root){
            return "#";
        }
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + " " + left + " " + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return DFS(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
