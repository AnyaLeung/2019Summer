class FenwickTree{
private:
  vector<int> sums;
public:
  FenwickTree(int n): sums(n+1, 0){}
  void Update(int i, int val){
    while(i<sums.size()){
      sums[i] += val;
      i += i & (-i);
    }
  }
  int Query(int i){
    int sum = 0;
    while(i>0){
      sum += sums[i];
      i -= i & (-i);
    }
    return sum;
  }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      vector<int> res;
      //sort unique numbers
      set<int> sorted(nums.begin(), nums.end());
      //map to ranking
      unordered_map<int, int> ranking;
      int count = 0;
      for(auto num : sorted){
        ranking[num] = ++ count;
      }
      
      FenwickTree tree(ranking.size());
      for(int i=nums.size()-1; i>=0; i--){
        res.push_back(tree.Query(ranking[nums[i]]-1));
        tree.Update(ranking[nums[i]], 1);
      }
      reverse(res.begin(), res.end());
      return res;
    }
};
