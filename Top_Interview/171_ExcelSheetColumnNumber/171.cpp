class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            int num = s[i] - 'A' + 1;
            res = res * 26 + num;
        }
        return res;
    }
};
