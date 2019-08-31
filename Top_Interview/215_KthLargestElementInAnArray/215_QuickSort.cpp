class Solution {
public:
    int Partition(vector<int>& nums, int begin, int end){
        int key = nums[end];
        int last = end;
        while(begin<end){
            while(begin<end && nums[begin]>=key){
                begin ++;
            }
            while(begin<end && nums[end]<=key){
                end --;
            }
            swap(nums[begin], nums[end]);
        }
        //把pivot放到重合的begin(end)处
        //此时左侧是比它大的，右侧是比它小的
        //begin是第几位，它就是第k大的
        swap(nums[begin], nums[last]);
        return begin;
    }
    
    int quick_sort(vector<int>& nums, int left, int right, int k){
        if(left>right){
            return -1;
        }
        int div = Partition(nums, left, right);
        if(div==k-1){
            return nums[div];
        }
        else if(div<k-1){
            return quick_sort(nums, div+1, right, k);
        }
        else if(div>=k-1){
            return quick_sort(nums, left, div-1, k);
        }
        return -1;
    }
    
    int findKthLargest(vector<int>& nums, int k){
        return quick_sort(nums, 0, nums.size()-1, k);
    }
};
