#include <iostream>

using namespace std;

int Cal(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return Cal(n-1) + Cal(n-2);
}

int main(void){
    cout << Cal(20);
    
    return 0;
}
