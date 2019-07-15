#include <iostream>

using namespace std;

void Merge(vector<int> a, vector<int>assist, int lo, int mid, int hi){
    assist = a; //copy
    
    for(int k=lo; k<=hi; k++){
        if(assist[j]>assist[i]) a[k] = assist[i++];
        else if(assist[j]<assist[i]) a[k] = assist[j++];
        else if(i>mid) a[k] = assist[j++]; //当一边已经merge结束了，处理另一边
        else if(j>high) a[k] = assist[i++];
    }
}

void Sort(vector<int> a, vector<int> assist, int lo, int hi){
    if(hi<=lo) return ;
    int mid = lo + (hi-lo) / 2;
    Sort(a, assist, lo, mid);
    Sort(a, assist, mid, high);
    Merge(a, assist, lo, mid, hi);
}

int main(void){
    vector<int> a, vector<int> assist;
    Sort(a, assist, 0, a.size()-1);
}
