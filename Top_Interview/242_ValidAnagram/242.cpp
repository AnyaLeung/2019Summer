class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        vector<int> record(26, 0);
        
        for(char ch : s){
            record[ch-'a'] += 1;
        }
        for(char ch : t){
            record[ch-'a'] -= 1;
        }
        
        for(int i=0; i<26; i++){
            if(record[i]){
                return false;
            }
        }
            
        return true;
    }
};
