class Solution {
public:
    int str2num(string s){
        int num = 0;
        stringstream ss(s);
        ss >> num;
        return num;
    }
    
    int evalRPN(vector<string>& tokens){
        stack<int> mystack;
        int len = tokens.size();
        int res = 0;
        
        
        if(tokens[0]!="+" && tokens[0]!="-" && tokens[0]!="*" && tokens[0]!="/"){
            res = str2num(tokens[0]);
        }
        
        for(int i=0; i<len; i++){
            if(tokens[i]=="+"){
                int right = mystack.top();
                mystack.pop();
                int left = mystack.top();
                mystack.pop();
                res = left + right;
                mystack.push(res);
            }
            else if(tokens[i]=="-"){
                int right = mystack.top();
                mystack.pop();
                int left = mystack.top();
                mystack.pop();
                res = left - right;
                mystack.push(res);
            }
            else if(tokens[i]=="*"){
                 int right = mystack.top();
                mystack.pop();
                int left = mystack.top();
                mystack.pop();
                res = left * right;
                mystack.push(res);
            }
            else if(tokens[i]=="/"){
                 int right = mystack.top();
                mystack.pop();
                int left = mystack.top();
                mystack.pop();
                res = left / right;
                mystack.push(res);
            }
            else{ //is number
                int num = str2num(tokens[i]);
                mystack.push(num);
            }
        }
        
        return res;
    }
};
