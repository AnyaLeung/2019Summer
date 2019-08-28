class Solution {
public:
    int getSum(int a, int b) {
        if(b==0){
            return a;
        }
        unsigned long c = a;
        unsigned long d = b;
        while(d){
            unsigned long carry = (c&d) << 1;
            c = c ^ d;
            d = carry;
        }
        return (int)c;
    }
};
