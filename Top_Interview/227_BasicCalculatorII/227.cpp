class Solution {
public:
    int calculate(string s) {
        long res = 0;
        long num = 0;
        int len = s.size();
        char op = '+';
        stack<int> mystack;
        
        for(int i=0; i<len; i++){
            if(s[i]>='0' && s[i]<='9'){
                num = num * 10 + (s[i]-'0');
            }
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==len-1){
                switch(op){
                    case '+': mystack.push(num); break;
                    case '-': mystack.push(-num); break;
                    case '*': {
                        int tmp = mystack.top() * num;
                        mystack.pop();
                        mystack.push(tmp);
                        break;
                    }
                    case '/': {
                        int tmp = mystack.top() / num;
                        mystack.pop();
                        mystack.push(tmp);
                        break;
                    }
                }
                op = s[i];
                num = 0;
            }
        }
        
        while(mystack.size()){
            res += mystack.top();
            mystack.pop();
        }
        
        return res;
    }
};
