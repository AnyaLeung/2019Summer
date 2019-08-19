class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        
        while(x){
            if(res>INT_MAX/10 || (res==INT_MAX/10 && x%10>7)){
                return 0;
            }
            else if(res<INT_MIN/10 || (res==INT_MIN/10 && x%10<-8)){
                return 0;
            }
            res *= 10;
            res += x % 10;
            x /= 10; 
        }
        
        return res;
    }
};
