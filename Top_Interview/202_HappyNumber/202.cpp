class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> used;
        int sum = 0;
        
        while(n!=1){
            used.insert(n);
            int tmp = 0;
            while(n){
                tmp += (n%10) * (n%10);
                n /= 10;
            }
            n = tmp;
            if(used.count(n)){
                return false;
            }
        }
        return true;
    }
};
