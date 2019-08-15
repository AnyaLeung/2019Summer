class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> dict;
        for(auto num : nums){
            if(dict.count(num)){
                return true;
            }
            else{
                dict.insert(num);
            }
        }
        return false;
    }
};
