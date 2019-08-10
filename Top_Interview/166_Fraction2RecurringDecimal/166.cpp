class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(denominator==0){
            return res;
        }
        long long num = (long long)numerator;
        long long denom = (long long)denominator;
        
        //deal with Signal
        if((num<0 && denom>0) || (num>0 && denom<0)){
            res += "-";
        }
        num = abs(num);
        denom = abs(denom);
        
        //deal with Int
        res += to_string(num/denom);
        num %= denom;
        
        //deal with Decimal
        if(num){
            res += ".";
        }
        
        //用哈希表记录出现过的除数以定位循环
        unordered_map<long long, int> mymap;
        int index = 0;
        while(num && mymap.count(num)==0){
            mymap[num] = index ++;
            num *= 10;
            res += to_string(num/denom);
            num %= denom;
        }
        
        //如果出现循环小数
        if(mymap.count(num)){
            res += "()";
            int curr = res.size() - 2;
            while(index>mymap[num]){
                swap(res[curr], res[curr-1]);
                index --;
                curr --;
            }
        }
        
        return res;
    }
};
