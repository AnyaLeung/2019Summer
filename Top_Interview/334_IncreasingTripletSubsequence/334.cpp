class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX; //smallest
        int b = INT_MAX; //second smallest
        
        for(auto num : nums){
            if(num<=a){
                a = num;
            }
            else if(num>a && num<=b){
                b = num;
            }
            else if(num>b){
                return true;
            }
        }
        return false;
    }
};
