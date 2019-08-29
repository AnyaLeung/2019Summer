class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mymap;
        
        for(int i=0; i<nums.size(); i++){
            if(mymap.count(target-nums[i])==0){
                mymap[nums[i]] = i;
            }
            else{
                return vector<int>{mymap[target-nums[i]], i};
            }
        }
        return vector<int>{0, 0};
    }
};
