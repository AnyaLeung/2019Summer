class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        
        if(len<3 || len==0){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<len; i++){
            if(nums[i]>0){
                continue;
            }
            int left = i + 1;
            int right = len - 1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(!sum){
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left ++;
                    right --;
                }
                else if(sum<0){
                    left ++;
                }
                else if(sum>0){
                    right --;
                }
            }
        }
        return res;
    }
};
