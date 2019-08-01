class Solution {
public:
    double fastPow(double x, int N){
        if(N==0){
            return 1;
        }
        double half = fastPow(x, N/2);
        
        if(N%2==0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
    
    double myPow(double x, int n) {
        long long N = n;
        
        if(n<0){
            x = 1 / x;
            N = abs(N);
        }
        
        return fastPow(x, N);
    }
};
