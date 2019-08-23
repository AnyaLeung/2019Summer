class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        if(n==1){
            return true;
        }
        
        double N = n;
        
        while(N>3){
            N /= 3;
        }
        return N==3;
    }
};
