class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        if(height.empty()){
            return sum;
        }
        
        //最两边的col一定没有水
        for(int i=1; i<height.size()-1; i++){
            int left_max = 0;
            for(int j=i-1; j>=0; j--){
                left_max = max(left_max, height[j]);
            }
            
            int right_max = 0;
            for(int j=i+1; j<height.size(); j++){
                right_max = max(right_max, height[j]);
            }
            
            int curr_height = min(left_max, right_max);
            //只有较小col>当前height才有水，其他情况无
            if(curr_height>height[i]){
                sum += curr_height - height[i];
            }
        }
        return sum;
    }
};
