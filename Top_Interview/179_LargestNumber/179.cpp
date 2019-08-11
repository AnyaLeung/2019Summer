class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs;
        bool all_zero = true;
        for(auto num : nums){
            if(num){
                all_zero = false;
            }
            vs.push_back(to_string(num));
        }
        if(all_zero){
            return "0";
        }
        sort(vs.begin(), vs.end(), [](string a, string b){
            return a + b > b + a;
        });
        string res;
        for(auto s : vs){
            res += s;
        }
        return res;
    }
