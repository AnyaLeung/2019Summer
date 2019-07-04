class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int no = 0;
        for(auto n : nums){
            no += n;
            sum.push_back(no);
        }
    }
    
    int sumRange(int i, int j) {
        if(!i){
            return sum[j];
        }
        return sum[j] - sum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
