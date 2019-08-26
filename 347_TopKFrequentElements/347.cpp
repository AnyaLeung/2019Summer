class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mym;
        //map num with frequency
        for(auto num : nums){
            mym[num] ++;
        }
        
        priority_queue<pair<int, int>> pq;
        //put into priority queue
        for(auto lp : mym){
            pq.push({lp.second, lp.first});
        }
        
        //save top k from pq into res
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
