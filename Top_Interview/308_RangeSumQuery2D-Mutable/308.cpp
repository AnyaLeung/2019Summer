class NumMatrix {
private:
    vector<vector<int>> sum;
    vector<vector<int>>& raw;
public:
    void add(int val, int x, int y){
        while(y<sum[x].size()){
            sum[x][y] += val;
            y += y & (-y);
        }
    }
    
    int getSum(int x, int y){
        int res = 0;
        while(y>=1){
            res += sum[x][y];
            y -= y & (-y);
        }
        return res;
    }
    
    NumMatrix(vector<vector<int>>& matrix):raw(matrix) {
        if(matrix.empty()){
            return ;
        }
        int mlen = matrix.size();
        int nlen = matrix[0].size();
        sum.resize(mlen, vector<int>(nlen+1, 0));
        for(int i=0; i<mlen; i++){
            for(int j=0; j<nlen; j++){
                add(matrix[i][j], i, j+1);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int addi = val - raw[row][col];
        raw[row][col] = val;
        add(addi, row, col+1);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0; 
        for(int i=row1; i<=row2; i++){
            res += getSum(i, col2+1) - getSum(i, col1);
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
