class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(!len) return 0;
        int min_price = prices[0];
        int result = 0;
        
        for(int i=0; i<len; i++){
            min_price = min(prices[i], min_price);
            result = max(0, max(prices[i]-min_price, result));
            //dp[i] = max(0, prices[i]-min_price, dp[i-1]);
        }
        
        return result;
    }
};
