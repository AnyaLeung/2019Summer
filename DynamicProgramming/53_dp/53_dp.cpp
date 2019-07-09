class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp = nums;
        
        for(int i=1; i<len; i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
