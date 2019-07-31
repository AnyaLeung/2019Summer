class Solution {
public:
    void swap(vector<int>& nums, int index1, int index2){
        nums[index1] = nums[index1] ^ nums[index2];
        nums[index2] = nums[index1] ^ nums[index2];
        nums[index1] = nums[index1] ^ nums[index2];
    }
    
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        
        for(int i=0; i<len; ){
            int t = nums[i];
            if(i+1!=t && t>0 && t<=len && nums[i]!=nums[nums[i]-1]){
                swap(nums, i, nums[i]-1); 
                //swap i to where it should be
            }
            else{
                i ++;
            }
        }
        
        for(int i=0; i<len; i++){
            if(i+1!=nums[i]){
                return i + 1;
            }
        }
        return len + 1;
    }
};
