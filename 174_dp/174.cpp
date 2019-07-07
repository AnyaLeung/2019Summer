class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int mlen = dungeon.size();
        int nlen = dungeon[0].size();
        
        vector<vector<int>> dp(mlen+1, vector<int>(nlen+1, INT_MAX));
        dp[mlen-1][nlen] = 1;
        dp[mlen][nlen-1] = 1;
        for(int i=mlen-1; i>=0; i--){
            for(int j=nlen-1; j>=0; j--){
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = need <= 0? 1 : need;
            }
        }
        return dp[0][0];
    }
};
