class Solution {
public:
    int reverse(int x) {
        int res = 0;
        
        while(x){
            int remainder = x % 10;
            if(res>INT_MAX/10 || (res==INT_MAX/10 && remainder>7)){
                return 0;
            }
              if(res<INT_MIN/10 || (res==INT_MIN/10 && remainder<-8)){
                  return 0;
              } 
              res = res * 10 + remainder;
              x /= 10;
        }
        return res;
    }
};
