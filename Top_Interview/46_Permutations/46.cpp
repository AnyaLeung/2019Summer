class Solution {
public:
    vector<vector<int>> res;
    
    void helper(vector<int>& curr, unordered_map<int, bool>& used, vector<int> nums){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return ;
        }
        for(auto num : nums){
            if(!used[num]){
                curr.push_back(num);
                used[num] = true;
                helper(curr, used, nums);
                curr.pop_back();
                used[num] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()){
            return res;
        }
        
        vector<int> curr;
        unordered_map<int, bool> used;
        helper(curr, used, nums);
        
        return res;
    }
};
