class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        priority_queue<pair<int, int>> mypq;
        vector<int> res;
        
        for(auto num : nums){
            mymap[num] ++;
        }
        for(auto lp : mymap){
            mypq.push({lp.second, lp.first});a
        }
        for(int i=0; i<k; i++){
            res.push_back(mypq.top().second);
            mypq.pop();
        }
        return res;
    }
};
