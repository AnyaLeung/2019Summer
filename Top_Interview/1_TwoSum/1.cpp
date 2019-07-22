class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ma;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            int rem = target - nums[i];
            if(ma.count(rem)){
                res.push_back(ma[rem]);
                res.push_back(i);
                return res;
            }
            else{
                ma[nums[i]] = i;
            }
        }
        return res;
    }
};
