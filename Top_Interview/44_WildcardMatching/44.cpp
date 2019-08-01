class Solution {
    public boolean isMatch(String s, String p) {
        if(s==null && p==null){
            return true;
        }
        if(s==null){
            return false;
        }
        
        int mlen = s.length();
        int nlen = p.length();
        boolean[][] dp = new boolean[mlen+1][nlen+1];
        
        dp[0][0] = true;
        for(int i=1; i<=mlen; i++){
            dp[i][0] = false;
        }
        
        for(int j=1; j<=nlen; j++){
            if(p.charAt(j-1)=='*' && dp[0][j-1]){
                dp[0][j] = true;
            }
            else{
                dp[0][j] = false;
            }
        }
        
        for(int i=1; i<=mlen; i++){
            for(int j=1; j<=nlen; j++){
                if(s.charAt(i-1)==p.charAt(j-1) || p.charAt(j-1)=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p.charAt(j-1)=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[mlen][nlen];
    }
}
