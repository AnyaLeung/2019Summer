class Solution {
public:
    vector<string> res;
    void DFS(string s, string str, int k){
        if(s.empty() && k==4){
            res.push_back(str.substr(0, str.size()-1));
            return ;
        }
        if(s.empty() || k==4){
            return ;
        }
        for(int i=1; i<=min(3, (int)s.size()); i++){
            int val = stoi(s.substr(0, i));
            if(val>=0 && val<=255){
                DFS(s.substr(i), str+s.substr(0, i)+".", k+1);
            }
            if(s[0]=='0'){
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.empty()){
            return res;
        }
        DFS(s, "", 0);
        return res;
    }
};

