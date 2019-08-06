class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()<=1){
            return true;
        }
        int i = 0;
        int j = s.size() - 1;
        
        while(i<j){
            while(i<j && !isalnum(s[i])){
                i ++;
            }
            while(i<j && !isalnum(s[j])){
                j --;
            }
            if(tolower(s[i++])!=tolower(s[j--])){
                return false;
            }
        }
        return true;
    }
};
