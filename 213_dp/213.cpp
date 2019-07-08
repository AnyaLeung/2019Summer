class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==0) return 0;
        else if(len==1) return nums[0];
        else if(len==2) return max(nums[0], nums[1]);
        
       
        //0--------->n-2
        int previous = nums[0];
        int current = max(nums[0], nums[1]);
        for(int i=2; i<len-1; i++){ 
            int tmp = current;
            current = max(nums[i]+previous, current);
            previous = tmp;
        }
        int res1 = current;
        
        //1 -------->n-1
        previous = nums[1];
        current = max(nums[1], nums[2]);
        for(int i=3; i<len; i++){
            int tmp = current;
            current = max(nums[i]+previous, current);
            previous = tmp;
        }
        
        return max(res1, current);
    }
};
