class Solution {
public:
    string longestPalindrome(string s) {
        if(s=="") return "";
        string result;
        int slen = s.size();
        if(slen==1) return s;
        bool palin[slen][slen] = {false};
        
        
        for(int i=0; i<slen; i++){
            for(int j=0; j<i+1; j++){
                if((i-j<2 || palin[j+1][i-1])&&s[i]==s[j]){
                    palin[j][i] = true;
                    if(palin[j][i]==true && i+1-j>result.size()){
                        result = s.substr(j, i+1-j);
                    }
                    
                }
            }
        }
        return result;
    }
};
