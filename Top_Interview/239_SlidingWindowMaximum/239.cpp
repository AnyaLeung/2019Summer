class Solution {
public:
    struct MonotonicQueue{
        deque<int> data;
        void push(int n){
            while(data.size() && data.back()<n){
                data.pop_back();
            }
            data.push_back(n);
        }
        
        int max(void){
            return data.front();
        }
        
        void pop(int n){
            if(data.size() && data.front()==n){
                data.pop_front();
            }
        }
    };
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue window;
        vector<int> res;
        
        for(int i=0; i<nums.size(); i++){
            if(i<k-1){ //window3, deal with [0], [1] < 2
                window.push(nums[i]);
            }
            else{
                window.push(nums[i]);
                res.push_back(window.max());
                window.pop(nums[i-k+1]);
            }
        }
        return res;
    }
};
