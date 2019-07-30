class Solution {
public:
    vector<string> res;
    void helper(string digits, int index, map<char, string> lookup, string str){
        if(index==digits.size()){
            res.push_back(str);
            return ;
        }
        else{
            string tmp = lookup[digits[index]];
            for(auto ch : tmp){
                helper(digits, index+1, lookup, str+ch);
            }
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        map<char, string> lookup{
		    {'2', "abc"},
		    {'3',"def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        if(digits.empty()){
            return res;
        }
        helper(digits, 0, lookup, "");
        return res;
    }
};
