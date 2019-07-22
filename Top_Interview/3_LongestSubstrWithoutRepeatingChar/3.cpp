class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> window;
        int index = 0;
        int left = 0;
        int res = 0;
        
        while(index<s.size()){
            if(window.find(s[index])==window.end()){
                window.insert(s[index]);
                res = max(res, (int)window.size());
                index ++;
            }
            else{
                window.erase(s[left]);
                left ++;
            }
        }
        
        return res;
    }
};
