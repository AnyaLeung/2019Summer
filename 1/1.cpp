class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> dict;
        
        for(int i=0; i<nums.size(); i++){
            int find = target - nums[i];
            if(dict.count(find)){ //map has key
                result.push_back(dict[find]);
                result.push_back(i);
                return result;
            }
            else{
                dict[nums[i]] = i;
                cout << "index:" << nums[i] << " value:" << dict[nums[i]] << endl;
            }
        }
    return result;
    }
};
