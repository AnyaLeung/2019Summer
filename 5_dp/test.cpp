#include <iostream>

using namespace std;

bool isPalindrome(string s){
    int i = 0;
    while(i<=s.size()/2){
        if(s[i]!=s[s.size()-1-i]){
            return false;
        }
        i++;
    }
    return true;
}

int main(void){
    cout << "abcba" << isPalindrome("abcba") << endl;
    cout << "abcbd" << isPalindrome("abcbd") << endl;
    cout << "abccba" << isPalindrome("abccba") << endl;
    cout << "abdcba" << isPalindrome("abdcba") << endl;

    return 0;
}
