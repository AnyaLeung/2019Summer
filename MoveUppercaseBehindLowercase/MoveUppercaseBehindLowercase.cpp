#include <iostream>

using namespace std;

string convert(string a){
    int p1 = a.size() - 1; //move
    int p2 = p1;

    while(p1>=0){
        //loop until p1 meet uppercase
        while(islower(a[p1]) && p2>=0){
            p1 --;
        }
        char tmp = a[p1]; //uppercase p1 meet

        //将[p1+1, p2]都顺位向前1位
        for(int i=p1+1; i<=p2; i++){
            a[i-1] = a[i];
        }
        
        a[p2] = tmp;
        p1 --;
        p2 --;
    }
    return a;
}

int main(void){
    string a = "AbCbcdc";
    cout << convert(a);

    return 0;
}
