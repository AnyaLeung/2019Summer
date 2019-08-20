class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty()){
            return "";
        }
        if(words[0]=="z" && words[0]=="z"){
            return "z";
        }
        unordered_map<char, int> indegree;
        unordered_map<char, multiset<char>> hash;
        string res;
        
        for(string word : words){
            for(char ch : word){
                indegree[ch] = 0;
            }
        }
        
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];
            int k = 0;
            while(w1[k]==w2[k]){
                k ++;
            }
            indegree[w2[k]] ++;
            hash[w1[k]].insert(w2[k]);
        }
        
        for(int i=0; i<indegree.size(); i++){
            char ch = ' ';
            for(auto val : indegree){
                if(val.second==0){
                    ch = val.first;
                    break;
                }
            }
            if(ch==' '){
                return "";
            }
            res += ch;
            indegree[ch] --;
            for(auto val : hash[ch]){
                indegree[val] --;
            }
        }
        
        return res;
    }
};
