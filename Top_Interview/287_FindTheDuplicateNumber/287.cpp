class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
            
            //find where fast and slow meet
            do{
                slow = nums[slow];
                fast = nums[nums[fast]];
            }while(slow!=fast);
            
            fast = 0;
            while(fast!=slow){
                slow = nums[slow];
                fast = nums[fast];
            }
        return fast;
    }
};
