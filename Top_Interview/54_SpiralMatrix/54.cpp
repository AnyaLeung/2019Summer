class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty()){
            return res;
        }
        int up = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        
        while(1){
            for(int i=left; i<=right; i++){
                res.push_back(matrix[up][i]);
            }
            up ++;
            if(up>down){
                break;
            }
            
            for(int j=up; j<=down; j++){
                res.push_back(matrix[j][right]);
            }
            right --;
            if(right<left){
                break;
            }
            
            for(int m=right; m>=left; m--){
                res.push_back(matrix[down][m]);
            } 
            down --;
            if(down<up){
                break;
            }
            
            for(int n=down; n>=up; n--){
                res.push_back(matrix[n][left]);
            }
            left ++;
            if(left>right){
                break;
            }
        }
        return res;
    }
};
