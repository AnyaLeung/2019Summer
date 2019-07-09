class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int len = A.size();
        vector<int> keep(len, INT_MAX);
        vector<int> swap = keep;
        
        if(!len){
            return 0;
        }
        
        keep[0] = 0;
        swap[0] = 1;
        for(int i=1; i<len; i++){
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                keep[i] = keep[i-1];
                swap[i] = swap[i-1] + 1;
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                keep[i] = min(keep[i], swap[i-1]);
                swap[i] = min(swap[i], keep[i-1]+1);
            }
        }
        
        return min(keep[len-1], swap[len-1]);
    }
};
