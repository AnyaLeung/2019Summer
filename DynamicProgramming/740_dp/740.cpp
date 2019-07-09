class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> count(10001, 0);
        vector<int> dp = count;
        int maxno = INT_MIN;
        
        for(auto num : nums){
            count[num] ++;
            maxno = (num>maxno)? num : maxno;
        }
        
        dp[0] = 0;
        dp[1] = count[1];
        for(int i=2; i<=maxno; i++){
            dp[i] = max(count[i]*i+dp[i-2], dp[i-1]);
        }
                   
        return dp[maxno];                    
    }
};
