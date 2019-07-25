class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //sort array
        
        int len = nums.size();
        if(nums.size()==0|| len<3){
            return res;
        }
        for(int i=0; i<len; i++){
            if(nums[i]>0){
                continue;
            }
            if(i && nums[i]==nums[i-1]){
                continue;
            }
            int L = i + 1;
            int R = len - 1;
            while(L<R){
                int sum = nums[L] + nums[i] + nums[R];
                if(sum==0){
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[L]);
                    tmp.push_back(nums[R]);
                    res.push_back(tmp);
                    while(L+1<len && nums[L]==nums[L+1]){
                        L ++;
                    }
                    
                    while(R-1>=0 && nums[R]==nums[R-1]){
                        R --;
                    }
                    L ++;
                    R --;
                }
                else if(sum<0){
                    L++;
                }
                else if(sum>0){
                    R--;
                }
            }
        }
        return res;
    }
};
