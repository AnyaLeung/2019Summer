class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.empty()){
            return res;
        }
        sort(intervals.begin(), intervals.end());
        int len = intervals.size();
        
        int i = 0;
        while(i<len){
            int left = intervals[i][0];
            int right = intervals[i][1];
            while(i<len-1 && intervals[i+1][0]<=right){
                right = max(right, intervals[i+1][1]);
                i ++;
            }
            vector<int> tmp {left, right};
            res.push_back(tmp);
            i ++;
        }
        
        return res;
    }
};
