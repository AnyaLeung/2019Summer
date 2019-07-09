class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int len = nums.size();
        if(!len) return 0;
        vector<int> nocount(10001, 0);
        int maxno = INT_MIN;
        
        for(auto num : nums){
            nocount[num] ++;
            maxno = (num > maxno)? num : maxno;
        }
        
        int curr = nocount[1];
        int prev = 0;
        for(int i=2; i<=maxno; i++){
            int tmp = curr;
            curr = max(curr, nocount[i]*i+prev);
            prev = tmp;
        }
        
        return curr;
    }
};
