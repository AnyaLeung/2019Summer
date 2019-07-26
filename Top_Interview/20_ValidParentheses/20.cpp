class Solution {
public:
    bool isValid(string s) {
        if(s.empty()){
            return true;
        }
        if(s.size()%2){
            return false;
        }
        
        map<char, char> mapping{
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        stack<char> sta;
        for(char ch : s){
            if(ch=='{' || ch=='(' || ch=='['){
                sta.push(ch);
            }
            else if(ch=='}' || ch==')' || ch==']'){
                if(sta.empty()){
                    return false;
                }
                else if(sta.top()==mapping[ch]){
                    sta.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        
        if(sta.empty()){
            return true;
        }
        return false;
    }
};
