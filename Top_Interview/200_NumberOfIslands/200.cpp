class Solution {
public:
    //dfs
    void setNum(vector<vector<char>>& grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        if(row<0 || col<0 || row>=m || col>=n
          || grid[row][col]!='1' || grid[row][col]=='2'){
            return ;
        }
        grid[row][col] = 2;
        setNum(grid, row+1, col);
        setNum(grid, row-1, col);
        setNum(grid, row, col+1);
        setNum(grid, row, col-1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int mlen = grid.size();
        int nlen = grid[0].size();
        if(mlen==0 || nlen==0){
            return 0;
        }
        
        int sum = 0;
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                if(grid[i][j]=='1'){ //is land
                    sum ++;
                    setNum(grid, i, j);
                }
            }
        }
        return sum;
    }
};
