class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> dp(len, false);
        dp[0] = true;
        
        for(int i=1; i<=len; i++){
            for(int j=1; j<=i; j++){
                string str = s.substr(j-1, i-j+1);
                if(dp[j-1] 
                   && find(wordDict.begin(), wordDict.end(), str)!=wordDict.end()){
                    dp[i] = true;
                }
            }
        }
        return dp[len];
    }
};
