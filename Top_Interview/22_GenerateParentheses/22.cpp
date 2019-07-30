class Solution {
public:
    vector<string> res;
    void helper(string str, int left, int right, int total){
        if(str.size()==total*2){
            res.push_back(str);
            return ;
        }
        if(left<total){
            helper(str+'(', left+1, right, total);
        }
          
        if(right<left){
            helper(str+')', left, right+1, total);
        } 
    }
    vector<string> generateParenthesis(int n) {
        helper("", 0, 0, n);
        return res;
    }
};
