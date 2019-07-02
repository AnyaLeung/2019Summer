bool isPalindrome(string s){
    int i = 0;

    while(i<=s.size()/2){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
        i++;
    }
    return true;
}
