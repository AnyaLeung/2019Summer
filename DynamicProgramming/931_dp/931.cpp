class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int mlen = A.size();
        int nlen = A[0].size();
        
        vector<vector<int>> dp = A;
        
        for(int i=1; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                if(j==0){
                    dp[i][j] = min(dp[i-1][0], dp[i-1][1]) + A[i][j];
                }
                else if(j==nlen-1){
                    dp[i][j] = min(dp[i-1][nlen-1], dp[i-1][nlen-2]) + A[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j+1], min(dp[i-1][j-1], dp[i-1][j])) + A[i][j];
                }
            }
        }
        
        return *min_element(dp[mlen-1].begin(), dp[mlen-1].end());
    }
};
