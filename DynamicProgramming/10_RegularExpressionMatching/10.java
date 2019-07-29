class Solution {
public:
    bool isMatch(string s, string p) {
        if(s=="" && p==""){
            return true;
        }
        if(s=="" && p.size()==2 && p[1]=='*'){
            return true;
        }
        if(s==""){
            return false;
        }
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        
        for(int i=0; i<p.size(); i++){
            if(p[i]=='*' && dp[0][i-1]){
                dp[0][i+1] = true;
            }
        }
        
        for(int i=0; i<s.size(); i++){
            for(int j=0; j<p.size(); j++){
                if(p[j]=='.' || p[j]==s[i]){
                    dp[i+1][j+1] = dp[i][j];
                }
                if(p[j]=='*'){
                    if(p[j-1]!=s[i] && p[j-1]!='.'){
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
                    else{
                        dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
