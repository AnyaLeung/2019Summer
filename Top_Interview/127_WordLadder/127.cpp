class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset(wordList.begin(), wordList.end());
        if(myset.count(endWord)==0){
            return 0;
        }
        
        queue<string> myqueue;
        myqueue.push(beginWord);
        int step = 1;
        
        while(myqueue.size()){
            step ++;
            int len = myqueue.size();
            while(len){
                string str = myqueue.front();
                myqueue.pop();
                for(int i=0; i<str.size(); i++){
                    string tmp = str;
                    for(char ch='a'; ch<='z'; ch++){
                        tmp[i] = ch;
                        if(tmp==endWord){
                            return step;
                        }
                        else if(myset.count(tmp)){
                            myset.erase(tmp);
                            myqueue.push(tmp);
                        }
                    }
                }
                len --;
            }
        }
        
        return 0;
    }
};
