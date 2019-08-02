class Solution {
public:
    int mySqrt(int x) {
        if(!x || x==1){
            return x;
        }
        int left = 0;
        int right = x;
        
        while(left<=right){
            int mid = left + (right-left) / 2;
            int s = x / mid;
            int ss = x / (mid + 1);
            if(x/s==s){
                return s;
            }
            else if(s>mid && ss<mid+1){
                return mid;
            }
            else if(s>mid){
                left = mid + 1;
            }
            else if(s<mid){
                right = mid - 1;
            }
        }
        return 0;
    }
};
