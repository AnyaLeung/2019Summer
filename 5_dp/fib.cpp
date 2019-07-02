#include <iostream>

using namespace std;

int arr[100] = {0};

int fib(int n){
    int result = 0;

    if(arr[n]!=0){
        return arr[n];
    }

    if(n==0 || n==1){
        result = 1;
    }
    else{
        result = fib(n-1) + fib(n-2);
    }
    arr[n] = result;

    return result;
}

int main(void){
    cout << fib(5) << endl;
}
