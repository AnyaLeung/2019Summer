//0 reserves for padding
//1 为初始状态，到达边缘只有一种走法
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i=0; i<=m; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=0; j<=n; j++){
            dp[0][j] = 0;
            dp[1][j] = 1;
        }
        
        
        for(int i=2; i<=m; i++){
            for(int j=2; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
