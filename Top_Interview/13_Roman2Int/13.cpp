class Solution {
public:
    int romanToInt(string s) {
       map<string, int> m = {
           {"I", 1},
           {"IV", 4},
           {"V", 5},
           {"IX", 9},
           {"X", 10},
           {"XL", 40},
           {"L", 50},
           {"XC", 90},
           {"C", 100},
           {"CD", 400},
           {"D", 500},
           {"CM", 900},
           {"M", 1000}
       };
        int res = 0;
        for(int i=0; i<s.size(); ){
            if(i+1<s.size() && m.count(s.substr(i, 2))){
                res += m[s.substr(i, 2)];
                i += 2;
            }
            else{
                res += m[s.substr(i, 1)];
                i ++;
            }
        }
        return res;
    }
};
