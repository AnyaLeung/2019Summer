class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0){
            return 0;
        }
        if((dividend==INT_MIN && divisor==-1)
          ||(dividend==INT_MAX && divisor==1)){
            return INT_MAX;
        }
        if((dividend==INT_MIN && divisor==1)
           ||(dividend==INT_MAX && divisor==-1)){
            return INT_MIN;
        }
        bool isNeg = false;
        isNeg = (dividend^divisor) < 0;
        long a = (abs)((long)dividend);
        long b = (abs)((long)divisor);
        int res = 0;
        for(int i=31; i>=0; i--){
            if((a>>i)>=b){
                res += 1 << i;
                a -= b << i;
            }
        }
        return isNeg ? -res : res;
    }
};
