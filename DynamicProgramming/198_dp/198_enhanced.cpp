class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        if(len==1) return nums[0];
        vector<int> dp(len, 0);
        
        int previous = nums[0];
        int current = max(nums[0], nums[1]);
        
        for(int i=2; i<len; i++){
            int tmp = current;
            current = max(previous+nums[i], current);
            previous = tmp;      
        }
        
        return current;
    }
};
