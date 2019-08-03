class Solution {
    public boolean helper(int i, int j, int index, String word, boolean[][] visited, char[][] board){
        if(index==word.length()){
            return true;
        }
        if(i>=board.length || i<0 || j>=board[0].length || j<0
          || board[i][j]!=word.charAt(index) || visited[i][j]){
            return false;
        }
        visited[i][j] = true;
        if(helper(i+1, j, index+1, word, visited, board) 
          || helper(i-1, j, index+1, word, visited, board)
          || helper(i, j+1, index+1, word, visited, board) 
          || helper(i, j-1, index+1, word, visited, board)){
            return true;
        }
        visited[i][j] = false;
        return false;
    }
    
    public boolean exist(char[][] board, String word) {
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board[0].length; j++){
                if(word.charAt(0)==board[i][j]
                  && helper(i, j, 0, word, visited, board)){
                    return true;
                }
            }
        }
        return false;
    }
}
