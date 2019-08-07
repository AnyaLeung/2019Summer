class Solution {
public:
    vector<vector<string>> res;
    
    bool isPalin(string s){
        int len = s.size();
        int i = 0;
        int j = len - 1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }
    
    void helper(string s, vector<string> curr, int lastindex){
        int len = s.size();
        if(lastindex==len){
            res.push_back(curr);
            return ;
        }
        for(int i=lastindex; i<len; i++){
            string tmp = s.substr(lastindex, i-lastindex+1);
            if(isPalin(tmp)){
                curr.push_back(tmp);
                helper(s, curr, i+1);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        helper(s, curr, 0);
        
        return res;
    }
};
