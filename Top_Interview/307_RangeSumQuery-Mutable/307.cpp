class NumArray {
private:
    vector<int> bit;
    vector<int>& raw;
public:
    NumArray(vector<int>& nums):raw(nums) {
        bit.resize(nums.size()+1, 0);
        for(int i=0; i<nums.size(); i++){
            add(i+1, nums[i]); //put nums[i] into index i+1 position
        }
    }
    
    void add(int index, int val){
        while(index<=raw.size()){
            bit[index] += val;
            index += index & (-index);
        }
    }
    
    int sum(int index){
        int res = 0;
        while(index>=1){
            res += bit[index];
            index -= index & (-index);
        }
        return res;
    }
    
    void update(int i, int val) {
        add(i+1, val-raw[i]);
        raw[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sum(j+1) - sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
