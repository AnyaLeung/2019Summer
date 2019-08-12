class TrieNode{
public:
    TrieNode* child[26];
    bool isWord;
    TrieNode(): isWord(false){
        for(auto &a : child){
            a = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            if(curr->child[word[i]-'a']==NULL){
                curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.empty()){
            return false;
        }
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            if(curr->child[word[i]-'a']==NULL){
                return false;
            }
            curr = curr->child[word[i]-'a'];
        }
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.empty()){
            return false;
        }
        TrieNode *curr = root;
        for(int i=0; i<prefix.size(); i++){
            if(curr->child[prefix[i]-'a']==NULL){
                return false;
            }
            curr = curr->child[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
