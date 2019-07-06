class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int mlen = obstacleGrid.size();
        int nlen = obstacleGrid[0].size();

        vector<vector<unsigned int>> dp(mlen+1, vector<unsigned int>(nlen+1, 0));
        dp[1][0] = 1;

        for(int i=1; i<=mlen; i++){
            for(int j=1; j<=nlen; j++){
                if(!obstacleGrid[i-1][j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[mlen][nlen];
    }
};
