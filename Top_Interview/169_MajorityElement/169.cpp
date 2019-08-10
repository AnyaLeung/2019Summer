class Solution {
public:
    // Boyer–Moore majority vote algorithm
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len<3){
            return nums[0];
        }
        
        int target = nums[0];
        int count = 1;
        for(int i=1; i<len; i++){
            if(nums[i]!=target){
                count --;
                if(count==0){
                    target = nums[i];
                    count = 1;
                }
            }
            else if(nums[i]==target){
                count ++;
            }
        }
        return target;
    }
};
