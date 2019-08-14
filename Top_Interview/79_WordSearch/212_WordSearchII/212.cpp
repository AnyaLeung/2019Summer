
class Solution {
public:
    struct TrieNode{
        TrieNode* child[26];
        string str;
        TrieNode(): str(""){
            for(int i=0; i<26; i++){
                child[i] = NULL;
            }
        }
    };
    
    struct Trie {
        TrieNode *root;
        Trie() : root(new TrieNode()){}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &ch : s) {
                if (p->child[ch-'a']==NULL){
                    p->child[ch-'a'] = new TrieNode();
                } 
                p = p->child[ch-'a'];
            }
            p->str = s;
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (words.empty() || board.empty() || board[0].empty()){
            return res;
        }
        Trie T;
        
        //put all words into Trie
        for (auto &word : words){
            T.insert(word);
        }
        
        int mlen = board.size();
        int nlen = board[0].size();
        vector<vector<bool>> visit(mlen, vector<bool>(nlen, false));
        for(int i=0; i<mlen; i++)
            for(int j=0; j<nlen; j++)
                if(T.root->child[board[i][j]-'a'])
                    DFS(T.root->child[board[i][j]-'a'], i, j, board, visit, res);
        return res;
    }
    
    void DFS(TrieNode* cur, int row, int col, vector<vector<char>>& board, vector<vector<bool>>& visit, vector<string>& res){
        if(!cur->str.empty()){
            res.push_back(cur->str);
            cur->str.clear();
        }
        visit[row][col] = true;
        
        
        if(col-1>=0 && row>=0 && col-1<board[0].size() && row<board.size() && cur->child[board[row][col-1]-'a'] && !visit[row][col-1])
            DFS(cur->child[board[row][col-1]-'a'], row, col-1, board, visit, res);
        if(col>=0 && row-1>=0 && col<board[0].size() && row-1<board.size() && cur->child[board[row-1][col]-'a'] && !visit[row-1][col])
            DFS(cur->child[board[row-1][col]-'a'], row-1, col, board, visit, res);
        if(col+1>= 0 && row>=0 && col+1<board[0].size() && row<board.size() && cur->child[board[row][col+1]-'a'] && !visit[row][col+1]) 
            DFS(cur->child[board[row][col+1]-'a'], row, col+1, board, visit, res);
        if(col>=0 && row+1>=0 && col<board[0].size() && row+1<board.size() && cur->child[board[row+1][col]-'a'] && !visit[row+1][col])
            DFS(cur->child[board[row+1][col]-'a'], row+1, col, board, visit, res);
        visit[row][col] = false;
    }
};
