#include <iostream>

using namespace std;

int arr[100] = {0};

int fib(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}

int main(void){
    cout << fib(5);
    return 0;
}
