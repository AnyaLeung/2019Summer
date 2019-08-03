class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row_zero;
        set<int> col_zero;
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]==0){
                    row_zero.insert(i);
                    col_zero.insert(j);
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(row_zero.count(i) || col_zero.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
