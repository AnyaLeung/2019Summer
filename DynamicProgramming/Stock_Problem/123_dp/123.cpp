class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr10 = 0;
        int curr11 = INT_MIN;
        int curr20 = 0;
        int curr21 = INT_MIN;
        
        for(int price : prices){
            curr20 = max(curr20, curr21+price);
            curr21 = max(curr21, curr10-price);
            curr10 = max(curr10, curr11+price);
            curr11 = max(curr11, -price);
        }
        return curr20;
    }
};
