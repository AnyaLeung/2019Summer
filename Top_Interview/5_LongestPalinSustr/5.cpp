class Solution {
public:
    string longestPalindrome(string s) {
        if(s==""){
            return "";
        }
        int len = s.size();
        bool dp[len][len] = {false};
        string res;
        
        for(int i=0; i<len; i++){
            dp[i][i] = true;
            res = s[i];
        }
        
        for(int i=0; i<len-1; i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                res = s.substr(i, 2);
            }
        }
        
        for(int i=2; i<len; i++){
            for(int j=0; j<=i; j++){
                if((i-j<2 || dp[j+1][i-1]) && s[i]==s[j]){
                    dp[j][i] = true;
                    if(dp[j][i] && i-j+1>res.size()){
                        res = s.substr(j, i-j+1);
                    }
                }
            }
        }
        return res;
    }
};
