class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> heap; //min heap
        sort(intervals.begin(), intervals.end());
        
        heap.push(intervals[0][1]);
        for(int i=1; i<intervals.size(); i++){
            int end = heap.top();
            if(intervals[i][0]>=end){
                heap.pop();
                heap.push(intervals[i][1]);
            }
            else if(intervals[i][0]<end){
                heap.push(intervals[i][1]);
            }
        }
        return heap.size();
    }
};
