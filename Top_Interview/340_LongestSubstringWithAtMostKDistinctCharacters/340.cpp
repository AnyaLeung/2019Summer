class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.size();
        if(len==0 || k==0){
            return 0;
        }
        
        int left = 0;
        int right = 0;
        //map to rightmost position in window
        unordered_map<char, int> mymap;
        int res = 1;
        
        while(right<len){
            mymap[s[right]] ++;
            right ++;
            while(mymap.size()>k){
                mymap[s[left]] --;
                if(mymap[s[left]]==0){
                    mymap.erase(s[left]);
                }
                left ++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};
