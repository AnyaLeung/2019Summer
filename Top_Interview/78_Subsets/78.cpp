class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> nums, int begin, vector<int>& curr){
        res.push_back(curr);
        for(int i=begin; i<nums.size(); i++){
            curr.push_back(nums[i]);
            helper(nums, i+1, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()){
            return res;
        }
        vector<int> pre;
        helper(nums, 0, pre);
        
        return res;
    }
};
