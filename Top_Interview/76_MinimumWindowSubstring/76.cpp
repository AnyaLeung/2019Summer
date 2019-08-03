class Solution {
public:
    
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int restart = 0;
        int reslen = INT_MAX;
        int matchsize = 0;
        
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        //init needs
        for(char ch : t){
            needs[ch] ++;
        }
        
        while(right<s.size()){
            //expand right
            char ch1 = s[right];
            if(needs.count(ch1)){
                window[ch1] ++;
                if(window[ch1]==needs[ch1]){
                    matchsize ++; //record has how many need chars
                }
            }
            
            right ++;
            //if has enough needs char
            while(matchsize==needs.size()){
                //res only used here
                if(right-left<reslen){
                    reslen = right - left;
                    restart = left;
                }
                char ch2 = s[left];
                if(needs.count(ch2)){
                    window[ch2] --;
                    if(window[ch2]<needs[ch2]){
                        matchsize --;
                    }
                }
                left ++;
            }
        }
        return (reslen==INT_MAX)? "" : s.substr(restart, reslen);
    }
};
