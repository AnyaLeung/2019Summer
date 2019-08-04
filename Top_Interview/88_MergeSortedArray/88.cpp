class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1 = m - 1;
        int len2 = n - 1;
        int len = m + n - 1;
        
        while(len1>=0 && len2>=0){
            nums1[len--] = (nums1[len1]>nums2[len2])? nums1[len1--] : nums2[len2--];
        }
        
        //put rest o' nums2 into nums1
        for(int i=0; i<=len2; i++){
            nums1[i] = nums2[i];
        }
    }
};
