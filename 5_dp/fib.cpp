#include <iostream>

using namespace std;

int arr[100] = {0};

int fib(int n){
    if(n==0 || n==1){
        return 1;
    }

    arr[0] = 1;
    arr[1] = 1;
    for(int i=2; i<n+1; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}

int main(void){
    cout << fib(5) << endl;
}
