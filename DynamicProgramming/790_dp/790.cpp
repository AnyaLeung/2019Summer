class Solution {
public:
    int numTilings(int N) {
        int con = 1e9 + 7; //10^9 + 7
        vector<long long> dp(1001, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for(int i=4; i<N+1; i++){
            dp[i] = 2 * dp[i-1] + dp[i-3];
            dp[i] %= con;
        }
        
        return dp[N];
    }
};
