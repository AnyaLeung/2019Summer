class FenwickTree{
private:
  vector<int> sums;

public:
  FenwickTree(int n): sums(n+1, 0){} //[1, n]

  void Update(int i, int val){ //add val
    while(i<sums.size()){
      sums[i] += val;
      i += i & (-i);
    }
  }
  int Query(int i){ //get sum o' index[0, i]
    int sum = 0;
    while(i>0){
      sum += sums[i];
      i -= i & (-i);
    }
    return sum;
  }
};

