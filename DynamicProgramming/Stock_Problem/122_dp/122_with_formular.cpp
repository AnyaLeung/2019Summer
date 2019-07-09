class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(!len) return 0;
        
        vector<vector<int>> dp(len, vector<int>(2, 0));
        
        for(int i=0; i<len; i++){
            if(i==0){
                dp[0][0] = 0;
                dp[0][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        
        return dp[len-1][0];
    }
};
