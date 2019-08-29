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
