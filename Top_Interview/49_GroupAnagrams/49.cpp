class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> lookup;
        
        for(string str : strs){
            int tmp = str;
            sort(tmp.begin(), tmp.end());
            lookup[tmp].push_back(str);
        }
        
        vector<vector<string>> res;
        //for(pair<string, vector<string>> lpair : lookup)
        for(auto lpair : lookup){
            res.push_back(lpair.second);
            //res.push_back(lookup[lpair.first]);
        }
        
        return res;
    }
};
