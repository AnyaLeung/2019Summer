class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        int curr0 = 0;
        int curr1 = INT_MIN;
        
        for(int i=0; i<len; i++){
            int tmp = curr0;
            curr0 = max(curr0, curr1+prices[i]);
            curr1 = max(curr1, tmp-prices[i]-fee);
        }
        
        return curr0;
    }
};
