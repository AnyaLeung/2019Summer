class Solution {
public:
    //厄拉多塞筛法
    int countPrimes(int n) {
        if(n<3){
            return 0;
        }
        vector<bool> flag(n+1 ,true);
        
        int count = 0; //count prime
        
        for(int i=2; i<n; i++){
            if(flag[i]){ //this number is prime
                for(int j=i*2; j<n; j+=i){ //所有这个数的质数都不是质数
                    flag[j] = false;
                }
                count ++;
            }
        }
        return count;
    }
};
