class Solution {
public:
    void checkStatus(vector<vector<int>>& board, int i, int j){
        int count = 0;
        //left and right in border
        int left = max(j-1, 0);
        int right = min(j+1, (int)board[0].size()-1);
        int top = max(i-1, 0);
        int bottom = min(i+1, (int)board.size()-1);
        
        for(int x=top; x<=bottom; x++){
            for(int y=left; y<=right; y++){
                if(board[x][y]==1 || board[x][y]==-1){
                    count ++;
                }
            }
        }
        if(board[i][j]==1){
            if(count==3 || count==4){
                board[i][j] = 1;
            }
            else{
                board[i][j] = -1;
            }
        }
        else if(board[i][j]==0){
            if(count==3){
                board[i][j] = -2;
            }
            else{
                board[i][j] = 0;
            }
        }
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                checkStatus(board, i, j);
            }
        }
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==-1 || board[i][j]==0){
                    board[i][j] = 0;
                }
                else{
                    board[i][j] = 1;
                }
            }
        }
    }
};
