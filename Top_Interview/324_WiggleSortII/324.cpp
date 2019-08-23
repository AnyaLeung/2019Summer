class Solution {
public:
    void wiggleSort(vector<int>& nums) {
      int len = nums.size();
      nth_element(nums.begin(), nums.begin()+len/2, nums.end());
      int mid = nums[len/2];
      
      int left = 0;
      int i = 0;
      int right = len - 1;
      #define a(i) nums[(2*(i)+1)%(len|1)]
        
        
        while(i<=right){
            if(a(i)>mid){
                swap(a(left), a(i));
                left ++;
                i ++;
            }
            else if(a(i)<mid){
                swap(a(i), a(right));
                right --;
            }
            else if(a(i)==mid){
                i ++;
            }
        }
    }
};
