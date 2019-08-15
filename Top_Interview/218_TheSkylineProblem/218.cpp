class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        
        for(vector<int> &e : buildings){
            all.insert({e[0], -e[2]}); //left node
            all.insert({e[1], e[2]});  //right node
        }
        
        multiset<int> prioqueue({0});
        vector<int> last(2, 0);
        for(auto lp : all){
            if(lp.second<0){ //is left node
                prioqueue.insert(-lp.second);
            }
            else if(lp.second>=0){
                prioqueue.erase(prioqueue.find(lp.second));
            }
            
            auto maxval = *prioqueue.rbegin();
            
            if(maxval!=last[1]){
                last[0] = lp.first;
                last[1] = maxval;
                res.push_back(last);
            }
        }
        return res;
    }
};
