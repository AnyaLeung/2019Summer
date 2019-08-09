class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            if(nums.empty()){
                return 0;
            }
            int res = INT_MIN;
            int imax = 1;
            int imin = 1;

            for(int i=0; i<nums.size(); i++){
                if(nums[i]<0){
                    int tmp = imax;
                    imax = imin;
                    imin = tmp;
                }
                imax = max(imax*nums[i], nums[i]);
                imin = min(imin*nums[i], nums[i]);
                res = max(res, imax);
            }
            return res;
        }
};
