class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int res = (len*(len+1)) / 2;
        
        for(auto num : nums){
            res -= num;
        }
        
        return res;
    }
};
