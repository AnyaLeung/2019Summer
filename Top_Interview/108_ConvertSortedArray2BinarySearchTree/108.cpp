class Solution {
public:
    TreeNode* helper(vector<int> nums,int begin,int end){
        if(begin>end){
            return NULL;
        }
        int mid = begin + (end-begin) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = helper(nums, begin, mid-1);
        node->right = helper(nums, mid+1, end);
            
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};
