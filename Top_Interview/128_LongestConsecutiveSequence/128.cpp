class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_set<int> myset(nums.begin(), nums.end());
        int res = 0;
        
        for(auto num : nums){
            if(myset.count(num-1)==0){
                int x = num + 1;
                while(myset.count(x)){
                    x ++;
                }
                res = max(res, x-num);
            }
        }
        return res;
    }
};
