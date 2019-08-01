class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        for(int i=0; i<len; i++){
            for(int j=0; j<len/2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][len-1-j];
                matrix[i][len-1-j] = tmp;
            }
        }
    }
};
