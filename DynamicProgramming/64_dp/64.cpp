class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int mlen = grid.size();
        int nlen = grid[0].size();
        vector<vector<int>> dp(mlen, vector<int>(nlen, 0));
        
        dp[0][0] = grid[0][0];
        
        for(int i=1; i<mlen; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        for(int j=1; j<nlen; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for(int i=1; i<mlen; i++){
            for(int j=1; j<nlen; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[mlen-1][nlen-1];
    }
};
