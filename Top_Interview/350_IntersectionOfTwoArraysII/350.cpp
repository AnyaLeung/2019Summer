class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        vector<int> res;
        
        for(auto num : nums1){
            mymap[num] ++;
        }
        for(auto num : nums2){
            if(mymap.count(num)){
                res.push_back(num);
                mymap[num] --;
                if(mymap[num]==0){
                    mymap.erase(num);
                }
            }
        }
        return res;
    }
};
