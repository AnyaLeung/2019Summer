class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> swap(len, INT_MAX);
        vector<int> keep = swap;
        
        if(!len) return 0;
        swap[0] = 1;
        keep[0] = 0;
        
        for(int i=1; i<len; i++){
            if(A[i]>A[i-1] && B[i]>B[i-1]){ //ordered
                swap[i] = swap[i-1] + 1;
                keep[i] = keep[i-1];
            }
            
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                swap[i] = min(swap[i], keep[i-1] + 1);
                keep[i] = min(keep[i], swap[i-1]);
            }
        }
        
        return min(swap[len-1], keep[len-1]);
    }
};
