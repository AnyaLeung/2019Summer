class Solution {
public: 
    vector<string> res;
    unordered_set<string> myset;
    vector<string> path;
    
    void helper(string s, int left, int right){
        if(left>right){
            string str;
            for(string word : path){
                str += word + " ";
            }
            str.pop_back(); //remove last " ", turn "dog cats "->"dog cats"
            res.push_back(str);
            return ;
        }
        
        //i 是截取字符串的长度
        for(int i=1; i<=right-left+1; i++){
            string tmp = s.substr(left, i);
            if(myset.count(tmp)){
                path.push_back(tmp);
                helper(s, left+i, right);
                path.pop_back();
            }
        }
    }
    
    bool isBreak(string& s, unordered_set<string> myset){
       int len = s.size();
        vector<bool> dp(len, false);
        dp[0] = true;

        for(int i=1; i<=len; i++){
            for(int j=1; j<=i; j++){
                string str = s.substr(j-1, i-j+1);
                if(dp[j-1] && myset.count(str)){
                    dp[i] = true;
                }
            }
        }
        return dp[len];
    }
        
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<vector<int>> flag(len, vector<int>(len, 0));
        int maxlen = 0;
        
        //move wordDict -> unordered_set
        for(auto str : wordDict){
            myset.insert(str);
        }
        if(!isBreak(s, myset)){
            return res;
        }
        
        helper(s, 0, s.size()-1);
        return res;
    }
        
};
