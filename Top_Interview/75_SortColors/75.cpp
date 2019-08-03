class Solution {
public:
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int i = 0;
        
        while(i<=right){
            if(nums[i]==0){
                swap(nums, i, left);
                left ++;
                i ++;
            }
            else if(nums[i]==2){
                swap(nums, i, right--);
            }
            else if(nums[i]==1){
                i ++;
            }
        }
    }
};
