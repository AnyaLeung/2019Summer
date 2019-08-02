class Solution {
public:
    int climb(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        return climb(n-1) + climb(n-2);
    }
    int climbStairs(int n) {
        return climb(n);
    }
};
