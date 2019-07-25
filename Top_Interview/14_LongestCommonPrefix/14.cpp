class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        string minstr = strs[0];
        string res = "";
        
        //find shortest str
        for(int i=1; i<strs.size(); i++){
            if(strs[i].size()<minstr.size()){
                minstr = strs[i];
            }
        }
        
        for(int i=0; i<minstr.size(); i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i]!=minstr[i]){
                    return res;
                }
            }
            res += minstr[i];
        }
        return res;
    }
};
