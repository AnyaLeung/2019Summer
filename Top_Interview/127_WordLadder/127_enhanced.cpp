class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset(wordList.begin(), wordList.end());
        if(myset.count(endWord)==0){
            return 0;
        }
        
        unordered_set<string> startSet{beginWord};
        unordered_set<string> endSet{endWord};
        int step = 1;
        
        while(startSet.size() && endSet.size()){
            step ++;
            
            if(startSet.size()>endSet.size()){
                swap(startSet, endSet);
            }
            unordered_set<string> tmpSet;
            
            for(string str : startSet){
                for(int i=0; i<str.size(); i++){
                    string tmp = str;
                    for(char ch='a'; ch<='z'; ch++){
                        tmp[i] = ch;
                        if(endSet.count(tmp)){
                            return step;
                        }
                        else if(myset.count(tmp)){
                            myset.erase(tmp);
                            tmpSet.insert(tmp);
                        }
                    }
                }
            }
            swap(tmpSet, startSet);
        }
        
        return 0;
    }
};
