class Solution {
public:
    int maxArea(vector<int>& height) {
        if(!height.size()){
            return 0;
        }
        int lo = 0;
        int hi = height.size()-1;
        int res = (hi-lo) * min(height[lo], height[hi]);
        
        while(lo<=hi){
            int hei = min(height[lo], height[hi]);
            res = max(res, hei * (hi-lo));
            if(height[lo]<height[hi]){
                lo ++;
            }
            else{
                hi --;
            }
        }
        return res;
    }
};
