class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int len = triangle.size();
        
        //dp[0][0] = triangle[0][0];
        for(int i=1; i<len; i++){
            for(int j=0; j<=i; j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] + triangle[i][j];
                }
                else if(j==i){
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        
        return *min_element(dp[len-1].begin(), dp[len-1].end());
    }
};
