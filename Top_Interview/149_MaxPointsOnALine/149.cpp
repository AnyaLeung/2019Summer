class Solution {
public:
    int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int len = points.size();
        int res = 0;
        if(len<3){
            return len;
        }
        
        for(int i=0; i<len; i++){
            int samecount = 1;
            map<pair<int, int>, int> mymap;
            for(int j=0; j<i; j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                if(!dx && !dy){
                    samecount ++;
                }
                else{
                    int g = gcd(dx, dy);
                    mymap[{dx/g, dy/g}] ++;
                }
            }
            res = max(res, samecount);
            
            for(auto lpair : mymap){
                res = max(res, lpair.second+samecount);
            }
        }
        return res;
    }
};
