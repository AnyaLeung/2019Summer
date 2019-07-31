class Solution {
public:
    int leftBound(vector<int> nums, int tar, int len){
        int left = 0;
        int right = len;
        
        while(left<right){
            int mid = left + (right-left) / 2;
            if(nums[mid]==tar){
                right = mid;
            }
            else if(nums[mid]<tar){
                left = mid + 1;
            }
            else if(nums[mid]>tar){
                right = mid;
            }
        }
         return (nums[left]==tar)? left : -1;
    }
    
    int rightBound(vector<int> nums, int tar, int len){
        int left = 0;
        int right = len;
        
        while(left<right){
            int mid = left + (right-left) / 2;
            if(nums[mid]==tar){
                left = mid + 1;
            }
            else if(nums[mid]<tar){
                left = mid + 1;
            }
            else if(nums[mid]>tar){
                right = mid;
            }
        }
         return (nums[left-1]==tar)? (left-1) : -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(nums.empty()){
            return res;
        }
        int len = nums.size();
        
        //find left boundary
        int left = 0;
        int right = len - 1;
        
        while(left<right){
            int mid = left + (right-left) / 2;
            if(nums[mid]==target){
                right = mid;
            }
            else if(nums[mid]<target){
                left = mid + 1;
            }
            else if(nums[mid]>target){
                right = mid;
            }
        }
        if(nums[left]!=target){
            return res;
        }
        res[0] = left;
        
        //find right boundary
        left = 0;
        right = len;
        while(left<right){
            int mid = left + (right-left) / 2;
            if(nums[mid]==target){
                left = mid + 1;
            }
            else if(nums[mid]>target){
                right = mid;
            }
            else if(nums[mid]<target){
                left = mid + 1;
            }
        }
        res[1] = left - 1;
        return res;
    }
};
